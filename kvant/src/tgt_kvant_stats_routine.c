/*
 * tgt_kvant_stats_routine.c
 *
 *  Created on: 06.05.2012
 *      Author: ZalogiX
 */
#include "../include/tgt_kvant_stats_routine.h"
#include <math.h>
#include <string.h>

/*
 * Calculate int mean
 */
int KVANT_average_int_value(
  int *X, /* input data array */
  int  N  /* data array length */)
{
  int     mean;
  int     i;
  mean =  0;

  for( i = 0; i < N; i++ ) {
    mean += X[i];
  }
  mean = mean/N;
  return mean;
}

/*
 * Calculate double mean
 */
double KVANT_average_double_value(
  double *X, /* input data array */
  int     N  /* data array length */)
{
  double  mean;
  int     i;
  mean =  0;

  for( i = 0; i < N; i++ ) {
    mean += X[i];
  }
  mean = mean/N;
  return mean;
}

/*
 * Calculate int RMS(root mean square)
 *
 */
int KVANT_RMS_int_value(
  int    *X, /* input data array */
  int     N  /* data array length */)
{
  int   mean;
  int   i;
  int   variance;
  int   sd;

  variance  = 0;
  mean      = KVANT_average_int_value( X, N );
  for( i = 0; i < N ; i++ ) {
    variance = variance + pow( X[i]-mean , 2 );
  }
  variance  = variance / (N-1);
  sd        = sqrt(variance);
  return sd;
}

/*
 * Calculate double RMS(root mean square)
 *
 */
double KVANT_RMS_double_value(
  double *X, /* input data array */
  int     N  /* data array length */)
{
  double    mean;
  int       i;
  double    variance;
  double    sd;

  variance  = 0;
  mean      = KVANT_average_double_value( X, N );
  for( i = 0; i < N ; i++ ) {
    variance = variance + pow( X[i]-mean , 2 );
  }
  variance  = variance / (N-1);
  sd        = sqrt(variance);
  return sd;
}

/*
 * Calculate double RMS(root mean square)
 * with floating statistics
 */
double KVANT_RMS_floating_statistics_value(
  double *X,/* input data array */
  int     N,/* data array length */
  double *m /* mean value */)
{
  double  mean;
  double  sd;
  int     i;
  double  sum;
  double  sum_squares;
  int     count;
  mean    = 0 ;
  count   = 0;

  for ( i=0; i < N; i++ ) {
    count++;
    sum +=  X[i];
    sum_squares +=  pow(  X[i], 2 );
    mean = sum / count;
      if ( count == 1 ) sd = 0;
    sd = sqrt( sum_squares - pow( sum, 2 )/ count )/( count-1 );
  }
  return sd;
}

/*
 * Calculate amplitude of the swing
 */
double KVANT_Vpp(
  double  RMS,       /* RMS value */
  int     signal_type/* signal type (noise, sin, ...) */)
{
  switch(signal_type){
    case 0:
      return 2*RMS;
    case 1:
      return sqrt(12)*RMS;
    case 2:
      return 2*sqrt(2)*RMS;
    case 3:
      return 8*RMS;
    default:
      return RMS;
  }
  return 0;
}

double KVANT_stats_noise(
  double  RMS,/* RMS value */
  int     N   /* data array length */)
{
  return RMS / sqrt( N );
}
/*
 * Calculate variation koefficient
 */
double KVANT_vari_koeff(
  double RMS,/* RMS value */
  double mean/* mean average value */)
{
  return ( RMS / mean ) * 100;
}

/*
 * Calculate RMS with histogram.
 * For big data arrays.
 */
double KVANT_histogram_RMS(
  double *X,/* input data array */
  int     N,/* data array length */
  double *m /* mean value */)
{
  double  H[10000];
  int     i;
  double  mean;
  double  variance;
  double  sd;

  memset( H, 0, sizeof(H) );
  for ( i = 0; i < N; i++ ){
    H[((int)X[i])] = H[((int)X[i])] + 1;
  }
  mean = 0;
  for( i = 0; i < sizeof(H)+1; i++ ){
    mean += i*H[i];
  }
  mean    /= N;
  *m       = mean;
  variance = 0;
  for ( i = 0; i < sizeof(H)+1; i++ ){
    variance += H[i] * pow( i-mean, 2 );
  }
  variance = variance / (N-1);
  sd       = sqrt(variance);
  return sd;
}
