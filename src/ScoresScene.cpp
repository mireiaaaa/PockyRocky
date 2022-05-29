
#include "ScoresScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


ScoresScene::~ScoresScene()
{
}

ScoresScene::ScoresScene()
{
}

void ScoresScene::init()
{


	_imgScores.init("Scores.png");
	_imgScores.setSize(258, 226);
	_imgScores.setPositionXY(0, 0);

}

void ScoresScene::update()
{
}



void ScoresScene::render()
{
	_imgScores.render();



}

void ScoresScene::reinit()
{
}






