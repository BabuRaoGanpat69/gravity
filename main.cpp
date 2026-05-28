#include "drawcircle.cpp"
#include "gravity.cpp"
#include "input.cpp"
// #include "string"
// #include <iostream>
#include <raylib.h>
// #include <string>
#include <vector>

Vector2 addvec(Vector2 vec1, Vector2 vec2) {
  return {vec1.x + vec2.x, vec1.y + vec2.y};
}

int main() {

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "GRAVITY");

  Font font{GetFontDefault()};
  int spacing = 3;
  bool sim_on = false;
  bool started = false;
  Color color{GOLD};
  Vector2 temp_coord;

  float scale = 1;
  input inp;
  int x_pad = 40;
  int y_pad = 27;
  int fsize = 25;

  my_DrawCircle draw1;

  std::vector<gravity *> bodies;
  gravity *gr = {};
  int noOfBody = 0;

  int fps = 60;

  float dt = (1.0 / fps) * scale;
  SetTargetFPS(fps);
  while (!WindowShouldClose()) {
    BeginDrawing();

    if (IsKeyPressed(KEY_W)) {
      scale += 0.5;
      dt = (1.0 / fps) * scale;
    }
    if (IsKeyPressed(KEY_S)) {
      scale -= 0.5;
      if (scale <= 0) {
        scale = 1;
      }
      dt = (1.0 / fps) * scale;
    };

    ClearBackground(BLACK);
    temp_coord = inp.r_coord();
    std::cout << dt << std::endl;
    if (IsMouseButtonPressed(1)) {
      sim_on = true;
    }
    if (IsMouseButtonPressed(0)) {
      noOfBody += 1;
      started = true;
      gr = new gravity;
      bodies.push_back(gr);

      gr->num = noOfBody;
    };

    if (IsMouseButtonDown(0)) {
      for (auto mass : bodies) {
        if (!mass->fixed) {
          mass->radius += 1;
          mass->posit = temp_coord;
          mass->mass = mass->M * pow(1.04, mass->radius);
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
            mass->accle = {0, 0};
            for (auto body : bodies) {
              mass->accle = addvec(
                  mass->accle, gr->acc(mass->posit, body->posit, body->mass));
            }
            mass->posit =
                gr->position(mass->accle, mass->inti_u, dt, mass->posit);
            mass->inti_u = addvec(mass->inti_u,
                                  {(mass->accle.x) * dt, (mass->accle.y) * dt});
            draw1.will_draw_circle(mass->posit, mass->radius, RED, !sim_on,
                                   mass->fixed);
            draw1.stats(mass, x_pad, y_pad, fsize, font, WHITE, spacing);
          }
        };
      };
    }
    EndDrawing();
  }
  delete gr;
  return 0;
}
