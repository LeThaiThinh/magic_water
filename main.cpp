#include "Game.h"
Game *game = nullptr;
SDL_Renderer* Game::renderer=nullptr;
int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frametime;
    game = new Game();
    game->init("GameWindow", Screen_Width, Screen_Height, false);
	srand(NULL);
	
    while (game->running())
    {
		frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
		game->render();
		
	
		frametime = SDL_GetTicks() - frameStart;
		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime);
		}
    }
 
    game->clean();
    return 0;
}