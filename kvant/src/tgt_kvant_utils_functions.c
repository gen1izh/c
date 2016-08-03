/*
 * tgt_kvant_utils_functions.c
 *
 *  Created on: 09.12.2012
 *      Author: ZalogiX
 */


/*
 * Function transform to polar system the signal
 */
void tgt_kvant_to_polar(
    double      *Rex,   /* real part of the representation of the signal */
    double      *Imx,   /* imaginary part of the representation of the signal */
    double      *Mag,   /* magnitude part of the representation of the signal */
    double      *Phase, /* phase part of the representation of the signal */
    int          N,     /* data array length */)
{
  int k;
  double const_PI;
  const_PI  = 3.14159265358979323846;

  for ( k = 0; k < N; k++ ) {
    Mag[k] = sqrt( pow( Rex[k], 2 )+ pow( Imx[k], 2 ) );
    if ( Rex[k] == 0 ) Rex[k] = 0.00001;
    Phase[k] = atan( Imx[k] / Rex[k] );
    if (( Rex[k] < 0 ) && ( Imx[k] < 0 ))
      Phase[k] = Phase[k] - const_PI;
    if (( Rex[k] < 0 ) && ( Imx[k] >= 0 ))
      Phase[k] = Phase[k] + const_PI;
  }
}


/*
 * Function transform to rectangular system the signal
 */
void tgt_kvant_to_rectangular(
    double      *Rex,   /* real part of the representation of the signal */
    double      *Imx,   /* imaginary part of the representation of the signal */
    double      *Mag,   /* magnitude part of the representation of the signal */
    double      *Phase, /* phase part of the representation of the signal */
    int          N,     /* data array length */)
{
  int k;
  for ( k = 0; k < N; k++ ) {
    Rex[k] = Mag[k]*cos( Phase[k] );
    Imx[k] = Mag[k]*sin( Phase[k] );
  }
}
