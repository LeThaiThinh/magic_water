#include"MainObj.h"

MainObj::MainObj()
{
	Countblastremain = 0;
	ObjTex = NULL;
	des.w = WidthMainObj; des.h = HeightMainObj;
	des.x = 0; des.y = 0;
	lvl = lvl0;
	BlastDown = new Blast();
	BlastUp = new Blast();
	BlastLeft = new Blast();
	BlastRight = new Blast();
}

MainObj::~MainObj()
{
	ObjTex = nullptr;
}
void MainObj::update()
{
	Mix_Chunk* BlastSound = Mix_LoadWAV("sound/blastsound.wav");
	switch (lvl)
	{
	case lvl0:
		ObjTex = TextureManager::LoadTexture("pic/lvl0.png");
		break;
	case lvl1:
		ObjTex = TextureManager::LoadTexture("pic/lvl1.png");
		break;
	case lvl2:
		ObjTex = TextureManager::LoadTexture("pic/lvl2.png");
		break;
	case lvl3:
		ObjTex = TextureManager::LoadTexture("pic/lvl3.png");
		break;
	case lvl4:
		ObjTex = TextureManager::LoadTexture("pic/lvl4.png");
		break;
	case lvl5:
	{	

		Mix_PlayChannel(-1, BlastSound, 0);
		this->~MainObj();
		srand(0);
		ObjTex = TextureManager::LoadTexture("pic/lvl0.png");
		lvl = lvl0;
		std::cout << des.x / WidthMainObj << " _ " << des.y / HeightMainObj<<std::endl;
		std::cout << ObjTex << " _ " << "" << std::endl;
		//blastup
		BlastUp->SetBlastUpTex();
		BlastUp->SetRectDes(des.x +  WidthMainObj / 2 - BlastWidth * 1 / 2, des.y + BlastHeight * 1 / 2);
		
		BlastUp->SetvY(BlastV);
		BlastUp->Set_Ismove(true);
		//blastdown
		BlastDown->SetBlastDownTex();
		BlastDown->SetRectDes(des.x + WidthMainObj/2- BlastWidth * 1 / 2, des.y + HeightMainObj - BlastHeight * 1 / 2);

		BlastDown->SetvY(BlastV);
		BlastDown->Set_Ismove(true);	
		//blastright
		BlastRight->SetBlastRightTex();
		BlastRight->SetRectDes(des.x +WidthMainObj- BlastWidth*1/2, des.y + HeightMainObj/2 - BlastHeight * 1 / 2);
	
		BlastRight->SetvX(BlastV);
		BlastRight->Set_Ismove(true);
		//blastleft
		BlastLeft->SetBlastLeftTex();
		BlastLeft->SetRectDes(des.x  + BlastWidth * 1 / 2, des.y + HeightMainObj / 2 - BlastHeight * 1 / 2);

		BlastLeft->SetvX(BlastV);
		BlastLeft->Set_Ismove(true);

	}
	break;
	default:
		break;
	}
}

void MainObj::render()
{
	SDL_RenderCopy(Game::renderer, ObjTex, NULL, &des);
}

