#include "GameScreenManager.h"
#include "GameScreenLevel1.h"
#include "GameScreen.h"
#include <iostream>

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	GameScreenLevel1* tempScreen;

	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
	default:;
	}
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_current_screen = nullptr;
	m_renderer = renderer;
	ChangeScreen(startScreen);

}

GameScreenManager::~GameScreenManager()
{
	delete m_current_screen;
	
}


