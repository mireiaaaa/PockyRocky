#include "MenuScene.h"
#include "MenuScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>

extern Camera* sCamera;
MenuScene::~MenuScene()
{
}

MenuScene::MenuScene()
{	
}

void MenuScene::init()
{
	

	_imgMenu.init("menu.png");
	_imgMenu.setSize(258,226);
	_imgMenu.setPositionXY(0, 0);

}

void MenuScene::update()
{
}



void MenuScene::render()
{
	_imgMenu.render();



}

void MenuScene::reinit()
{
}






