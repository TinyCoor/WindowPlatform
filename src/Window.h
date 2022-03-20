//
// Created by 12132 on 2022/3/20.
//

#ifndef WINDOW_H_
#define WINDOW_H_
#include "Windows.h"
namespace Win32Platform {
struct WindowData{
	const char * title = "Default";
	int x = 200, y = 200;
	int	width = 1280, height = 720;
	bool showWindow = true;
};

class Window {
public:
	Window();
	Window(const WindowData& data);

private:
	bool initialized ;
	HWND windowHandle;
	WindowData data;
};
}

#endif //WINDOWPLATFORM_SRC_WINDOW_H_
