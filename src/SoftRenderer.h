//
// Created by 12132 on 2022/3/20.
//

#ifndef SOFT_RENDERER_H_
#define SOFT_RENDERER_H_
#include "utility.h"
#include "Window.h"

namespace Win32Platform{
class SoftRenderer {
public:
	static void ClearScreen(RenderTarget& target, u32 color);
	static void DrawRect(int x0, int y0, int x1, int y1, RenderTarget& target, u32 color);
private:

};
}

#endif // SOFT_RENDERER_H_
