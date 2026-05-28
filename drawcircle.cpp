#include "include/drawcircle.h"
#include <cmath>
#include <iostream>
#include <raylib.h>
void my_DrawCircle::will_draw_circle(Vector2 coord, float radius, Color color,
                                     bool sim_on, bool fixed) {
  if (!sim_on)
    DrawCircleV(coord, radius, color);
};
void my_DrawCircle::fvec(Vector2 startPos, Vector2 endPos, Color color) {
  DrawLineV(startPos, endPos, color);
}
void my_DrawCircle::stats(gravity *mass, int x_pad, int y_pad, int fsize,
                          Font font, Color tint, float spacing) {
  int pad = x_pad;

  float mag = sqrt(pow(mass->accle.x, 2) + pow(mass->accle.y, 2));
  Vector2 endPos = mass->posit;
  if (mag > 0) {
    endPos.x += (mass->accle.x / mag) * mass->radius;
    endPos.y += (mass->accle.y / mag) * mass->radius;
  }
  fvec(mass->posit, endPos, WHITE);

  std::string num_s = std::to_string(mass->num) + " num";
  const char *num = num_s.c_str();

  std::string intix_s = std::to_string(mass->inti_u.x) + " px/s";
  const char *intix = intix_s.c_str();

  std::string intiy_s = std::to_string(mass->inti_u.y) + " px/s";
  const char *intiy = intiy_s.c_str();

  std::string acclex_s = std::to_string(mass->accle.x) + " px/s*s";
  const char *acclex = acclex_s.c_str();

  std::string accley_s = std::to_string(mass->accle.y) + " px/s*s";
  const char *accley = accley_s.c_str();

  std::string posx_s = std::to_string(mass->posit.x) + " px";
  const char *posx = posx_s.c_str();

  std::string posy_s = std::to_string(mass->posit.y) + " px";
  const char *posy = posy_s.c_str();

  DrawTextEx(font, num,
             {mass->posit.x - mass->radius / 8.0f,
              mass->posit.y - mass->radius / 7.0f},
             mass->radius / 3.0f, spacing, tint);
  DrawTextEx(font, num,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);
  x_pad += MeasureText(num, fsize) + pad;

  DrawTextEx(font, intix,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(intix, fsize) + pad;

  DrawTextEx(font, intiy,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(intiy, fsize) + pad;

  DrawTextEx(font, acclex,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(acclex, fsize) + pad;
  DrawTextEx(font, accley,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(accley, fsize) + pad;
  DrawTextEx(font, posx,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(posx, fsize) + pad;
  DrawTextEx(font, posy,
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);
}
