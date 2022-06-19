#pragma once

class Character
{
protected:
	int _HP = 0;
	int _nowHP = 0;
	int _attackPower = 0;
	int _speed = 0;

public :
	int GetHP() { return _HP; }
	void SetHP(int HP) { _HP = HP; }
	void UpdateHP(int HP) { _HP += HP; }

	int GetNowHP() { return _nowHP; }
	void UpdateNowHP(int HP)
	{
		_nowHP += HP;
		if (_nowHP < 0)
		{
			// »ç¸Á
			_nowHP = 0;
		}
	}

	int GetAttackPower() { return _attackPower; }
	void SetAttackPower(int attackPower) { _attackPower = attackPower; }
	void UpdateAttackPower(int attackPower)
	{
		_attackPower += attackPower;
		if (_attackPower < 0) _attackPower = 0;
	}

	int GetSpeed() { return _speed; }
	void SetSpeed(int speed) { _speed = speed; }
	void UpdateSpeed(int speed)
	{
		_speed += speed;
		if (_speed < 0) _speed = 0;
	}
};