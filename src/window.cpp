#include "window.h"
#include <cstdint>
#include <iostream>
#include <libloaderapi.h>
#include <minwindef.h>
#include <print>
#include <stdexcept>
#include <windows.h>

void Window::setRunning(bool running) { m_running = running; }

LRESULT Window::HandleMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                              LPARAM lParam) {
  switch (uMsg) {

  case WM_ERASEBKGND: {
    HDC hdc = (HDC)wParam;
    RECT rect;
    GetClientRect(hwnd, &rect);

    // Create a solid brush with the desired color (e.g., blue)
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

    // Fill the background with the brush
    FillRect(hdc, &rect, hBrush);

    // Clean up the brush
    DeleteObject(hBrush);

    // Return 1 to indicate that the background has been erased
    return 1;
  }
  case WM_CLOSE: {
    std::cout << "key down" << std::endl;
    setRunning(false);
  }
  case WM_KEYDOWN: {
    std::cout << "key down" << std::endl;
  }

  default:
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
  Window *self = nullptr;
  if (uMsg == WM_NCCREATE) {
    CREATESTRUCT *cs = reinterpret_cast<CREATESTRUCT *>(lParam);
    self = reinterpret_cast<Window *>(cs->lpCreateParams);
    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
  } else {
    self = reinterpret_cast<Window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
  }

  if (self)
    return self->HandleMessage(hwnd, uMsg, wParam, lParam);

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window(std::uint32_t width, std::uint32_t height) {

  HWND window_;
  WNDCLASSA wc_;

  wc_ = {};

  wc_.lpfnWndProc = WindowProc;
  wc_.hInstance = GetModuleHandleA(nullptr);
  wc_.lpszClassName = "mainwindow";
  wc_.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

  if (RegisterClassA(&wc_) == 0) {
    throw std::runtime_error("Failed to register window class");
  }

  RECT rect{
      .left = {},
      .top = {},
      .right = static_cast<int>(width),
      .bottom = static_cast<int>(height),
  };

  if (AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false) == 0) {
    throw std::runtime_error("Could not resize window");
  }

  window_ = CreateWindowExA(0,                 // Optional window styles.
                            wc_.lpszClassName, // Window class
                            "Learn to Program Windows", // Window text
                            WS_OVERLAPPEDWINDOW,        // Window style

                            // Size and position
                            CW_USEDEFAULT, CW_USEDEFAULT,
                            rect.right - rect.left, rect.bottom - rect.top,

                            NULL,          // Parent window
                            NULL,          // Menu
                            wc_.hInstance, // Instance handle
                            this           // Additional application data
  );
  ShowWindow(window_, SW_SHOW);
  UpdateWindow(window_);
}

bool Window::getRunning() {
  MessagePump();
  return m_running;
}

void Window::MessagePump() {
  auto message = ::MSG{};
  while (::PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE) != 0) {
    ::TranslateMessage(&message);
    ::DispatchMessageA(&message);
    std::cout << ::TranslateMessage(&message) << std::endl;
  }
}
