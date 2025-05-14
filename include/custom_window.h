#pragma once
#include <cstdint>
#include <windows.h>

namespace custom_window {
class CustomWindow {
public:
  CustomWindow(std::uint32_t width, std::uint32_t height);

  CustomWindow(const CustomWindow &) = delete;

  ~CustomWindow() = default;

  auto operator=(const CustomWindow &) -> CustomWindow & = delete;

  CustomWindow(CustomWindow &&) = default;
  auto operator=(CustomWindow &&) -> CustomWindow & = default;

private:
  HWND window_;
  WNDCLASSA wc_;
};
} // namespace custom_window
