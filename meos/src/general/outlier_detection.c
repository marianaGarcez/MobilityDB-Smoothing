/*****************************************************************************
 *
 * This MobilityDB code is provided under The PostgreSQL License.
 * Copyright (c) 2016-2022, Université libre de Bruxelles and MobilityDB
 * contributors
 *
 * MobilityDB includes portions of PostGIS version 3 source code released
 * under the GNU General Public License (GPLv2 or later).
 * Copyright (c) 2001-2022, PostGIS contributors
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without a written
 * agreement is hereby granted, provided that the above copyright notice and
 * this paragraph and the following two paragraphs appear in all copies.
 *
 * IN NO EVENT SHALL UNIVERSITE LIBRE DE BRUXELLES BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING
 * LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
 * EVEN IF UNIVERSITE LIBRE DE BRUXELLES HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * UNIVERSITE LIBRE DE BRUXELLES SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON
 * AN "AS IS" BASIS, AND UNIVERSITE LIBRE DE BRUXELLES HAS NO OBLIGATIONS TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS. 
 *
 *****************************************************************************/

/**
 * @brief Outlier detection functions.
 */

#include "general/periodset.h"

/* C */
#include <assert.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>
/* PostgreSQL */
#include <postgres.h>
#include <utils/timestamp.h>
/* MobilityDB */
#include <meos.h>
#include <meos_internal.h>
#include "general/pg_call.h"
#include "general/span.h"
#include "general/temporal_util.h"
#include "general/time_ops.h"
#include "general/temporal_parser.h"

double getDistance(double loc1, double loc2){
    //"Haversine formula - give coordinates as (lat_decimal,lon_decimal) tuples"
    double earthradius = 6371.0;
    double lat1 = loc1, lon1 = loc1;
    double lat2 = loc2, lon2 = loc2;
    
    //convert to radians
    lon1 = lon1 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    //haversine formula
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a,c,km;

    a = (sin(dlat/2))**2 + cos(lat1) * cos(lat2) * (sin(dlon/2.0))**2;
    c = 2.0 * atan2(sqrt(a), sqrt(1.0-a));
    km = earthradius * c;
    return km;
}

double diff_seconds(TInstant t0, TInstant t1){
    Datum t_0= t0.value;
    Datum t_1= t1.value;
    //TODO set seconds
    return (t_1 - t_0)*60;
}

double frand() {
    return 2*((rand()/(double)RAND_MAX) - 0.5);
}

// For each individual trajectory, 
//filter out the trajectory points that are considered noise 
//or outliers

//TODO: add a filter based on the acceleration

TSequence filter_trajectory_heuristic(TSequence t, int max_speed, int include_loops, int speed, int max_loop, float max_ratio){
    /*
        Inputs:
        one trajectory at a time
        max_speed: float, optional
        delete a trajectory point if the speed (in km/h) from the previous point is higher than `max_speed_kmh`. The default is `500.0`.

        include_loops: boolean, optional
            If `True`, trajectory points belonging to short and fast "loops" are removed. 
            Specifically, points are removed if within the next `max_loop` points the individual 
            has come back to a distance (`ratio_max` * the maximum distance reached), AND the average speed (in km/h) is higher than `speed`.
            The default is `False`.
    
        speed : float, optional 
            the default is 5km/h (walking speed).

        max_loop : int, optional
            the default is `6`.

        ratio_max : float, optional
            the default is `0.25`.

        return clean trajectory
    */

    /*
    Delete points from raw trajectory `data` if:

    1. The speed from previous point is > `max_speed` km/h

    2. Within the next `max_loop` points the user has come back
            of `ratio_max`% of the maximum distance reached, AND s/he travelled
            at a speed > `speed` km/h
    */
    //tamanho da trajetoria
    int i=0;
    int32 lx;
    double dt;

    //Size of a trajectory - how many instants in a sequence
    lx = t.count;

    //TInstant tint= t.period;
    printf("size of trajectory %d instants",lx);
    printf("Structure Tsequence temptype %d, subtype %d, flags %d, count %d, maxcount %d, bbxsize %d, period %s\n ",t.temptype,t.subtype, t.flags,t.count, t.maxcount, t.bbxsize, t.period);

    //printf("Structure Tinstant header %d,temptype %d, subtype %d, flags %d, \n", )
    //while (i < lx - 2) {
        //dt = diff_seconds(t.);
        //if distfunc(t[i][:2], t[i + 1][:2]) / dt * 3600. > max_speed{
                //delete point (TInstant from TSequence)
                
            //lx = t.count;
        
        //}

    //}


    return t;
}



TSequenceSet filter_trajectory_heuristic_set(TSequenceSet t, int max_speed, int include_loops, int speed, int max_loop, float max_ratio){
    //call filter_trajectory_heuristic for each trajectory in the set
    
}


TSequence Kalman_filter_CV(TSequence t,float process_noise_std, int measurement_noise_std){

    //initial values for the kalman filter
    float x_est_last = 0;
    float P_last = 0;
    //the noise in the system
    float Q = 0.022;
    float R = 0.617;
    
    float K;
    float P;
    float P_temp;
    float x_temp_est;
    float x_est;
    float z_measured; //the 'noisy' value we measured
    float z_real = 0.5; //the ideal value we wish to measure
    
    srand(0);
    
    //initialize with a measurement
    x_est_last = z_real + frand()*0.09;
    
    float sum_error_kalman = 0;
    float sum_error_measure = 0;
    
    for (int i=0;i<30;i++) {
        //do a prediction
        x_temp_est = x_est_last;
        P_temp = P_last + Q;
        //calculate the Kalman gain
        K = P_temp * (1.0/(P_temp + R));
        //measure
        z_measured = z_real + frand()*0.09; //the real measurement plus noise
        //correct
        x_est = x_temp_est + K * (z_measured - x_temp_est); 
        P = (1- K) * P_temp;
        //we have our new system
        
        printf("Ideal    position: %6.3f \n",z_real);
        printf("Mesaured position: %6.3f [diff:%.3f]\n",z_measured,fabs(z_real-z_measured));
        printf("Kalman   position: %6.3f [diff:%.3f]\n",x_est,fabs(z_real - x_est));
        
        sum_error_kalman += fabs(z_real - x_est);
        sum_error_measure += fabs(z_real-z_measured);
        
        //update our last's
        P_last = P;
        x_est_last = x_est;
    }
    
    printf("Total error if using raw measured:  %f\n",sum_error_measure);
    printf("Total error if using kalman filter: %f\n",sum_error_kalman);
    printf("Reduction in error: %d%% \n",100-(int)((sum_error_kalman/sum_error_measure)*100));
    
    
    return 0;
}


TSequenceSet Kalman_filter_CV_set(TSequenceSet t,float process_noise_std, int measurement_noise_std){
    //call Kalman_filter_CV for each trajectory in the set
}