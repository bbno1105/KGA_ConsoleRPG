#pragma once

class Character
{
protected:
	int _HP = 0;
	int _attackPower = 0;
	int _speed = 0;

public :
	int GetHP() { return _HP; }
	void SetHP(int HP) { _HP = HP; }

	int GetAttackPower() { return _attackPower; }
	void SetAttackPower(int attackPower) { _attackPower = attackPower; }

	int GetSpeed() { return _speed; }
	void SetSpeed(int speed) { _speed = speed; }
};