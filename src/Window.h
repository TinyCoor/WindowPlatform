//
// Created by 12132 on 2022/3/20.
//

#ifndef WINDOW_H_
#define WINDOW_H_
#include "Windows.h"
#include "utility.h"
namespace Win32Platform {

struct RenderTarget {
	int width, height;
	u32* pixels;
	/// Platform Specific
	BITMAPINFO bitmapInfo;
};
struct WindowData {
	const char * title = "Default";
	int x = 200, y = 200;
	int	width = 1280, height = 720;
	bool showWindow = true;
};

class Window {
public:
	Window();
	Window(const WindowData& data);

	void Run();

private:
	bool running;
	HWND windowHandle;
	HDC hdc;
	WindowData data;
};
}

#endif // WINDOW_H_
