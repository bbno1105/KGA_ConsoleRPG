#include "Scene.h"

int Scene::GetNowScene()
{
	return nowScene;
}

void Scene::Change(int scene)
{
	if(MIN < scene && scene< MAX)
	{
		nowScene = scene;
	}
}