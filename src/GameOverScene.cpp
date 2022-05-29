
#include "GameOverScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


GameOverScene::~GameOverScene()
{
}

GameOverScene::GameOverScene()
{
}

void GameOverScene::init()
{


	_imgGameOver.init("GameOver.png");
	_imgGameOver.setSize(258, 226);
	_imgGameOver.setPositionXY(0, 0);

}

void GameOverScene::update()
{
}



void GameOverScene::render()
{
	_imgGameOver.render();



}

void GameOverScene::reinit()
{
}






