/*
 * fixed_point.h
 *
 *  Created on: 26-Feb-2026
 *      Author: HARSHA
 */

#ifndef FIXED_POINT_H_
#define FIXED_POINT_H_

#include<stm32f411xe.h>
#include<stdint.h>

typedef int16_t q15_t;
typedef int32_t q31_t;

#define Q15_MIN				-32768
#define Q15_MAX				32767

#define Q15(x)				(q15_t)(x * 32768)


#endif /* FIXED_POINT_H_ */
