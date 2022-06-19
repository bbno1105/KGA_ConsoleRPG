#include "GameManager.h"

void Gdata::Init()
{
	// 초기 세팅
	// 플레이어 데이터가 있으면 로드 가능
	// 없으면 로드 불가능
}

void Gdata::SaveGame()
{
	ofstream SaveData(_dataName);
	SaveData << pdata.GetName() << "\n";
	SaveData << pdata.GetHP() << "\n";
	SaveData << pdata.GetAttackPower() << "\n";
	SaveData << pdata.GetTalk() << "\n";
	SaveData << pdata.GetGold() << "\n";
	SaveData << GetYear() << "\n";
	SaveData << GetMonth() << "\n";
	SaveData << GetFloor();
	SaveData.close();
}

bool Gdata::LoadGame()
{
	ifstream LoadData;
	LoadData.open(_dataName);
	while (!LoadData.is_open())
	{
		return false;
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
	SetYear(str);

	getline(LoadData, str);
	SetMonth(str);

	getline(LoadData, str);
	SetFloor(str);

	pdata.SetNowHP(pdata.GetHP());

	LoadData.close();
	return true;
}


int Gdata::GetYear() { return _year; }
void Gdata::SetYear(int year) { _year = year; }
void Gdata::SetYear(string year) { _year = stoi(year); }

int Gdata::GetMonth() { return _month; }
void Gdata::SetMonth(int month) { _month = month; }
void Gdata::SetMonth(string month) { _month = stoi(month); }
void Gdata::UpdateMonth(int month) 
{
	if (_month + month > 12)
	{
		_year++;
		_month = 1;
	}
	else
	{
		_month += month; 
	}
	gdata.pdata.SetNowHP(gdata.pdata.GetHP()); // 한 달 지날때마다 회복
}

int Gdata::GetFloor() { return _floor; }
void Gdata::SetFloor(int floor) { _floor = floor; }
void Gdata::SetFloor(string floor) { _floor = stoi(floor); }
void Gdata::UpdateFloor(int floor) { _floor += floor; }

int Gdata::GetScene() { return _nowScene; }
void Gdata::ChangeSecene(int sceneNum)
{
	_nowScene = sceneNum;
	switch (_nowScene)
	{
	case 1:
		title.Init();
		break;
	case 2:
		inGame.Init();
		break;
	}
}