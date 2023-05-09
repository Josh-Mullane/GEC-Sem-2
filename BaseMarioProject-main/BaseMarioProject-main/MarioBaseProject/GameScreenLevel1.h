#pragma once
#include "GameScreen.h"
class GameScreenLevel1
{
public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	bool SetUpLevel();
};

