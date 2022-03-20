//
// Created by 12132 on 2022/3/20.
//

#ifndef MATH_HPP_
#define MATH_HPP_
#include "utility.h"

u32 clamp(u32 val,u32 min, u32 max);


#ifdef MATH_IMPLEMENT

u32 clamp(u32 val,u32 min, u32 max)
{
	if (val  < min) return min;
	if (val > max) return max;
	return val;
}
#endif
#endif //MATH_HPP_
