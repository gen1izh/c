/*
 * tgt_kvant_DFT.c
 *
 *  Created on: 07.12.2012
 *      Author: ZalogiX
 */
#include <math.h>

/*
 * Inverse discrete Fourier transform
 */
void KVANT_inverse_DFT(
  double      *X,   /* output data array */
  int          N,   /* data array length */
  double      *Rex, /* real part of the representation of the signal */
  double      *Imx  /* imaginary part of the signal representation */
)
{
  double const_PI;
  int i, k;

  const_PI  = 3.14159265358979323846;

  for ( k = 0; k < (N/2); k++ ) {
    Rex[k] = Rex[k] / (N/2);
    Imx[k] = Imx[k] / (N/2);
  }

  Rex[0]     = Rex[0]   / 2;
  Rex[(N/2)] = Rex[(N/2)] / 2;

  for ( i = 0; i < N; i++ ) {
    X[i] = 0;
  }

  for ( k = 0; k < (N/2); k++ ) {
    for ( i = 0; i < N; i++ ) {
      X[i] = X[i] + Rex[k]*cos(2*const_PI*k*i/N);
      X[i] = X[i] + Imx[k]*sin(2*const_PI*k*i/N);
    }
  }
}



/*
 *  Discrete Fourier transform
 */
void KVANT_DFT(
  double      *X,   /* output data array */
  int          N,   /* data array length */
  double      *Rex, /* real part of the representation of the signal */
  double      *Imx  /* imaginary part of the signal representation */
)
{
  double const_PI;
  int i, k;

  const_PI  = 3.14159265358979323846;

  for ( k = 0; k < (N/2); k++ ) {
    Rex[k] = 0;
    Imx[k] = 0;
  }

  for ( k = 0; k < (N/2); k++ ) {
    for ( i = 0; i < N; i++ ) {
      Rex[k] = Rex[k] + X[i]*cos(2*const_PI*k*i/N);
      Imx[k] = Imx[k] - X[i]*sin(2*const_PI*k*i/N);
    }
  }
}
