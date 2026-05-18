#include "drawcircle.cpp"
#include "input.cpp"
#include <iostream>
#include <raylib.h>
int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GRAVITY");

  my_DrawCircle draw1; // obj
  my_DrawCircle draw2; // idk why there are 2
  draw1.fixed = false; // status of firstcircle1
  draw2.fixed = false; // status of firstcircle2
  bool started =false; // checks if we have presed the mouse button even onec as without
             // iskeyup is  true in the starting before even pressing the button
  bool was_key_pressed =
      false; // was keypressed need to chng the state of circles(fixed or not)
  Vector2 temp_coord; // gets coord from mouse
  input inp;

  float radius1 = 0;   // self
  Vector2 perm_coord1; // stores permamnet coord of 1

  float radius2 = 0;   // self
  Vector2 perm_coord2; // stores permamnet coord of 2

  SetTargetFPS(60);
  Color color;
  color = GOLD;
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    temp_coord = inp.r_coord();

    if (IsMouseButtonDown(0)) {
      started = true;
      was_key_pressed = true;

      if (!draw1.fixed) {
        radius1 += 1;
        perm_coord1 = temp_coord;
        draw1.will_draw_circle(temp_coord, radius1, color, true);

      } else if (!draw2.fixed) { // else if because then both radius will
                                 // increase at same time in starting even if
                                 // radius1 should increase in starting only
        radius2 += 1;
        perm_coord2 = temp_coord;
        std::cout << "riyiyvb" << std::endl;
        draw2.will_draw_circle(temp_coord, radius2, color, true);
      }

      if (draw1.fixed) {
        draw1.will_draw_circle(perm_coord1, radius1, color, true);
      }
      if (draw2.fixed) {
        draw1.will_draw_circle(perm_coord2, radius2, color, true);
      }
    }

    if (started) {
      if (IsMouseButtonUp(0)) {

        if (was_key_pressed) {
          if (draw1.fixed) {
            draw2.fixed = true;
          }
          was_key_pressed = false;
        }
        draw2.will_draw_circle(perm_coord2, radius2, color, true);
        draw1.fixed = true; // it is after draw2 becuase then draw2 will be
                            // turned ture in the starting when the draw1
                            // chnages true to stop that it is after;
        draw1.will_draw_circle(perm_coord1, radius1, color, true);
      }
    }
    EndDrawing();
  }

  return 0;
}
