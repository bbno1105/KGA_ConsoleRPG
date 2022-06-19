#pragma once
#include "Common.h"

#include "Title.h"
#include "InGame.h"

enum sceneType
{
	MIN,
	TITLE,
	INGAME,
	MAX
};

class Scene
{
private :
	int nowScene = 0;

public :
	int GetNowScene();
	void Change(int scene);

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

};

