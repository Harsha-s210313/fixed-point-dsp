/*
 * fp_math.c
 *
 *  Created on: 26-02-2026
 *      Author: HARSHA
 */

#include <fp_math.h>
q15_t fp_add(q15_t x, q15_t y){
	int32_t resultant = x+y;
	if(resultant > Q15_MAX){
		return Q15_MAX;
	}
	else if(resultant < Q15_MIN){
		return Q15_MIN;
	}
	else{
		return resultant;
	}
}

q15_t fp_sub(q15_t x, q15_t y){
	int32_t resultant = x-y;
		if(resultant > Q15_MAX){
			return Q15_MAX;
		}
		else if(resultant < Q15_MIN){
			return Q15_MIN;
		}
		else{
			return resultant;
		}
}
q15_t fp_mul(q15_t x, q15_t y){
	int32_t resultant = (int32_t)x*y;
	resultant>>=15;
	if(resultant > Q15_MAX){
		return Q15_MAX;
	}
	else if(resultant < Q15_MIN){
		return Q15_MIN;
	}
	else{
		return resultant;
	}
}

q15_t fp_div(q15_t x, q15_t y){
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
	int32_t temp = (int32_t)x <<15;
	int32_t resultant = temp/ y;

	if(resultant>Q15_MAX){
		return Q15_MAX;
	}
	else if(resultant<Q15_MIN){
		return Q15_MIN;
	}
	else{
		return resultant;
	}
}
