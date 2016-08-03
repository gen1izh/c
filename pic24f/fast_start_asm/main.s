#include "P24FJ128GA010.inc"
.data
value1:  .word  0x0800
.text
.global __reset
__reset:
	mov	#0x1234, W0
	mov	#value1, W1
	mov	W0, [W1]
met:
	goto met
.end