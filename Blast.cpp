#include"Blast.h"

Blast::Blast()
{
	des.x = 0;
	des.y = 0;
	des.w = BlastWidth;
	des.h = BlastHeight;
	vx = 0;
	vy = 0;
	ismove = false;
	scr.x = 0;
	scr.y = 0;
	scr.h = 125;
	scr.w = 125;
	ObjTex = nullptr;
}
Blast::~Blast()
{
	des.x = NULL;
	des.y = NULL;
	des.w = NULL;
	des.h = NULL;
	vx =NULL;
	vy = NULL;
	ismove = NULL;
	ObjTex = nullptr;
}
void Blast::render()
{
	SDL_RenderCopy(Game::renderer, ObjTex, &scr, &des);
}

void Blast::MoveLeft(const int& x_border, const int& y_border)
{
	if (ismove == true)
	{
		des.x -= vx;
		//scr.x = (scr.x + 125) % 1000;
		if (des.x+BlastWidth > x_border or des.y + BlastHeight > y_border or des.x < 0 or des.y < 0)
		{
			ismove = false;
			if (this != NULL)
			{
				this->~Blast();
			}
		}
	}
}

void Blast::MoveUp(const int& x_border, const int& y_border)
{
	if (ismove == true)
	{
		des.y -= vy;
		//scr.y = (scr.y + 125) % 1000;
		if (des.x + BlastWidth> x_border or des.y + BlastHeight >y_border or des.x<0 or des.y<0)
		{
			ismove = false;
			if (this != NULL)
			{
				this->~Blast();
			}
		}
	}
}

void Blast::MoveDown(const int& x_border, const int& y_border)
{
	if (ismove == true)
	{
		des.y += vy;
		//scr.y = (scr.y + 125) % 1000;
		if (des.x +BlastWidth> x_border or des.y+BlastHeight > y_border or des.x < 0 or des.y < 0)
		{
			ismove = false;
			if (this != NULL)
			{
				this->~Blast();
			}
		}
	}
}

void Blast::MoveRight(const int& x_border, const int& y_border)
{
	if (ismove == true)
	{
		des.x += vx;
		//scr.x =(scr.x+ 125)%1000;
		if (des.x+ BlastWidth > x_border or des.y + BlastHeight > y_border or des.x < 0 or des.y < 0)
		{
			ismove = false;
			if (this != NULL)
			{
				this->~Blast();
			}
		}
	}
}

