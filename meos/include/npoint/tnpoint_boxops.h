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
 * @brief Bounding box operators for temporal network points.
 */

#ifndef __TNPOINT_BOXOPS_H__
#define __TNPOINT_BOXOPS_H__

/* PostgreSQL */
#include <postgres.h>
// #include <catalog/pg_type.h>
/* PostgreSQL */
#include "general/temporal.h"
#include "npoint/tnpoint.h"

/*****************************************************************************/

extern bool npoint_set_stbox(const Npoint *np, STBOX *box);
extern bool nsegment_set_stbox(const Nsegment *ns, STBOX *box);
extern bool npoint_timestamp_set_stbox(const Npoint *np, TimestampTz t,
  STBOX *box);
extern bool npoint_period_set_stbox(const Npoint *np, const Period *p,
  STBOX *box);

extern void tnpointinst_set_stbox(const TInstant *inst, STBOX *box);
extern void tnpointinstarr_set_stbox(const TInstant **inst, int count,
  STBOX *box);
extern void tnpointseq_set_stbox(const TInstant **inst, int count,
  interpType interp, STBOX *box);

/*****************************************************************************/

extern int boxop_tnpoint_geo(const Temporal *temp, const GSERIALIZED *geo,
  bool (*func)(const STBOX *, const STBOX *), bool invert);
extern int boxop_tnpoint_stbox(const Temporal *temp, const STBOX *box,
  bool (*func)(const STBOX *, const STBOX *), bool spatial, bool invert);
extern bool boxop_tnpoint_npoint(const Temporal *temp, const Npoint *np,
  bool (*func)(const STBOX *, const STBOX *), bool invert);
extern bool boxop_tnpoint_tnpoint(const Temporal *temp1, const Temporal *temp2,
  bool (*func)(const STBOX *, const STBOX *));

/*****************************************************************************/

#endif /* __TNPOINT_BOXOPS_H__ */
