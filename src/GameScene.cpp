
#include "GameScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SceneDirector.h"
#include <iostream>

extern SceneDirector* sDirector;
extern InputManager* sInputControl;
//extern Audio* sAudio;
//extern AudioManager* sAudioManager;
extern Video* sVideo;
extern ResourceManager* sResourceManager;
extern Camera* sCamera;
//extern Highscore* sHighscore;

//extern Uint32           global_elapsed_time;

GameScene::~GameScene()
{
}

GameScene::GameScene()
{
}

void GameScene::init()
{
	
	SDL_Event test_event;

	//int pos=0;
	
	//const Uint8* state;
	Fantasmita* GhostVector;
	GhostVector = new Fantasmita;
	Ghost.push_back(GhostVector);
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->setPos(&Player);
	}

	Esque.setPos(&Player);
	Umb.setPos(&Player);
	Nopino.setPos(&Player);
	Player.setPos(&Bala);


	Player.init("pocky.png");
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->init("fantasmita.png");
	}
	Esque.init("esquelety.png");
	Umb.init("umby.png");
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");

	Player.setPos(&Map);
	Esque.setPos(&Map);
	Umb.setPos(&Map);
	Nopino.setPos(&Map);


	sCamera->setPos(&Player);
	sCamera->setPos(&Map);
	sCamera->init();





}

void GameScene::update()
{

	
	
	for (size_t i = 0; i < Bala.size(); i++)
	{
		Bala[i]->update();
	}
	Player.update();
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->update();
	}
	Esque.update();
	Umb.update();
	Nopino.update();
	sCamera->update();
	Map.update();

	for (size_t i = 0; i < Ghost.size(); i++)
		{
			
			if (Player.samePos(Ghost[i]->getCollision())) {
			Player.isHurt();
			delete Ghost[i];
		

			Ghost.erase(Ghost.begin() + i);
		}
	}
	
}



void GameScene::render()
{
	

	Map.render();
	Esque.render();
	Player.render();
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->render();
	}
	Nopino.render();
	for (size_t i = 0; i < Bala.size(); i++)
	{
		Bala[i]->render();

	}
	Umb.render();


	


}

void GameScene::reinit()
{
}






