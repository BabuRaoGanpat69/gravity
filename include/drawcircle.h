
#include <raylib.h>
class my_DrawCircle {
public:
  bool fixed = false;
  inline void will_draw_circle(Vector2 coord, float radius, Color color,
                               bool sim_on, bool fixed);
};