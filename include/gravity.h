#pragma once
#include <cmath>
#include <iostream>
#include <raylib.h>
class gravity {
public:
  const double G = 6.674 * pow(10, -11);
  double ep = 10e+6;
  float M = 10e+9;

  float radius;
  float mass;
  bool fixed = false;
  int num = 0;
  Vector2 inti_u;
  Vector2 accle;
  Vector2 posit;
  Vector2 vec2;
  Vector2 inline acc(Vector2 p1, Vector2 p2, float m);
  Vector2 inline position(Vector2 a, Vector2 u, float t, Vector2 prev_coord);

  inline gravity();
};