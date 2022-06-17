#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Player.h"

using namespace std;

class Gdata
{
private:
	string _dataName = "saveData.txt";

public:
	void Init()
	{
		//초기 세팅??
	}

	void SaveGame()
	{
		ofstream SaveData(_dataName);
		SaveData << pdata.GetName() << "\n";
		SaveData << pdata.GetHP() << "\n";
		SaveData << pdata.GetAttackPower() << "\n";
		SaveData << pdata.GetSpeed() << "\n";
		SaveData << pdata.GetGold() << "\n";
		SaveData << pdata.GetYear() << "\n";
		SaveData << pdata.GetMonth() << "\n";
		SaveData << pdata.GetFloor();
		SaveData.close();
	}

	void LoadGame()
	{
		ifstream LoadData;
		if (!LoadData.is_open())
		{
			LoadData.open(_dataName);
		}

		string str;

		getline(LoadData, str);
		pdata.SetName(str);

		getline(LoadData, str);
		pdata.SetHP(str);

		getline(LoadData, str);
		pdata.SetAttackPower(str);

		getline(LoadData, str);
		pdata.SetSpeed(str);

		getline(LoadData, str);
		pdata.SetGold(str);

		getline(LoadData, str);
		pdata.SetYear(str);

		getline(LoadData, str);
		pdata.SetMonth(str);

		getline(LoadData, str);
		pdata.SetFloor(str);

		LoadData.close();
	}
}gdata;