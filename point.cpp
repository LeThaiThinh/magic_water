/*#include<SDL_image.h>
#include<SDL.h>
#include"Game.h"
#include"TextureManager.h"
#include"point.h"
point::point()
{
	pointedSqr = TextureManager::LoadTexture("pic/pointed.png");
	dest.h = Game::Sizeh / 4; dest.w = Game::Sizew / 4;
	dest.x = 0; dest.y = 0;
}
void point::handleEvent()
{
		x = (Game::event.button.x/ Game::Sizew)* Game::Sizew;
		y = (Game::event.button.y / Game::Sizeh) * Game::Sizeh;
}
void point::update()
{
	dest.h = Game::Sizeh/4; dest.w = Game::Sizew / 4;
	dest.x = x; dest.y = y;
}
void point::render()
{
	SDL_RenderCopy(Game::renderer, pointedSqr, NULL, &dest);
}*/