//
// Created by 12132 on 2022/3/20.
//

#ifndef SOFT_RENDERER_H_
#define SOFT_RENDERER_H_
#include "utility.h"
#include "Window.h"
#include "math.hpp"
#include "render_types.h"

///To NDC coord



class SoftRenderer {
public:
	static void ClearScreen(RenderTarget& target, u32 color);
	static void DrawRect(vec2f p, vec2f halfSize,  RenderTarget& target, u32 color);
private:
	static void DrawRect(i32 x0, i32 y0, i32 x1, i32 y1, RenderTarget& target, u32 color);
	f32 aspectRation = 16.0 / 9.0;
};


#endif // SOFT_RENDERER_H_
