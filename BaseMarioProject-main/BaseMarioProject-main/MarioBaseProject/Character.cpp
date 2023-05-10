#include "Character.h"
#include "Texture2D.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_facing_direction = FACING_RIGHT;

	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << ("Failed to load texture") << std::endl;
		
	}
	m_moving_left = false;
	m_moving_right = false;
}

void Character::AddGravity(float deltaTime)
{
	if ((m_position.y + 64) <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY;
	}
	else
	{
		m_can_jump = true;
	}
}

void Character::MoveLeft(float deltaTime)
{
	m_position.x -= deltaTime * MOVEMENT_SPEED;
	m_facing_direction = FACING_LEFT;
}

void Character::MoveRight(float deltaTime)
{
	m_position.x += deltaTime * MOVEMENT_SPEED;
	m_facing_direction = FACING_RIGHT;
}

void Character::Jump()
{
	if (!m_jumping)
	{
		m_jump_force = INITIAL_JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}
	
}

void Character::Render()
{
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else if(m_facing_direction == FACING_LEFT)
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
	
}

void Character::Update(float deltaTime, SDL_Event e)
{
	
	SDL_PollEvent(&e);

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			
			m_moving_left = true;
			break;
		}
			
		case SDLK_RIGHT:
		{
		
			m_moving_right = true;
			break;
		}
		case SDLK_UP:
		{
			Jump();
			break;
		}
			
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			m_moving_left = false;
			break;
		}
		case SDLK_RIGHT:
		{
			m_moving_right = false;
			break;
		}
		}
		break;
	}


	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}

	if (m_jumping)
	{
		m_position.y -= m_jump_force * deltaTime;

		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		if (m_jump_force <= 0.0f)
			m_jumping = false;
		
	}
	AddGravity(deltaTime);
}



void Character::setPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}

Character::~Character()
{
	delete m_renderer;
}