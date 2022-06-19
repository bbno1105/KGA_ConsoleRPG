#pragma once

class Character
{
protected:
	int _HP = 0;
	int _nowHP = 0;
	int _attackPower = 0;
	int _talk = 0;

public :
	int GetHP() { return _HP; }
	void SetHP(int HP) { _HP = HP; }
	void UpdateHP(int HP) { _HP += HP; }

	int GetNowHP() { return _nowHP; }
	void SetNowHP(int HP) { _nowHP = HP; }
	bool UpdateNowHP(int HP)
	{
		_nowHP += HP;
		if (_nowHP <= 0)
		{
			_nowHP = _HP; // HP È¸º¹
			return false; // »ç¸Á
		}
		return true;
	}

	int GetAttackPower() { return _attackPower; }
	void SetAttackPower(int attackPower) { _attackPower = attackPower; }
	void UpdateAttackPower(int attackPower)
	{
		_attackPower += attackPower;
		if (_attackPower < 0) _attackPower = 0;
	}

	int GetTalk() { return _talk; }
	void SetTalk(int talk) { _talk = talk; }
	void UpdateTalk(int talk)
	{
		_talk += talk;
		if (_talk < 0) _talk = 0;
	}
};