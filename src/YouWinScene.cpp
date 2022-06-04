
#include "YouWinScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>
#include "SceneDirector.h"

extern InputManager* sInputControl;
extern SceneDirector* sDirector;

YouWinScene::~YouWinScene()
{
}

YouWinScene::YouWinScene()
{
}

void YouWinScene::init()
{


	_imgYouWin.init("win.png");
	_imgYouWin.setSize(258, 226);
	_imgYouWin.setPositionXY(0, 0);

}

void YouWinScene::update()
{
	if (sInputControl->getAtaque()) {
		sDirector->changeScene(MENU, 1);
	}
}



void YouWinScene::render()
{
	_imgYouWin.render();



}

void YouWinScene::reinit()
{
}






