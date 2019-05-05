include"Blast.h"

Blast::Blast()
{
	des.x = 0;
	des.y = 0;
	des.w = BlastWidth;
	des.h = BlastHeight;
	vx = 0;
	vy = 0;
	ismove = false;
	
}
Blast::~Blast()
{
	des.x = 0;
	des.y = 0;
	des.w = 0;
	des.h = 0;
	vx = 0;
	vy = 0;
	ismove = false;
	ObjTex = NULL;
}



void Blast::render()
{
	SDL_RenderCopy(Game::renderer, ObjTex, NULL, &des);
}

void Blast::MoveLeft(const int& x_border, const int& y_border)
{
	if (ismove == true)
	{
		des.x -= vx;
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

