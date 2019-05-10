#pragma once
#include"Game.h"
#include<vector>
class BaseObj
{
public:
	BaseObj();
	~BaseObj();
	void SetRectDes(int x, int y) { des.x = x; des.y = y; }
	int getY()const { return des.y; }
	int getX()const { return des.x; }
	SDL_Texture* getTex()const { return ObjTex; }
protected:
	SDL_Texture* ObjTex;
	SDL_Rect scr, des;
private:

};
