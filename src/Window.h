//
// Created by 12132 on 2022/3/20.
//

#ifndef WINDOW_H_
#define WINDOW_H_
#include "Windows.h"
#include "utility.h"
class Button;
class Mouse;

namespace Win32Platform {

struct WindowData {
	const char * title = "Default";
	int x = 200, y = 200;
	int	width = 1280, height = 720;
	bool showWindow = true;
};

typedef bool WindowProcessButton(const Button& button);
typedef bool WindowProcessMouse(const Mouse& mouse);

class Window {
public:
	Window();
	Window(const WindowData& data);

	void Run();
	WindowProcessMouse mouse_process;
	WindowProcessButton button_process;
private:
	bool running;
	HWND windowHandle;
	HDC hdc;
	WindowData data;
};
}

#endif // WINDOW_H_
