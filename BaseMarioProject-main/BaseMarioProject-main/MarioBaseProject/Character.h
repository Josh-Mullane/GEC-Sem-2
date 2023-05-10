#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#include "commons.h"

using namespace std;

class Texture2D;

class Character
{
public:

	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void setPosition(Vector2D new_position);
	Vector2D GetPosition();

private:

protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
};

