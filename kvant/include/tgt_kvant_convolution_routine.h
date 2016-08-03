/*
 * tgt_kvant_convolution_routine.h
 *
 *  Created on: 06.05.2012
 *      Author: ZalogiX
 */

#ifndef TGT_KVANT_CONVOLUTION_ROUTINE_H_
#define TGT_KVANT_CONVOLUTION_ROUTINE_H_

/*
 * Convolution, represented by the input side.
 */
void KVANT_inside_convolution(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *H, /* impulse response data */
  int          M, /* impulse response data length */
  double      *Y  /* output data array */
);

/*
 * Convolution, represented by the output side.
 */
void KVANT_outside_convolution(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *H, /* impulse response data */
  int          M, /* impulse response data length */
  double      *Y  /* output data array */
);

#endif /* TGT_KVANT_CONVOLUTION_ROUTINE_H_ */
