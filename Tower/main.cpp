#include "GameManager.h"

#include <iostream>

int nowScene;

int main()
{


	title.Init();
	gdata.ChangeSecene(1);

	bool isGameOver = false;

	while (!isGameOver)
	{
		switch (gdata.GetScene())
		{
		case 1:
			title.Update();
			break;
		case 2:
			inGame.Update();
			break;
		case 3:
			isGameOver = true;
			break;
		}

		switch (gdata.GetScene())
		{
		case 1:
			title.Render();
			break;
		case 2:
			inGame.Render();
			break;
		case 3 :
			isGameOver = true;
			break;
		}
	}

	return 0;
}