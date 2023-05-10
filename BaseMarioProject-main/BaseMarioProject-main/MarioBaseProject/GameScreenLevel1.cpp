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

	my_character = new Character(m_renderer, "Images/Mario.png", Vector2D(64, 330));
}

void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character->Render();
}

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}





void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	my_character->Update(deltaTime, e);

}

GameScreenLevel1::~GameScreenLevel1()
{
	delete m_background_texture;
	delete my_character;

	my_character = nullptr;
	m_background_texture = nullptr;

	
}