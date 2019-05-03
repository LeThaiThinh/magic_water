#pragma once
#include"Game.h"
#include"Blast.h"
#include<vector>
#include"BaseObject.h"
#define WidthMainObj  80
#define HeightMainObj  80
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
	void HandleEvent();
	void render();
	void SetLvl(int Lvl) { lvl = Lvl; }
	int GetLvl()const { return lvl; }
	void MakeBlast(MainObj* waterlist);
	std::vector<Blast*> GetBlastListUp() const  {return BlastListUp;}
	std::vector<Blast*> GetBlastListDown() const { return BlastListDown; }
	std::vector<Blast*> GetBlastListLeft() const { return BlastListLeft; }
	std::vector<Blast*> GetBlastListRight() const { return BlastListRight; }

private:
	int lvl;
	std::vector<Blast*> BlastListUp;
	std::vector<Blast*> BlastListDown;
	std::vector<Blast*> BlastListLeft;
	std::vector<Blast*> BlastListRight;
	Blast* BlastDown;
};