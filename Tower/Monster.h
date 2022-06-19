#pragma once
#include "Common.h"
#include "Character.h"

class Monster : public Character
{
	int _resultGold;

public :
	Monster() = default;
	~Monster() = default;

	int GetResult() { return _resultGold; }
	 
	void Set(int HP, int atk, int result)
	{
		_HP = HP;
		_attackPower = atk;
		_resultGold = result;
		_nowHP = _HP;
	}
};