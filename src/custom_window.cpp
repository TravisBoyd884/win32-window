#include "custom_window.h"
#include <cstdint>
#include <libloaderapi.h>
#include <stdexcept>
#include <windows.h>

namespace custom_window {
CustomWindow::CustomWindow(std::uint32_t width, std::uint32_t height) {

  wc_ = {};

  wc_.lpfnWndProc = DefWindowProcA;
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
                            NULL           // Additional application data
  );
  ShowWindow(window_, SW_SHOW);
  UpdateWindow(window_);
}

} // namespace custom_window
