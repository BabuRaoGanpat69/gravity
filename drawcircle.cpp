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

  DrawTextEx(font, std::to_string(mass->num).c_str(), mass->posit,
             mass->radius / 3, spacing, tint);
  DrawTextEx(font, std::to_string(mass->num).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);
  x_pad += MeasureText(std::to_string(mass->num).c_str(), fsize) + pad;

  DrawTextEx(font, std::to_string(mass->inti_u.x).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(std::to_string(mass->inti_u.x).c_str(), fsize) + pad;

  DrawTextEx(font, std::to_string(mass->inti_u.y).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(std::to_string(mass->inti_u.y).c_str(), fsize) + pad;

  DrawTextEx(font, std::to_string(mass->accle.x).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(std::to_string(mass->accle.x).c_str(), fsize) + pad;
  DrawTextEx(font, std::to_string(mass->accle.y).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(std::to_string(mass->accle.y).c_str(), fsize) + pad;
  DrawTextEx(font, std::to_string(mass->posit.x).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);

  x_pad += MeasureText(std::to_string(mass->posit.x).c_str(), fsize) + pad;
  DrawTextEx(font, std::to_string(mass->posit.y).c_str(),
             {
                 (float)x_pad,
                 mass->num * (float)y_pad,
             },
             fsize, spacing, tint);
}
