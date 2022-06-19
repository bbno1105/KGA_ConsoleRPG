#pragma once
#include "Common.h"
#include "Character.h"

using namespace std;

class Pdata : public Character
{
private:
	
	// 플레이어 정보
	string _name = "";
	int _gold = 0;

public :
	Pdata() = default;
	~Pdata() = default;

	// [ 캐릭터 정보 ]
	void SetHP(string HP);
	
	void SetAttackPower(string attackPower);
	
	void SetSpeed(string speed);

	// [ 플레이어 정보 ]
	string GetName();
	void SetName(string name);

	int GetGold();
	void SetGold(int gold);
	void SetGold(string gold);
	bool UpdateGold(int gold);

	// [ 플레이어 행동 ]
	void Attack();

};
