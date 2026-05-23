#include "drawcircle.cpp"
#include "gravity.cpp"
#include "input.cpp"
#include <iostream>
#include <raylib.h>
#include <vector>

Vector2 addvec(Vector2 vec1, Vector2 vec2) {
  return {vec1.x + vec2.x, vec1.y + vec2.y};
}

int main() {

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GRAVITY");

  bool sim_on = false;
  bool started = false;
  Color color{GOLD};
  Vector2 temp_coord;

  input inp;

  my_DrawCircle draw1;

  std::vector<gravity *> bodies;
  gravity *gr = {};
  int noOfBody = 0;

  int fps = 60;
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    temp_coord = inp.r_coord();

    if (IsMouseButtonPressed(1)) {
      sim_on = true;
    }
    if (IsMouseButtonPressed(0)) {
      noOfBody += 1;
      started = true;
      gr = new gravity;
      bodies.push_back(gr);
    };

    if (IsMouseButtonDown(0)) {
      for (auto mass : bodies) {
        if (!mass->fixed) {
          mass->radius += 1;
          mass->posit = temp_coord;
          mass->mass = mass->M * pow(1.08, mass->radius);
        }
        draw1.will_draw_circle(mass->posit, mass->radius, color, false,
                               mass->fixed);
      };
    }
    if (started) {
      if (IsMouseButtonUp(0)) {
        (*(bodies.begin() + noOfBody - 1))->fixed = true;
        if (!sim_on) {
          for (auto mass : bodies)
            draw1.will_draw_circle(mass->posit, mass->radius, color, sim_on,
                                   mass->fixed);
        }
        if (sim_on) {
          for (auto mass : bodies) {
            for (auto body : bodies) {
              mass->accle = addvec(
                  mass->accle, gr->acc(mass->posit, body->posit, body->mass));
            }
            mass->posit = gr->position(mass->accle, mass->inti_u, 1.0 / fps,
                                       mass->posit.x, mass->posit.y);
            mass->inti_u = addvec(
                mass->inti_u, {(mass->accle.x) / fps, (mass->accle.y) / fps});
            draw1.will_draw_circle(mass->posit, mass->radius, WHITE, !sim_on,
                                   mass->fixed);
          };
        };
      }
    }
    EndDrawing();
  }
  delete gr;
  return 0;
}
