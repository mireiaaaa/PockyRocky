
#include "MenuScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SceneDirector.h"
#include <iostream>

extern InputManager* sInputControl;
extern SceneDirector* sDirector;
extern Camera* sCamera;
MenuScene::~MenuScene()
{
}

MenuScene::MenuScene()
{	
}

void MenuScene::init()
{
	_cont = 0;
	//arrow
	_arrowPos = 0;
	_arrow.init("arrow.png");
	_arrow.setSize(16,16);
	_arrow.setPositionXY(16, 170);
	
	_imgMenu.init("menu.png");
	_imgMenu.setSize(258,226);
	_imgMenu.setPositionXY(0, 0);

}

void MenuScene::update()
{
	_cont++;
	if (_cont > 5) {
		_cont = 0;
		if (sInputControl->getRight()) {
			_arrowPos++;
			if (_arrowPos > 2) {
				_arrowPos = 2;
			}
		}
		if (sInputControl->getLeft()) {
			_arrowPos--;
			if (_arrowPos < 0) {
				_arrowPos = 0;
			}
		}
		switch (_arrowPos)
		{
		case 0:
			_arrow.setPositionXY(16, 170);
			break;
		case 1:
			_arrow.setPositionXY(84, 170);
			break;
		case 2:
			_arrow.setPositionXY(158, 170);
			break;
		default:
			break;
		}
	}
	if (!sInputControl->getAtaque()) {
		switch (_arrowPos)
		{
		case 0:
			sDirector->changeScene(GAME,1);

			break;
		case 1:
			sDirector->changeScene(SCORES, 1);
			break;
		case 2:
			sDirector->changeScene(OPTIONS, 1);
			break;
		default:
			break;
		}
	}
	
}



void MenuScene::render()
{
	_imgMenu.render();
	_arrow.render();


}

void MenuScene::reinit()
{
}






