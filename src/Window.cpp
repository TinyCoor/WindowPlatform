//
// Created by 12132 on 2022/3/20.
//

#include "Window.h"
#include "utility.h"
#include "SoftRenderer.h"

using namespace Win32Platform;

global_variable RenderTarget renderTarget;

static LRESULT CALLBACK WndProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_ACTIVATE:
		case WM_SIZE: {
			// Get Width
			RECT rect;
			GetWindowRect(window, &rect);
			renderTarget.width = rect.right - rect.left;
			renderTarget.height = rect.bottom - rect.top;
			if (renderTarget.pixels) {
				VirtualFree(renderTarget.pixels, 0, MEM_RELEASE);
			}
			renderTarget.pixels =(u32*)VirtualAlloc(nullptr, sizeof(u32) * renderTarget.width * renderTarget.height,
		   		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
			renderTarget.bitmapInfo.bmiHeader.biSize = sizeof(renderTarget.bitmapInfo.bmiHeader);
			renderTarget.bitmapInfo.bmiHeader.biWidth = renderTarget.width;
			renderTarget.bitmapInfo.bmiHeader.biHeight = renderTarget.height;
			renderTarget.bitmapInfo.bmiHeader.biPlanes = 1u;
			renderTarget.bitmapInfo.bmiHeader.biBitCount = 32u;
			renderTarget.bitmapInfo.bmiHeader.biCompression = BI_RGB;
		}break;
		case WM_CLOSE:
		case WM_QUIT:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			break;
	}
	return DefWindowProcA(window, msg, wParam, lParam);
}

Win32Platform::Window::Window()
	: Window(WindowData())
{

}

Win32Platform::Window::Window(const Win32Platform::WindowData &data)
	: data(data), running(true)
{
	WNDCLASSEXA windowClass 	= {0};
	HINSTANCE instance 			= GetModuleHandleA(nullptr);
	windowClass.cbSize			= sizeof(windowClass);
	windowClass.style 			= 0l;
	windowClass.lpfnWndProc 	= WndProc;
	windowClass.cbClsExtra 		= 0l ;
	windowClass.hInstance 		= instance;
	windowClass.hIcon  			= LoadIconA(instance, IDI_APPLICATION);
	windowClass.hCursor 		= LoadCursorA(nullptr, IDC_ARROW);
	windowClass.hbrBackground 	= CreateSolidBrush(RGB(255,0,255));
	windowClass.lpszClassName 	= "DefaultWindow";
	windowClass.hIconSm 		= LoadIconA(nullptr, IDI_APPLICATION);
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

	if (RegisterClassExA(&windowClass) == 0) {
		running = false;
	}

	i32 windowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
	i32 windowExStyle = WS_EX_APPWINDOW;
	windowStyle |= WS_MAXIMIZEBOX;
	windowStyle |= WS_MINIMIZEBOX;
	windowStyle |= WS_THICKFRAME;

	windowHandle = CreateWindowExA(windowExStyle, windowClass.lpszClassName, data.title,
		windowStyle, data.x, data.y, data.width, data.height, nullptr, nullptr, instance, nullptr);
	if (windowHandle == nullptr) {
		running = false;
	}
	ShowWindow((HWND)windowHandle,data.showWindow);
	hdc = GetDC(windowHandle);
}


void Win32Platform::Window::Run() {
	/// TODO MOVE APPLICATION
	while (running) {
		MSG msg;
		while (PeekMessageA(&msg, windowHandle, 0, 0, PM_REMOVE)) {
			////
			switch (msg.message) {
				case WM_SYSKEYUP:
				case WM_SYSKEYDOWN:
				case WM_KEYDOWN:
				case WM_KEYUP:{
					u32 vk_code = (u32) msg.wParam;
					b32 wasDown = ((msg.lParam & (1 << 30)) != 0);
					b32 isDown = ((msg.lParam & (1 << 31)) == 0);
					if (vk_code==VK_ESCAPE){
						return ;
					}
				}break;
				default:{
					TranslateMessage(&msg);
					DispatchMessageA(&msg);
				}
			}
		}

		SoftRenderer::ClearScreen(renderTarget, 0xFF0000);
		SoftRenderer::DrawRect(50,50, 150,200, renderTarget, 0x0000FF);
		/// Move to SoftwareRender
		StretchDIBits(hdc,0, 0, renderTarget.width, renderTarget.height, 0, 0, data.width, data.height,
	  		renderTarget.pixels, &renderTarget.bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}
}
