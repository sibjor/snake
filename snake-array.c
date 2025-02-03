#include <raylib.h>
#include <stdlib.h>

#define APPLE_SIZE 20

typedef struct Snake {
  Vector2 pos[(800 / 600) * APPLE_SIZE];
  int length;
  Vector2 direction;
} Snake;

typedef struct Apple {
  Vector2 pos;
  bool active;
} Apple;

void InitGame(Snake *snake, Apple *apple, int width, int height);
void UpdateGame(Snake *snake, Apple *apple, int width, int height);
void DrawGame(Snake *snake, Apple *apple);

int main(void) {
  // Initialization
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Snake Array by Sixten B");

  Snake snake;
  Apple apple;

  InitGame(&snake, &apple, screenWidth, screenHeight);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update
    UpdateGame(&snake, &apple, screenWidth, screenHeight);
    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawGame(&snake, &apple);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}

void InitGame(Snake *snake, Apple *apple, int width, int height) {
  snake->length = 4;
  snake->pos[0] = (Vector2){width / APPLE_SIZE, height / APPLE_SIZE};
  snake->direction = (Vector2){1, 0};
  apple->pos = (Vector2){(rand() % (width / APPLE_SIZE)) * APPLE_SIZE,
                         (rand() % (height / APPLE_SIZE) * APPLE_SIZE)};
  apple->active = true;
}

void UpdateGame(Snake *snake, Apple *apple, int width, int height) {
  if (IsKeyPressed(KEY_RIGHT) && snake->direction.x == 0)
    snake->direction = (Vector2){APPLE_SIZE, 0};
  if (IsKeyPressed(KEY_LEFT) && snake->direction.x == 0)
    snake->direction = (Vector2){-APPLE_SIZE, 0};
  if (IsKeyPressed(KEY_UP) && snake->direction.y == 0)
    snake->direction = (Vector2){0, -APPLE_SIZE};
  if (IsKeyPressed(KEY_DOWN) && snake->direction.y == 0)
    snake->direction = (Vector2){0, APPLE_SIZE};

  for (int i = snake->length - 1; i > 0; i--) {
    snake->pos[i] = snake->pos[i - 1];
  }

  snake->pos[0].x += snake->direction.x;
  snake->pos[0].y += snake->direction.y;

  if (snake->pos[0].x >= width)
    snake->pos[0].x = 0;
  if (snake->pos[0].y >= height)
    snake->pos[0].y = 0;
  if (snake->pos[0].x < 0)
    snake->pos[0].x = width - APPLE_SIZE;
  if (snake->pos[0].y < 0)
    snake->pos[0].y = height - APPLE_SIZE;

  if (CheckCollisionRecs(
          (Rectangle){snake->pos[0].x, snake->pos[0].y, APPLE_SIZE, APPLE_SIZE},
          (Rectangle){apple->pos.x, apple->pos.y, APPLE_SIZE, APPLE_SIZE})) {
    apple->pos = (Vector2){(rand() % (width / APPLE_SIZE)) * APPLE_SIZE,
                           (rand() % (height / APPLE_SIZE)) * APPLE_SIZE};
    snake->length++;
  }
}

void DrawGame(Snake *snake, Apple *apple) {
  for (int i = 0; i < snake->length; i++) {
    DrawRectangleV(snake->pos[i], (Vector2){APPLE_SIZE, APPLE_SIZE}, DARKGREEN);
  }

  DrawRectangleV(apple->pos, (Vector2){APPLE_SIZE, APPLE_SIZE}, RED);
}