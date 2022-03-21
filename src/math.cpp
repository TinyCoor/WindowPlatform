//
// Created by 12132 on 2022/3/21.
//
#include "math.hpp"

u32 clamp(u32 val,u32 min, u32 max)
{
	if (val  < min) return min;
	if (val > max) return max;
	return val;
}
