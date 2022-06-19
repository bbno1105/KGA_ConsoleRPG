#pragma once

#include "Common.h"

class InGame
{
private:
	int selectMenu = 0;

	int nowMenu[4] = { 3, 3, 2, 1 };
	int menuState = 0;

	string Menu[4][3] = { { "단련하기", "아르바이트", "탐험하기" },
						  { "기초체력(-100G)", "주먹단련(-150G)", "달리기(-150G)" },
						  { "농장(100G)", "배달(50,150G)", ""},
						  { "탑 오르기", "", ""}};

	string text[4] = { "" };

public:
	void Init();
	void Update();
	void Render();
	void Release();
};