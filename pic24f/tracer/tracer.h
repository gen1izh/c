#ifdef _TRACER_H_
#define _TRACER_H_

#define _tracer_fn_enter_(fname) \
			printf("Enter into [%s] function... ", fname)

#define _tracer_debug_(fname, str, value) \
			printf("[%s] function. %s = %d(hex=0x%08X)  ", fname, str, value, value)			
	
#define _tracer_warning_(fname, str) \
			printf("Warning in [%s] function. Info = %s ", fname, str)
			
#define _tracer_notice_(fname, str) \
			printf("Notice in [%s] function. Info = %s ", fname, str)			

#define _tracer_error_(fname, str, value) \
			printf("ERROR in [%s] function! %s = %d(hex=0x%08X)  ", fname, str, value)
#endif