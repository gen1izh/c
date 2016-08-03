/*
 * tgt_kvant_utils_functions.h
 *
 *  Created on: 09.12.2012
 *      Author: ZalogiX
 */

#ifndef TGT_KVANT_UTILS_FUNCTIONS_H_
#define TGT_KVANT_UTILS_FUNCTIONS_H_

/*
 * Function transform to polar system the signal
 */
void tgt_kvant_to_polar(
    double      *Rex,   /* real part of the representation of the signal */
    double      *Imx,   /* imaginary part of the representation of the signal */
    double      *Mag,   /* magnitude part of the representation of the signal */
    double      *Phase, /* phase part of the representation of the signal */
    int          N,     /* data array length */
);


/*
 * Function transform to rectangular system the signal
 */
void tgt_kvant_to_rectangular(
    double      *Rex,   /* real part of the representation of the signal */
    double      *Imx,   /* imaginary part of the representation of the signal */
    double      *Mag,   /* magnitude part of the representation of the signal */
    double      *Phase, /* phase part of the representation of the signal */
    int          N,     /* data array length */
);

#endif /* TGT_KVANT_UTILS_FUNCTIONS_H_ */
