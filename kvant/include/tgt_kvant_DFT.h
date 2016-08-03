/*
 * tgt_kvant_DFT.h
 *
 *  Created on: 07.12.2012
 *      Author: ZalogiX
 */

#ifndef TGT_KVANT_DFT_H_
#define TGT_KVANT_DFT_H_

/*
 * Inverse discrete Fourier transform
 */
void KVANT_inverse_DFT(
  double      *X,   /* output data array */
  int          N,   /* data array length */
  double      *Rex, /* real part of the representation of the signal */
  double      *Imx  /* imaginary part of the signal representation */
);


/*
 *  Discrete Fourier transform
 */
void KVANT_DFT(
  double      *X,   /* output data array */
  int          N,   /* data array length */
  double      *Rex, /* real part of the representation of the signal */
  double      *Imx  /* imaginary part of the signal representation */
);


#endif /* TGT_KVANT_DFT_H_ */
