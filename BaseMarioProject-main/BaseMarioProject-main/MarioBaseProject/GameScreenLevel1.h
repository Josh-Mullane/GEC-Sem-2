#pragma once
#include "GameScreen.h"
#include <iostream>
#include "commons.h"
#include "Texture2D.h"

class Texture2D;

class GameScreenLevel1 : GameScreen
{
public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	

	Texture2D* m_background_texture;



	
private:

	bool SetUpLevel();
};

