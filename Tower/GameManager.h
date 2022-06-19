#pragma once
#include "Common.h"

#include "Player.h"
#include "Scene.h"

using namespace std;

class Gdata
{
private:
	string _dataName = "saveData.txt";

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
	void LoadGame();

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

};

static Gdata gdata;