#pragma once
#include "Common.h"
#include "Player.h"
#include "Title.h"
#include "InGame.h"

class Gdata
{
private:
	string _dataName = "saveData.txt";
	int _nowScene = 0;

	// 시간
	int _year = 0;
	int _month = 0;

	// 진행도
	int _floor = 0;

public:
	Pdata pdata;

public:
	void Init();
	void SaveGame();
	bool LoadGame();

	int GetYear();
	void SetYear(int year);
	void SetYear(string year);

	int GetMonth();
	void SetMonth(int month);
	void SetMonth(string month);
	void UpdateMonth(int month);

	int GetFloor();
	void SetFloor(int floor);
	void SetFloor(string floor);
	void UpdateFloor(int floor);

	int GetScene();
	void ChangeSecene(int sceneNum);

};

__declspec(selectany) Gdata gdata;
