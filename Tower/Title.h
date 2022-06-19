#pragma once
#include "Common.h"
#include "GameManager.h"
#include "InGame.h"

class Title
{
private :
	int nowLocale = ENG;
	int nowMenu = NEW;

	string newGame[2] = { "New Game", "새로운 시작" };
	string loadGame[2] = { "Load Game", "이어하기" };
	string exitGame[2] = { "Exit", "게임 종료" };

	enum LOCALE
	{
		ENG,
		KOR
	};

	enum MENU
	{
		NEW,
		LOAD,
		EXIT
	};
	
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

__declspec(selectany) Title title;