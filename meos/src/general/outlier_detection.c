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


// For each individual trajectory, 
//filter out the trajectory points that are considered noise 
//or outliers

//TODO: add a filter based on the acceleration

TSequence filter_trajectory_heuristic(TSequence t, int max_speed, int include_loops, int speed, int max_loop, float max_ratio){
    /*
        tdf : TrajDataFrame
        the trajectories of the individuals.

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

   // sort by uid and datatime 
    

   //if utils.is_multi_user(tdf):
        //groupby.append(constants.UID)
    //if utils.is_multi_trajectory(tdf):
        //groupby.append(constants.TID)

    return t;
}



TSequenceSet filter_trajectory_heuristic_set(TSequenceSet t, int max_speed, int include_loops, int speed, int max_loop, float max_ratio){
    //call filter_trajectory_heuristic for each trajectory in the set
    
}


TSequence Kalman_filter_CV(TSequence t,float process_noise_std, int measurement_noise_std){

}


TSequenceSet Kalman_filter_CV_set(TSequenceSet t,float process_noise_std, int measurement_noise_std){
    //call Kalman_filter_CV for each trajectory in the set
}