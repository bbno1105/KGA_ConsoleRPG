#include "GameManager.h"

#include <iostream>

int main()
{
	gdata.LoadGame();

	std::cout << pdata.GetName();

	// gdata.SaveGame();

	return 0;
}