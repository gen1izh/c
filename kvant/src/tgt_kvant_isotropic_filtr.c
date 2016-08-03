/*
 * tgt_kvant_isotropic_filtr.c
 *
 *  Created on: 13.05.2012
 *      Author: ZalogiX
 */

#include "../include/tgt_kvant_isotropic_filtr.h"

/*
 * Isotropic filter. Non recursive moving average filter.
 */
void KVANT_Non_recursive_moving_average_filter(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *Y, /* output data array */
  int          M /* number of samples averaged */ )
{
  int i;
  int j;

  /* Clear output data*/
  for ( i = (M / 2); i < N - (M / 2); i++) {
    Y[0] = 0;
  /* calculation of the samples */
    for( j = -(M / 2); j < (M / 2); j++ ) {
      Y[i] = Y[i] + X[i+j];
    }
    Y[i] = Y[i] / (M+1);
  }
}


/*
 * Isotropic filter. Recursive moving average filter.
 */
void KVANT_Recursive_moving_average_filter(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *Y, /* output data array */
  int          M /* number of samples averaged */ )
{
  int i;
  double ACC;

  ACC = 0;
  for( i = 0; i < M+1; i++ ) {
    ACC+=X[i];
  }

  Y[M/2] = ACC / (M + 1);

  for ( i = (M / 2) + 1; i < N - (M / 2); i++ ) {
    ACC += X[i+(M / 2)] - X[i-(M / 2)-1];
    Y[i] = ACC / (M + 1);
  }

}
