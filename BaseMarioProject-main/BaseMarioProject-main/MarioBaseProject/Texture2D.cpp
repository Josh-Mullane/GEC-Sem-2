#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Texture2d::Texture2D(SDL_Renderer* renderer);

bool LoadFromFile(std::string path);
void Free();
void Render(Vector2D new_position, SDL_RendererFlip flip, double angle 0.0);