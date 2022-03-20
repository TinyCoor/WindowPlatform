//
// Created by 12132 on 2022/3/20.
//

#include "Window.h"
#include <cstdint>
static LRESULT CALLBACK MainProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	LRESULT result =0;
	switch (msg) {
		case WM_ACTIVATE:
			ShowCursor(false);
			break;

		case WM_SIZE:
			break;
		case WM_CLOSE:
		case WM_QUIT:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default: {
			return DefWindowProcA(hwnd, msg, wParam, lParam);
		}
	}
	return result;
}

Win32Platform::Window::Window()
	: Window(WindowData())
{

}

Win32Platform::Window::Window(const Win32Platform::WindowData &data)
	: data(data), initialized(true)
{
	WNDCLASSEXA windowClass ={0};
	HINSTANCE instance = GetModuleHandleA(NULL);
	windowClass.cbSize = sizeof(windowClass);
	windowClass.style = NULL;
	windowClass.lpfnWndProc = MainProc;
	windowClass.cbClsExtra = NULL ;
	windowClass.hInstance = instance;
	windowClass.hIcon  = LoadIconA(instance, IDI_APPLICATION);
	windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
	windowClass.hbrBackground = CreateSolidBrush(RGB(255,0,255));
	windowClass.lpszClassName = "DefaultWindow";
	windowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	if (RegisterClassExA(&windowClass) == 0) {
		MessageBoxA(NULL, "WindowClass Register failed","Error!", MB_ICONEXCLAMATION | MB_OK);
		initialized = false;
	}

	uint32_t window_x = data.x;
	uint32_t window_y = data.y;
	uint32_t window_width = data.width;
	uint32_t window_height = data.height;

	uint32_t window_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
	uint32_t window_ex_style = WS_EX_APPWINDOW;
	window_style |= WS_MAXIMIZEBOX;
	window_style |= WS_MINIMIZEBOX;
	window_style |= WS_THICKFRAME;

	windowHandle = CreateWindowExA(window_ex_style, windowClass.lpszClassName, data.title,
		window_style, window_x, window_y, window_width, window_height,
						 0, 0, instance, 0);
	if (windowHandle == NULL) {
		initialized = false;
	}
	ShowWindow((HWND)windowHandle,data.showWindow);
}
