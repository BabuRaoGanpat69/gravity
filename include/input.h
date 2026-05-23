#pragma once
#include <chrono>
#include <iostream>
#include <raylib.h>
using namespace std::chrono_literals;
class input {
public:
  inline static Vector2 coordinates;
  inline static Vector2 r_coord();
  inline static double time_pressed();
};