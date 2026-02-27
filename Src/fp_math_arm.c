/*
 * fp_math_arm.c
 *
 *  Created on: 26-02-2026
 *      Author: HARSHA
 */

#include<fp_math.h>

q15_t fp_add_arm(q15_t x, q15_t y){
	int32_t result;
	__asm volatile(
			"ADD %0, %1, %2\n\t"
			"SSAT %0, #16, %0"
			: "=r"(result)
			: "r"(x),"r"(y)
			  );
	return (q15_t)result;
}
q15_t fp_sub_arm(q15_t x, q15_t y){
	int32_t result;
	__asm volatile(
			"SUB %0, %1, %2\n\t"
			"SSAT %0, #16, %0"
			: "=r"(result)
			: "r"(x), "r"(y)
			  );
	return (q15_t)result;
}
q15_t fp_mul_arm(q15_t x, q15_t y){
	int32_t result;
	__asm volatile(
			"MUL %0, %1, %2\n\t"
			"ASR %0, #15\n\t"
			"SSAT %0, #16, %0"
			: "=r"(result)
			: "r"(x), "r"(y) );
	return (q15_t)result;
}
q15_t fp_div_arm(q15_t x, q15_t y){
	if(y == 0){
		if(x>0){
			return Q15_MAX;
		}
		else if(x==0){
			return 0;
		}
		else{
			return Q15_MIN;
		}
	}
	int32_t result;
	int32_t temp;
	__asm volatile(
			"LSL %1, %2, #15\n\t"
			"SDIV %0, %1, %3\n\t"
			"SSAT %0, #16, %0"
			: "=r"(result), "=r"(temp)
			: "r"(x),"r"(y) );
	return (q15_t) result;
}
