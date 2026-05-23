#include "include/drawcircle.h"
#include <iostream>
void my_DrawCircle::will_draw_circle(Vector2 coord, float radius, Color color,
                                     bool sim_on, bool fixed) {
  if (!sim_on)
    DrawCircleV(coord, radius, color);
};