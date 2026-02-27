/*
 * fp_dsp.h
 *
 *  Created on: 26-Feb-2026
 *      Author: HARSHA
 */

#ifndef FP_DSP_H_
#define FP_DSP_H_
#include<fixed_point.h>

#define FIR_MAX_TAPS			64

typedef struct{
	q15_t samples[FIR_MAX_TAPS];
	q15_t coefficients[FIR_MAX_TAPS];
	uint16_t wrt_index;
	uint16_t filter_length;
}FIR_fp;


void FIR_init(FIR_fp *filter, q15_t *coefficients, uint16_t length);
q15_t FIR_process(FIR_fp *filter, q15_t sample);

#endif /* FP_DSP_H_ */
