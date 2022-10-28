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
#include "general/periodset.h"

/* C */
#include <assert.h>
#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>
/* PostgreSQL */
#include <postgres.h>
#include <utils/timestamp.h>
/* PostGIS */
#include <liblwgeom_internal.h>
#include <lwgeodetic_tree.h>
/* MobilityDB */
#include <meos.h>
#include <meos_internal.h>
#include "general/pg_call.h"
#include "general/span.h"
#include "general/temporal_util.h"
#include "general/time_ops.h"
#include "general/temporal_parser.h"
#include "general/lifting.h"
#include "general/tsequence.h"
#include "point/geography_funcs.h"
#include "point/tpoint.h"
#include "point/tpoint_boxops.h"
#include "point/tpoint_spatialrels.h"
#include "point/tpoint_spatialfuncs.h"

double frand() {
    return 2*((rand()/(double)RAND_MAX) - 0.5);
}

Temporal* Kalman_filter_CV(const Temporal *t,float process_noise_std, int measurement_noise_std){

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
    
    
    return t;
}


Temporal * Kalman_filter_CV_set(const Temporal *t,float process_noise_std, int measurement_noise_std){
    //call Kalman_filter_CV for each trajectory in the set
    return t;
}


