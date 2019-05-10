#pragma once
class point
{
public:
	point();
	void handleEvent();
	void update();
	void render();
private:
	int x = 0;
	int y = 0;
	SDL_Texture* pointedSqr;
	SDL_Rect dest;
};
