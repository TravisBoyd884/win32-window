#include "window.h"
#include <iostream>
#include <windows.h>

int main(int argc, char *argv[]) {
  std::cout << "Hello from hybrid app!" << std::endl;
  Window w(800u, 600u);

  while (w.getRunning()) {
  }

  return 0;
}
