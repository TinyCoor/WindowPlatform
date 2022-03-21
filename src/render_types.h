//
// Created by 12132 on 2022/3/21.
//

#ifndef RENDER_TYPES_H_
#define RENDER_TYPES_H_
#include "utility.h"
#include <windows.h>

struct RenderTarget {
	int width, height;
	u32* pixels;
	/// Platform Specific
	BITMAPINFO bitmapInfo;
};
#endif //RENDER_TYPES_H_
