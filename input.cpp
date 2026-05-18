#include "include/input.h"
#include <raylib.h>

Vector2 input::r_coord() {
  coordinates.x = GetMouseX();
  coordinates.y = GetMouseY();
  return coordinates;
}

double input::time_pressed() {
  const auto start = std::chrono::high_resolution_clock::now();
  while (IsKeyDown(KEY_W)) {
    if (!IsKeyDown(KEY_W)) {
      break;
    }
    std::cout << IsKeyUp(KEY_W) << std::endl;
  };
  const auto end = std::chrono::high_resolution_clock::now();
  const std::chrono::duration<double, std::milli> elapsed = end - start;
  std::cout << elapsed.count() << std::endl;
  return elapsed.count();
};