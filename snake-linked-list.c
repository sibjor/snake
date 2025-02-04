/*
Pupil: Sixten Björling
Teacher: Sebastian Jensen
Course: Game Programming
School Forsbergs YH
Assignment: Linked list Snake game
Date: 2025-02-04
*/

/*
En linked list är en dynamisk datastruktur där varje element
(nod) innehåller data och en pekare till nästa nod i listan. Till skillnad från
arrayer lagras elementen inte i sammanhängande minnesplatser, vilket gör att
storleken enkelt kan ändras vid behov.
*/
#include <raylib.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Snake Linked List by Sixten B"
#define APPLE_SIZE 4

typedef struct Snake {
  int speed;
  int length[];

} Snake;

typedef struct Apple {
  Vector2 position;
  Vector2 direction;
  struct Apple *next;
  Color color;
  bool active;
} Apple;

void InitGame();

void UpdateGame();

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  InitGame();
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateGame();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

void InitGame() {}

void UpdateGame() {}