int MainObj::MakeBlast(MainObj* waterlist)
{
	MainObj::Countblastremain = 0;
	//Down
	if (BlastDown != nullptr)
	{
		if (BlastDown->Get_Ismove())
		{
			if ((waterlist + (BlastDown->getX() + BlastWidth / 3) / WidthMainObj + (BlastDown->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() != 0
				and
				(waterlist + (BlastDown->getX() + BlastWidth / 3) / WidthMainObj + (BlastDown->getY() + BlastHeight / 3) / HeightMainObj * columnmax) != NULL) {
					{
						(waterlist + (BlastDown->getX() + BlastWidth / 3) / WidthMainObj + (BlastDown->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->SetLvl((waterlist + (BlastDown->getX() + BlastWidth / 3) / WidthMainObj + (BlastDown->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() + 1);
						(waterlist + (BlastDown->getX() + BlastWidth / 3) / WidthMainObj + (BlastDown->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->update();

						BlastDown->Set_Ismove(false);
						delete BlastDown;
						BlastDown = nullptr;
					}
			}
			if (BlastDown != nullptr)
			{
				BlastDown->MoveDown(Screen_Width * 2 / 3, Screen_Height);
				BlastDown->render();
			}
			Countblastremain++;

		}
	}
//Up
		if (BlastUp != nullptr)
		{
			if (BlastUp->Get_Ismove())
			{
				if ((waterlist + (BlastUp->getX() + BlastWidth / 3) / WidthMainObj + (BlastUp->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() != 0
					and
					(waterlist + (BlastUp->getX() + BlastWidth / 3) / WidthMainObj + (BlastUp->getY() + BlastHeight / 3) / HeightMainObj * columnmax) != NULL)
				{
					{
						(waterlist + (BlastUp->getX() + BlastWidth / 3) / WidthMainObj + (BlastUp->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->SetLvl((waterlist + (BlastUp->getX() + BlastWidth / 3) / WidthMainObj + (BlastUp->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() + 1);
						(waterlist + (BlastUp->getX() + BlastWidth / 3) / WidthMainObj + (BlastUp->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->update();

						BlastUp->Set_Ismove(false);
						delete BlastUp;
						BlastUp = nullptr;
					}
				}
				if (BlastUp != nullptr)
				{
					BlastUp->MoveUp(Screen_Width * 2 / 3, Screen_Height);
					BlastUp->render();
				}
				Countblastremain++;
			}
		}
//Right
		if (BlastRight != nullptr)
		{
			if (BlastRight->Get_Ismove())
			{
				if ((waterlist + (BlastRight->getX() + BlastWidth / 3) / WidthMainObj + (BlastRight->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() != 0
					and
					(waterlist + (BlastRight->getX() + BlastWidth / 3) / WidthMainObj + (BlastRight->getY() + BlastHeight / 3) / HeightMainObj * columnmax) != NULL)
				{
					{
						(waterlist + (BlastRight->getX() + BlastWidth / 3) / WidthMainObj + (BlastRight->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->SetLvl((waterlist + (BlastRight->getX() + BlastWidth / 3) / WidthMainObj + (BlastRight->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() + 1);
						(waterlist + (BlastRight->getX() + BlastWidth / 3) / WidthMainObj + (BlastRight->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->update();
						BlastRight->Set_Ismove(false);
						delete BlastRight;
						BlastRight = nullptr;
					}
				}
				if (BlastRight != nullptr)
				{
					BlastRight->MoveRight(Screen_Width * 2 / 3, Screen_Height);
					BlastRight->render();
				}
				Countblastremain++;
			}
		}
//Left
		if (BlastLeft != nullptr)
		{
			if (BlastLeft->Get_Ismove())
			{
				if ((waterlist + (BlastLeft->getX() + BlastWidth / 3) / WidthMainObj + (BlastLeft->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() != 0
					and
					(waterlist + (BlastLeft->getX() + BlastWidth / 3) / WidthMainObj + (BlastLeft->getY() + BlastHeight / 3) / HeightMainObj * columnmax) != NULL)
				{
					(waterlist + (BlastLeft->getX() + BlastWidth / 3) / WidthMainObj + (BlastLeft->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->SetLvl((waterlist + (BlastLeft->getX() + BlastWidth / 3) / WidthMainObj + (BlastLeft->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->GetLvl() + 1);
					(waterlist + (BlastLeft->getX() + BlastWidth / 3) / WidthMainObj + (BlastLeft->getY() + BlastHeight / 3) / HeightMainObj * columnmax)->update();
					BlastLeft->Set_Ismove(false);
					delete BlastLeft;
					BlastLeft = nullptr;
				}
				if (BlastLeft != nullptr)
				{
					BlastLeft->MoveLeft(Screen_Width * 2 / 3, Screen_Height);
					BlastLeft->render();
				}
				Countblastremain++;
			}
			
		}
		return Countblastremain;
}
