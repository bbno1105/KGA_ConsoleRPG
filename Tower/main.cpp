#include "GameManager.h"
#include "Scene.h"

#include <iostream>

int nowScene;


int main()
{
	InGame inGame;

	inGame.Init();

	while (true)
	{
		switch (2)
		{
		case TITLE:

			break;
		case INGAME:
			inGame.Update();
			inGame.Render();
			break;
		}
	}

	return 0;
}