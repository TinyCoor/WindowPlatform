//
// Created by 12132 on 2022/3/20.
//

#ifndef MATH_HPP_
#define MATH_HPP_
#include "utility.h"

template<typename T>
struct vec2 {
	union {
		struct { T x, y; };
		struct { T r, g; };
		struct { T u, v; };
		T e[2];
	};
};


template<typename T>
struct vec3 {
	union {
		struct { T x, y, z; };
		struct { T r, g, b; };
		T e[3];
	};

};


template<typename T>
struct vec4 {
	union {
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		T e[4];
	};
};

using vec2f = vec2<float>;
using vec3f = vec3<float>;

u32 clamp(u32 val,u32 min, u32 max);



#endif // MATH_HPP_
