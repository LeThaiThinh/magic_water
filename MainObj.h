#pragma once
#include"Game.h"
#include"Blast.h"
#include<vector>
#include"BaseObject.h"
#define WidthMainObj  (int)(Screen_Height/columnmax)
#define HeightMainObj (int)(Screen_Height/rowmax)
class MainObj :public BaseObj {
public:
	enum Lvl {
		lvl0 = 0,
		lvl1 = 1,
		lvl2 = 2,
		lvl3 = 3,
		lvl4 = 4,
		lvl5 = 5
	};
	MainObj();
	~MainObj();
	void update();
	void render();
	void SetLvl(int Lvl) { lvl = Lvl; }
	int GetLvl()const { return lvl; }
	int MakeBlast(MainObj* waterlist);
private:
	int Countblastremain;
	int lvl;
	Blast* BlastDown;
	Blast* BlastUp;
	Blast* BlastRight;
	Blast* BlastLeft;
};
