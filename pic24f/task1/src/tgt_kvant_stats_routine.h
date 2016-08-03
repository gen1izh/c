/*
 * tgt_kvant_stats_routine.h
 *
 *  Created on: 06.05.2012
 *      Author: ZalogiX
 */

#ifndef TGT_KVANT_STATS_ROUTINE_H_
#define TGT_KVANT_STATS_ROUTINE_H_

/*
 * Calculate int mean
 */
int KVANT_average_int_value(
  int *X, /* input data array */
  int  N  /* data array length */
);

/*
 * Calculate double mean
 */
double KVANT_average_double_value(
  double *X, /* input data array */
  int     N  /* data array length */
);

/*
 * Calculate int RMS(root mean square)
 *
 */
int KVANT_RMS_int_value(
  int    *X, /* input data array */
  int     N  /* data array length */
);

/*
 * Calculate double RMS(root mean square)
 *
 */
double KVANT_RMS_double_value(
  double *X, /* input data array */
  int     N  /* data array length */
);

/*
 * Calculate double RMS(root mean square)
 * with floating statistics
 */
double KVANT_RMS_floating_statistics_value(
  double *X,/* input data array */
  int     N,/* data array length */
  double *m /* mean value */
);

/*
 * Calculate amplitude of the swing
 */
double KVANT_Vpp(
  double  RMS,       /* RMS value */
  int     signal_type/* signal type (noise, sin, ...) */
);

double KVANT_stats_noise(
  double  RMS,/* RMS value */
  int     N   /* data array length */
);

/*
 * Calculate variation koefficient
 */
double KVANT_vari_koeff(
  double RMS,/* RMS value */
  double mean/* mean average value */
);

/*
 * Calculate RMS with histogram.
 * For big data arrays.
 */
double KVANT_histogram_RMS(
  double *X,/* input data array */
  int     N,/* data array length */
  double *m /* mean value */
);


#endif /* TGT_KVANT_STATS_ROUTINE_H_ */
