#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Pdata : public Character
{
private:
	
	// 플레이어 정보
	string _name = "";
	int _gold = 0;

	// 시간
	int _year = 0;
	int _month = 0;
	
	// 진행도
	int _floor = 0;

public :
	Pdata() = default;
	~Pdata() = default;

	// [ 플레이어 정보 ]
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	void SetHP(string HP) { _HP = stoi(HP); }
	
	void SetAttackPower(string attackPower) { _attackPower = stoi(attackPower); }
	
	void SetSpeed(string speed) { _speed = stoi(speed); }


	int GetGold() { return _gold; }
	void SetGold(int gold) { _gold = gold; }
	void SetGold(string gold) { _gold = stoi(gold); }

	int GetYear() { return _year; }
	void SetYear(int year) { _year = year; }
	void SetYear(string year) { _year = stoi(year); }

	int GetMonth() { return _month; }
	void SetMonth(int month) { _month = month; }
	void SetMonth(string month) { _month = stoi(month); }

	int GetFloor() { return _floor; }
	void SetFloor(int floor) { _floor = floor; }
	void SetFloor(string floor) { _floor = stoi(floor); }

	// [ 플레이어 행동 ]
	void Attack()
	{

	}
}pdata ;

