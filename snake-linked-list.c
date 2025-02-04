#include <raylib.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Snake Linked List by Sixten B"
#define APPLE_SIZE 20
#define INIT_SPEED 10
#define SNAKE_SIZE APPLE_SIZE
#define MAX_SNAKE_LENGTH 1000 // Maximum number of segments in the snake

typedef struct SnakeSegment {
    Vector2 position;
    Vector2 direction;
} SnakeSegment;

typedef struct Apple {
    Vector2 position;
    bool active;
    Color color;
} Apple;

void InitGame();
void UpdateGame();
void DrawGame();
void UpdateSnake();
void AddSegmentToSnake();
void DrawSnake();
void UpdateApple();
void CheckCollision();
void GameLoop();

SnakeSegment snake[MAX_SNAKE_LENGTH];  // Array of SnakeSegments
int snakeLength = 1;  // Initial length of the snake
Apple apple;
int fps;
bool gameOver = false;

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    InitGame();
    SetTargetFPS(INIT_SPEED);

    GameLoop();

    CloseWindow();
    return 0;
}

void InitGame() {
    snake[0].position = (Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    snake[0].direction = (Vector2){SNAKE_SIZE, 0}; // Initial movement direction

    apple.position = (Vector2){rand() % (WINDOW_WIDTH - APPLE_SIZE), rand() % (WINDOW_HEIGHT - APPLE_SIZE)};
    apple.active = true;
    apple.color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};

    fps = INIT_SPEED;
}

void UpdateGame() {
    UpdateSnake();
    UpdateApple();
    CheckCollision();
}

void DrawGame() {
    DrawSnake();
    if (apple.active) {
        DrawRectangleV(apple.position, (Vector2){APPLE_SIZE, APPLE_SIZE}, apple.color);
    }
}

void CheckCollision() {
        // Create rectangles for head and body segment
        Rectangle headRect = (Rectangle){snake[0].position.x, snake[0].position.y, SNAKE_SIZE, SNAKE_SIZE};
        Rectangle bodyRect = (Rectangle){snake->position.x, snake->position.y, SNAKE_SIZE, SNAKE_SIZE};
        Rectangle appleRect = (Rectangle){apple.position.x, apple.position.y, APPLE_SIZE, APPLE_SIZE};

        // Check if the head collides with body
        if (CheckCollisionRecs(headRect, bodyRect)) {
            gameOver = true;
        }

    // Check if the head collides with the wall
    if (headRect.x < 0 || headRect.x >= WINDOW_WIDTH || headRect.y < 0 || headRect.y >= WINDOW_HEIGHT) {
        gameOver = true;
    }

    // Check if the snake eats an apple
    if (CheckCollisionRecs(headRect, appleRect)) {
            apple.active = false;
            AddSegmentToSnake();
            
        }
}



void UpdateSnake() {
    if (IsKeyPressed(KEY_RIGHT) && snake[0].direction.x == 0) {
        snake[0].direction = (Vector2){SNAKE_SIZE, 0};
    }
    if (IsKeyPressed(KEY_LEFT) && snake[0].direction.x == 0) {
        snake[0].direction = (Vector2){-SNAKE_SIZE, 0};
    }
    if (IsKeyPressed(KEY_UP) && snake[0].direction.y == 0) {
        snake[0].direction = (Vector2){0, -SNAKE_SIZE};
    }
    if (IsKeyPressed(KEY_DOWN) && snake[0].direction.y == 0) {
        snake[0].direction = (Vector2){0, SNAKE_SIZE};
    }

    // Move the snake segments
    Vector2 oldPos = snake[0].position;
    snake[0].position.x += snake[0].direction.x;
    snake[0].position.y += snake[0].direction.y;

    // Update the positions of the rest of the snake segments
    for (int i = 1; i < snakeLength; i++) {
        Vector2 temp = snake[i].position;
        snake[i].position = oldPos;
        oldPos = temp;
    }
}


void AddSegmentToSnake() {
    if (snakeLength < MAX_SNAKE_LENGTH) {
        snake[snakeLength] = snake[snakeLength - 1];
        snakeLength++;
    }

    apple.position = (Vector2){rand() % (WINDOW_WIDTH - APPLE_SIZE), rand() % (WINDOW_HEIGHT - APPLE_SIZE)};
    apple.active = true;
}

void DrawSnake() {
    for (int i = 0; i < snakeLength; i++) {
        DrawRectangleV(snake[i].position, (Vector2){SNAKE_SIZE, SNAKE_SIZE}, GREEN);
    }
}

void UpdateApple() {
    if (!apple.active) {
        apple.position = (Vector2){rand() % (WINDOW_WIDTH - APPLE_SIZE), rand() % (WINDOW_HEIGHT - APPLE_SIZE)};
        apple.active = true;
    }
}

void GameLoop() {
    while (!WindowShouldClose()) {
      gameOver = false;
      if(gameOver){
          break;
        }
        UpdateGame();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame();
        EndDrawing();
    }
}