#include "TexureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* tmpSurface = IMG_Load(filename);
	if(tmpSurface!=NULL)
	SDL_SetColorKey(tmpSurface, 1, SDL_MapRGB(tmpSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}
void TextureManager::Draw(SDL_Texture*tex , SDL_Rect scr, SDL_Rect des)
{
	SDL_RenderCopy(Game::renderer, tex, &scr, &des);
}
