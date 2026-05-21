
#include <cmath>
#include <iostream>
#include <raylib.h>
class gravity {
public:
  const double G = 6.674 * pow(10, -11);
  const double ep = 10e+6;
  Vector2 inti_u;
  float mass;
  Vector2 accle;
  Vector2 posit;
  Vector2 vec2;
  Vector2 inline acc(Vector2 p1, Vector2 p2, float m);
  Vector2 inline position(Vector2 a, Vector2 u, float t, float prev_x,
                          float prev_y);
};