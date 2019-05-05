#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<Windows.h>
#include"BaseObject.h"
#include"TexureManager.h"
const int Screen_Width = 1200;

const int Screen_Height = 800;

const int screen_bpp = 16;
 
const int RemTurn_Height = 400;

const int RemTurn_Width = 400;
#define rowmax 80
#define columnmax 80
static SDL_Event event;   
class Game
{
public:
    Game();
    ~Game();
 
    void init(const char* title, int width, int height, bool fullscreen);
 
    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();
    static SDL_Renderer *renderer;
	void layhangchuc();
	void layhangdonvi();

private:
    bool isRunning = false;
	int countturn=20;
	bool dangno;
    SDL_Window *window;
	SDL_Texture* bkground = NULL,* RemainingTurn,*chuctex,*donvitex, *youlosetex;
	SDL_Rect youlose,bkgr,remturn,chuc,donvi;
};
