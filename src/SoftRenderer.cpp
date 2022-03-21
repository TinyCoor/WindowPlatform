//
// Created by 12132 on 2022/3/20.
//

#include "SoftRenderer.h"
#include "math.hpp"


void SoftRenderer::ClearScreen(RenderTarget &target, u32 color) {
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

void SoftRenderer::DrawRect(vec2f p, vec2f halfSize, RenderTarget& target, u32 color)
{
	f32 aspect_mul = (f32)target.height;

	if ((float)(target.width / (float)target.height) < 1.77f) {
		aspect_mul = target.width * 1.77f;
	}

	f32 scale = 0.001f;
	halfSize.x *= aspect_mul * scale;
	halfSize.y *= aspect_mul * scale;

	p.x *= aspect_mul * scale;
	p.y *= aspect_mul * scale;

	p.x += (f32)target.width * 0.5f;
	p.y += (f32)target.height * 0.5f;

	i32 x0 = static_cast<i32>(p.x - halfSize.x);
	i32 y0 = static_cast<i32>(p.y - halfSize.y);
	i32 x1 = static_cast<i32>(p.x + halfSize.x);
	i32	y1 = static_cast<i32>( p.y + halfSize.y);
	DrawRect(x0, y0, x1, y1, target, color);
}
