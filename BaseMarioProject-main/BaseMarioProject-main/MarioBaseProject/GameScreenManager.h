#pragma once
#include <SDL.h>
#include "commons.h"
class GameScreenManager
{
public:

	class GameScreen;

	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS new_screen);

private:

	SDL_Renderer* m_renderer;
	GameScreen* m_current_screen;

};

