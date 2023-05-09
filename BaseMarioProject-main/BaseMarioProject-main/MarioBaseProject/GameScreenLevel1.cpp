#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>
#include "commons.h"

bool GameScreenLevel1::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;

	}
}

void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}





void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{


}

GameScreenLevel1::~GameScreenLevel1()
{
	delete m_background_texture;
	
}