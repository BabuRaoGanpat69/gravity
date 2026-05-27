#include "./gravity.h"
#include <cmath>
#include <raylib.h>
Vector2 gravity::acc(Vector2 p1, Vector2 p2, float m) {
  vec2.x = -(m * G /
             ((pow((sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2))), 3)) +
              ep)) *
           (p1.x - p2.x);
  vec2.y = -(m * G /
             ((pow((sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2))), 3)) +
              ep)) *
           (p1.y - p2.y);
  return vec2;
};
Vector2 gravity::position(Vector2 a, Vector2 u, float t, Vector2 prev_coord) {
  vec2.x = prev_coord.x + (u.x * t + 0.5 * a.x * t * t);
  vec2.y = prev_coord.y + (u.y * t + 0.5 * a.y * t * t);
  return vec2;
};
gravity::gravity() {
  this->mass = M;
  this->radius = 0;
  this->inti_u.x = 0;
  this->inti_u.y = 0;
  this->accle.x = 0;
  this->accle.y = 0;
}