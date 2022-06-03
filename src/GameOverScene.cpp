
#include "GameOverScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "Camera.h"
#include <iostream>

extern InputManager* sInputControl;
extern SceneDirector* sDirector;

GameOverScene::~GameOverScene()
{
}

GameOverScene::GameOverScene()
{
}

void GameOverScene::init()
{


	_imgGameOver.init("lose.png");
	_imgGameOver.setSize(258, 226);
	_imgGameOver.setPositionXY(0, 0);

}

void GameOverScene::update()
{



	if(sInputControl->getEnter()){
			sDirector->changeScene(MENU, 1);
	}

}



void GameOverScene::render()
{
	_imgGameOver.render();



}

void GameOverScene::reinit()
{
}






