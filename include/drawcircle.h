
#include "./gravity.h"
#include <cmath>
#include <raylib.h>
class my_DrawCircle {
public:
  bool fixed = false;
  inline void will_draw_circle(Vector2 coord, float radius, Color color,
                               bool sim_on, bool fixed);
  inline void stats(gravity *mass, int x_pad, int y_pad, int fsize, Font font,
                    Color tint, float spacing);
  inline void fvec(Vector2 startPos, Vector2 endPos, Color color);
};