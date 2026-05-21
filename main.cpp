#include "drawcircle.cpp"
#include "gravity.cpp"
#include "input.cpp"
#include <iostream>
#include <raylib.h>
int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GRAVITY");

  bool sim_on = false;

  gravity gr1;
  gravity gr2;

  gr1.mass = 10000000000000000;
  gr2.mass = 1;
  gr1.inti_u.x = 0;
  gr1.inti_u.y = 0;

  gr2.inti_u.x = 40;
  gr2.inti_u.y = 0;
  my_DrawCircle draw1; // obj
  my_DrawCircle draw2; // idk why there are 2
  draw1.fixed = false; // status of firstcircle1
  draw2.fixed = false; // status of firstcircle2
  bool started =
      false; // checks if we have presed the mouse button even onec as without
             // iskeyup is  true in the starting before even pressing the button
  bool was_key_pressed =
      false; // was keypressed need to chng the state of circles(fixed or not)
  Vector2 temp_coord; // gets coord from mouse
  input inp;

  float radius1 = 0;   // self
  Vector2 perm_coord1; // stores permamnet coord of 1
  Vector2 current_coord1;

  float radius2 = 0;   // self
  Vector2 perm_coord2; // stores permamnet coord of 2
  Vector2 current_coord2;
  int fps = 60;
  SetTargetFPS(fps);

  Color color;
  color = GOLD;

  // current_coord1 = perm_coord1;
  // current_coord2 = perm_coord2;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    temp_coord = inp.r_coord();

    if (!sim_on) {

      // std::cout << current_coord1.x << " " << current_coord1.y << std::endl;
    }

    if (IsMouseButtonDown(0)) {
      started = true;
      was_key_pressed = true;

      if (!draw1.fixed) {
        radius1 += 1;
        perm_coord1 = temp_coord;
        draw1.will_draw_circle(temp_coord, radius1, color, sim_on);

      } else if (!draw2.fixed) { // else if because then both radius will
                                 // increase at same time in starting even if
                                 // radius1 should increase in starting only
        radius2 += 1;
        perm_coord2 = temp_coord;
        draw2.will_draw_circle(temp_coord, radius2, color, sim_on);
      }

      if (draw1.fixed) {

        draw1.will_draw_circle(perm_coord1, radius1, color, sim_on);
        current_coord1 = perm_coord1;
        std::cout << perm_coord1.x << " per," << perm_coord1.y << std::endl;
      }
      if (draw2.fixed) {
        sim_on = true;
        draw1.will_draw_circle(perm_coord2, radius2, color, sim_on);
        current_coord2 = perm_coord2;
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
        draw1.fixed = true; // it is after draw2 becuase then draw2 will be
                            // turned ture in the starting when the draw1
                            // chnages true to stop that it is after;
        if (!sim_on) {
          draw2.will_draw_circle(perm_coord2, radius2, color, sim_on);
          draw1.will_draw_circle(perm_coord1, radius1, color, sim_on);
        }

        if (sim_on) {
          gr1.accle = gr1.acc(current_coord1, current_coord2, gr2.mass);
          gr1.posit = gr1.position(gr1.accle, gr1.inti_u, 1.0 / fps,
                                   current_coord1.x, current_coord1.y);

          gr2.accle = gr2.acc(current_coord2, current_coord1, gr1.mass);
          gr2.posit = gr2.position(gr2.accle, gr2.inti_u, 1.0 / fps,
                                   current_coord2.x, current_coord2.y);

          draw1.will_draw_circle(gr1.posit, radius1, color, !sim_on);
          draw2.will_draw_circle(gr2.posit, radius2, RED, !sim_on);

          gr1.inti_u.x = gr1.inti_u.x + gr1.accle.x * 1.0 / fps;
          gr1.inti_u.y = gr1.inti_u.y + gr1.accle.y * 1.0 / fps;

          gr2.inti_u.x = gr2.inti_u.x + gr2.accle.x * 1.0 / fps;

          gr2.inti_u.y = gr2.inti_u.y + gr2.accle.y * 1.0 / fps;

          current_coord1.x = gr1.posit.x;
          current_coord1.y = gr1.posit.y;
          current_coord2.x = gr2.posit.x;
          current_coord2.y = gr2.posit.y;
        }
      }
    }
    EndDrawing();
  }
  return 0;
}
