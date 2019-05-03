#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"Game.h"
class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect scr, SDL_Rect des);

};