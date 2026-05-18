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
  bool was_key_pressed = false;
  input inp;

  float radius1 = 0;
  double starttime1 = 0;
  double endtime1 = 0;
  Vector2 temp_coord1;
  Vector2 perm_coord1;

  float radius2 = 0;
  double starttime2 = 0;
  double endtime2 = 0;
  Vector2 temp_coord2;
  Vector2 perm_coord2;

  SetTargetFPS(6);
  Color color;
  color = GOLD;
  while (!WindowShouldClose()) {
    BeginDrawing();

    // started1 = false;
    ClearBackground(BLACK);

    // if (!draw1.fixed) {
    temp_coord1 = inp.r_coord();
    // }
    // if (!draw2.fixed) {
    //  temp_coord2 = inp.r_coord();
    //}

    if (IsMouseButtonDown(0)) {
      started1 = true;
      was_key_pressed = true;
      if (!draw2.fixed) {
        radius2 += 1;
        perm_coord2 = temp_coord1;
        // radius2 = radius2;
        draw2.will_draw_circle(temp_coord1, radius2, VIOLET, true);
      }
      if (!draw1.fixed) {
        radius1 += 1;
        perm_coord1 = temp_coord1;
        //  perm_radius1 = temp_radius1;

        draw1.will_draw_circle(temp_coord1, radius1, color, true);
      }
      if (draw1.fixed) {
        draw1.will_draw_circle(perm_coord1, radius1, YELLOW, true);
      }
      if (draw2.fixed) {
        draw1.will_draw_circle(perm_coord2, radius2, GREEN, true);
      }
    }
    if (started1) {
      if (IsMouseButtonUp(0)) {

        // temp_radius1 = 0;
        if (was_key_pressed) {
          if (draw1.fixed) {
            draw2.fixed = true;
            // temp_radius2 = 0;
          }
          was_key_pressed = false;
        }
        draw2.will_draw_circle(perm_coord2, radius2, RED, true);
        draw1.fixed = true;
        draw1.will_draw_circle(perm_coord1, radius1, color, true);
      }
    }

    std::cout << "draw1" << draw1.fixed << "draw2" << draw2.fixed << std::endl;
    
    EndDrawing();
  }

  return 0;
}
