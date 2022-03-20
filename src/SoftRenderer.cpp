//
// Created by 12132 on 2022/3/20.
//

#include "SoftRenderer.h"
#define MATH_IMPLEMENT
#include "math.hpp"

using namespace Win32Platform;

void SoftRenderer::ClearScreen(Win32Platform::RenderTarget &target, u32 color) {
	u32* pixel = target.pixels;
	for (u32 y = 0; y < target.width; ++y ) {
		for (u32 x = 0; x < target.height; ++x ) {
			*pixel++ = color;
		}
	}
}

void SoftRenderer::DrawRect(int x0, int y0, int x1, int y1, RenderTarget &target, u32 color) {
	x0 = clamp(target.width, 0, x0);
	x1 = clamp(target.width, 0, x1);
	y0 = clamp(target.height, 0, y0);
	y1 = clamp(target.height, 0, y1);

	for (u32 y = y0; y < y1; ++y) {
		u32* pixel = target.pixels + x0 + target.width * y ;
		for (u32 x = x0; x < x1; ++x ) {
			*pixel++ = color;
		}
	}
}
