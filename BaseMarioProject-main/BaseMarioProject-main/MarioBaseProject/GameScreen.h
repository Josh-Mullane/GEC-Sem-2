#pragma once
#include <SDL.h>
#include <iostream>
#include "Texture2D.h"
class GameScreen
{
public:

	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	

private:

	

	Texture2D* m_background_texture;

protected:

	SDL_Renderer* m_renderer;

};

