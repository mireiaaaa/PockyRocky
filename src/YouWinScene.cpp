
#include "YouWinScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


YouWinScene::~YouWinScene()
{
}

YouWinScene::YouWinScene()
{
}

void YouWinScene::init()
{


	_imgYouWin.init("YouWin.png");
	_imgYouWin.setSize(258, 226);
	_imgYouWin.setPositionXY(0, 0);

}

void YouWinScene::update()
{
}



void YouWinScene::render()
{
	_imgYouWin.render();



}

void YouWinScene::reinit()
{
}






