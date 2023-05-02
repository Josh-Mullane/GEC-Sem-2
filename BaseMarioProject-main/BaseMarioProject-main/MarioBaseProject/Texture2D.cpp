#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_renderer = renderer;

}

Texture2D::~Texture2D()
{
	Free();

	m_renderer = nullptr;
}



bool Texture2D::LoadFromFile(std::string path)
{
	SDL_Texture* m_texture = nullptr;
	SDL_Surface* m_surface = IMG_Load(path.c_str());
	if (m_surface != nullptr)
	{

	}

}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	SDL_Rect renderLocation = { 0,0,m_width, m_height };

	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, 0, nullptr, SDL_FLIP_NONE);
}


void Texture2D::Free()
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}
}