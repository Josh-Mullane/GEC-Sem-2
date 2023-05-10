#pragma once
//screen Dimensions
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 416
#define MOVEMENT_SPEED 90
#define GRAVITY 260 * deltaTime
#define JUMP_FORCE_DECREMENT 400.0f
#define INITIAL_JUMP_FORCE 600.0f

bool InitSDL();
void CloseSDL();