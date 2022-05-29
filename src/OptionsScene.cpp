
#include "OptionsScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


OptionsScene::~OptionsScene()
{
}

OptionsScene::OptionsScene()
{
}

void OptionsScene::init()
{


	_imgOptions.init("options.png");
	_imgOptions.setSize(258, 226);
	_imgOptions.setPositionXY(0, 0);

}

void OptionsScene::update()
{
}



void OptionsScene::render()
{
	_imgOptions.render();



}

void OptionsScene::reinit()
{
}






