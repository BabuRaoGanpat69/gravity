#include "drawcircle.cpp"
#include "input.cpp"
#include <iostream>
#include <raylib.h>
#include <vector>
int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GRAVITY");

  my_DrawCircle draw1;
  my_DrawCircle draw2;
  draw1.fixed = false;
  draw2.fixed = false;
  bool started1 = false;
  bool started2 = false;
  input inp;

  float perm_radius1 = 0;
  float temp_radius1 = 0;
  double starttime1 = 0;
  double endtime1 = 0;
  Vector2 temp_coord1;
  Vector2 perm_coord1;

  float perm_radius2 = 0;
  float temp_radius2 = 0;
  double starttime2 = 0;
  double endtime2 = 0;
  Vector2 temp_coord2;
  Vector2 perm_coord2;

  SetTargetFPS(60);
  Color color;
  color = GOLD;
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    if (!draw1.fixed)
      temp_coord1 = inp.r_coord();
    if (!draw2.fixed)
      temp_coord2 = inp.r_coord();

    temp_coord2 = inp.r_coord();

    if (IsMouseButtonDown(0)) {
      started1 = true;
      if (draw1.fixed) {
        temp_radius2 += 1;
        perm_coord2 = temp_coord2;
        perm_radius2 = temp_radius2;
        draw1.will_draw_circle(temp_coord2, temp_radius2, color, true);
      }
      if (!draw1.fixed) {
        temp_radius1 += 1;
        perm_coord1 = temp_coord1;
        perm_radius1 = temp_radius1;
        draw1.will_draw_circle(temp_coord1, temp_radius1, color, true);
      }
      if (started2) {
        draw1.will_draw_circle(perm_coord1, perm_radius1, color, true);
      }
    }
    if (started1) {
      if (IsMouseButtonUp(0) || started1) {
        draw1.fixed = true;
        temp_radius1 = 0;
        draw1.will_draw_circle(perm_coord1, perm_radius1, color, true);

        if (draw1.fixed) {
          draw2.fixed = true;
          temp_radius2 = 0;
          draw1.will_draw_circle(perm_coord2, perm_radius2, color, true);
        }
      }
    }

    // std::cout << "draw1" << draw1.fixed << "draw2" << draw2.fixed <<
    // std::endl;
    EndDrawing();
  }

  return 0;
}

draw1.will_draw_circle(
    gr.position(gr.acc(current_coord1, current_coord2, 10000), gr.inti_u,
                (1 / 60), current_coord1.x, current_coord1.y),
    radius1, color, true);
