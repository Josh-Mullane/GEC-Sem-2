#pragma once
//screen Dimensions
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 416
#include <string>

bool InitSDL();
void CloseSDL();
bool Update();

void Render();
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();