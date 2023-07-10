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
