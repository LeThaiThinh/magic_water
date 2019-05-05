#pragma once
#include"Game.h"
#include<vector>
#define BlastWidth (int)(Screen_Height/columnmax/2.5)
#define BlastHeight (int)(Screen_Height/rowmax/2.5)
#define BlastV 2
class Blast :public BaseObj
{
public:

	Blast();
	~Blast();
	void MoveRight(const int& x_border, const int& y_border);
	void render();
	void MoveLeft(const int& x_border, const int& y_border);
	void MoveUp(const int& x_border, const int& y_border);
	void MoveDown(const int& x_border, const int& y_border);
	void Set_Ismove(bool is_move) { ismove = is_move;}
	void SetvX(int x) { vx = x; }
	void SetvY(int y) { vy = y; }
	bool Get_Ismove()const { return ismove; }
	void SetBlastUpTex() { ObjTex = TextureManager::LoadTexture("pic/blastup.png"); }
	void SetBlastDownTex() { ObjTex = TextureManager::LoadTexture("pic/blastdown.png"); }
	void SetBlastRightTex() { ObjTex = TextureManager::LoadTexture("pic/blastright.png"); }
	void SetBlastLeftTex() { ObjTex = TextureManager::LoadTexture("pic/blastleft.png"); }

private:
	bool ismove;
	int vx, vy;
};


