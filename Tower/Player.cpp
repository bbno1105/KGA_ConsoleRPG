#include "Player.h"

void Pdata::SetHP(string HP) { _HP = stoi(HP); }

void Pdata::SetAttackPower(string attackPower) { _attackPower = stoi(attackPower); }

void Pdata::SetSpeed(string speed) { _speed = stoi(speed); }

// [ 플레이어 정보 ]
string Pdata::GetName() { return _name; }
void Pdata::SetName(string name) { _name = name; }

int Pdata::GetGold() { return _gold; }
void Pdata::SetGold(int gold) { _gold = gold; }
void Pdata::SetGold(string gold) { _gold = stoi(gold); }
bool Pdata::UpdateGold(int gold)
{
	if (_gold + gold >= 0)
	{
		_gold += gold;
		return true;
	}
	else 
	{
		return false; // 돈을 갱신할 수 없다 (돈이 부족할 경우)
	}

}


// [ 플레이어 행동 ]
void Pdata::Attack()
{

}