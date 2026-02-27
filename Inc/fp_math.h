/*
 * fp_math.h
 *
 *  Created on: 26-Feb-2026
 *      Author: HARSHA
 */

#ifndef FP_MATH_H_
#define FP_MATH_H_

#include<fixed_point.h>
#define USE_ARM_OPTIMIZED


#ifdef USE_ARM_OPTIMIZED
//ARM OPTIMIZED
q15_t fp_add_arm(q15_t x, q15_t y);
q15_t fp_sub_arm(q15_t x, q15_t y);
q15_t fp_mul_arm(q15_t x, q15_t y);
q15_t fp_div_arm(q15_t x, q15_t y);

#else
//GENERIC FUNCTIONS
q15_t fp_add(q15_t x, q15_t y);
q15_t fp_sub(q15_t x, q15_t y);
q15_t fp_mul(q15_t x, q15_t y);
q15_t fp_div(q15_t x, q15_t y);
#endif

#endif /* FP_MATH_H_ */
