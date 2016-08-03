/*
 * tgt_kvant_isotropic_filtr.h
 *
 *  Created on: 13.05.2012
 *      Author: ZalogiX
 */

#ifndef TGT_KVANT_ISOTROPIC_FILTR_H_
#define TGT_KVANT_ISOTROPIC_FILTR_H_

/*
 * Isotropic filter. Non recursive moving average filter.
 */
void KVANT_Non_recursive_moving_average_filter(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *Y, /* output data array */
  int          M /* number of samples averaged */
);

/*
 * Isotropic filter. Recursive moving average filter.
 */
void KVANT_Recursive_moving_average_filter(
  double      *X, /* input data array */
  int          N, /* data array length */
  double      *Y, /* output data array */
  int          M /* number of samples averaged */
);
#endif /* TGT_KVANT_ISOTROPIC_FILTR_H_ */
