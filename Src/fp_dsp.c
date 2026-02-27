
#include<fp_dsp.h>
#include<fp_math.h>
#include<string.h>


void FIR_init(FIR_fp *filter, q15_t *coefficients, uint16_t length){

	filter->filter_length = length;

	memcpy(filter->coefficients,coefficients, length * sizeof(q15_t));

	memset(filter->samples, 0, sizeof(filter->samples));

	filter->wrt_index = 0;

}

q15_t FIR_process(FIR_fp *filter, q15_t sample){
	filter->samples[filter->wrt_index] = sample;
	filter->wrt_index++ ;
	if(filter->wrt_index >= filter->filter_length){
		filter->wrt_index = 0;
	}
	q31_t accum = 0;
	for(int i=0; i<filter->filter_length ; i++){
		accum += fp_mul(filter->coefficients[i], filter->samples[(filter->wrt_index - i - 1 + filter->filter_length ) % filter->filter_length]);
	}
	if(accum>Q15_MAX){
		accum = Q15_MAX;
	}
	else if(accum<Q15_MIN){
		accum = Q15_MIN;
	}
	return accum;
}
