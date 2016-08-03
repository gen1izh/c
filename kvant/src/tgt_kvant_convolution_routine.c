/*
 * tgt_kvant_convolution_routine.c
 *
 *  Created on: 06.05.2012
 *  Author: ZalogiX
 */


#include "../include/tgt_kvant_convolution_routine.h"

/*
 * Convolution, represented by the input side.
 */
void KVANT_inside_convolution(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *H, /* impulse response data */
  int          M, /* impulse response data length */
  double      *Y  /* output data array */ )
{
  int i;
  int j;
  /* Clear output data*/
  for ( i = 0; i < N+M; i++) {
    Y[0] = 0;
  }
  /* calculation of the convolution */
  for ( i = 0; i < N; i++)
    for(j=0; j<M; j++)
      Y[i+j] = Y[i+j] + X[i*((int)H[j])];
}


/*
 * Convolution, represented by the output side.
 */
void KVANT_outside_convolution(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *H, /* impulse response data */
  int          M, /* impulse response data length */
  double      *Y  /* output data array */ )
{
  int i;
  int j;
  for ( i = 0; i < N+M; i++) {
    Y[0] = 0;
    for ( j=0; j < M; j++){
      if ((i-j) < 0) continue;
      if ((i-j) > N) continue;
      Y[i] = Y[i] + H[j]*X[i-j];
    }
  }
}






