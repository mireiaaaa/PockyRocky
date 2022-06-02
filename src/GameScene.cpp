
#include "GameScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SceneDirector.h"
#include <iostream>
#include "Hud.h"
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
	HUD.init();
	

	Esquelety* EsqueVector;
	EsqueVector = new Esquelety;
	Esque.push_back(EsqueVector);

	Umby* UmbyVector;
	UmbyVector = new Umby;
	Umb.push_back(UmbyVector);
		


	for (size_t i = 0; i < Umb.size(); i++)
	{
		Umb[i]->setPos(&Player);
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->setPos(&Player);
	}

	Nopino.setPos(&Player);
	Player.setPos(&Bala);


	Player.init("pocky.png");




	Fantasmita* GhostVector;
	for (size_t i = 0; i < 18; i++)
	{
		GhostVector = new Fantasmita;
		GhostVector->setPos(&Player);


		//6 fantasmitas juntos dos fileras
		//primera fila
		if(i >= 1 && i <= 2){
			GhostVector->init("fantasmita.png", 100,300);
		}
		else if(i>=3&&i<=4){
			GhostVector->init("fantasmita.png", 80, 300);
		}
		else if (i >= 5 && i <= 6) {
			GhostVector->init("fantasmita.png", 60, 300);
		}
		//segunda fila
		else if (i >= 7 && i <= 8) {
			GhostVector->init("fantasmita.png", 100, 250);
		}
		else if (i >= 9 && i <= 10) {
			GhostVector->init("fantasmita.png", 80, 250);
		}
		else if (i >= 11 && i <= 12) {
			GhostVector->init("fantasmita.png", 60, 250);
		}

		//tres fantasmitas
		else if (i >= 13 && i <= 14) {
			GhostVector->init("fantasmita.png", 100, 100);
		}
		else if (i >= 15 && i <= 16) {
			GhostVector->init("fantasmita.png", 80, 100);
		}
		else if (i >= 17 && i <= 18) {
			GhostVector->init("fantasmita.png", 60, 100);
		}


	
		Ghost.push_back(GhostVector);
		
	
	}
	for(size_t i = 0; i < Umb.size(); i++){
		Umb[i]->init("umby.png");
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->init("esquelety.png");
	}
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");


	
	




	for (size_t i = 0; i < Umb.size(); i++) {
		Umb[i]->setPos(&Map);
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->setPos(&Map);
	}
	Player.setPos(&Map);
	Nopino.setPos(&Map);


	sCamera->setPos(&Player);
	sCamera->setPos(&Map);
	sCamera->init();





}

void GameScene::update()
{

	HUD.update();
	
	for (size_t i = 0; i < Bala.size(); i++)
	{
		Bala[i]->update();
	}
	Player.update();
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->update();
	}
	for (size_t i = 0; i < Umb.size(); i++){
		Umb[i]->update();
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->update();
	}
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


			//NAO FUNCIONA MT BEM N SEI PQ
			/*
			if (Player.samePos(Ghost[i]->getCollision())&& Personaje::ST_IDLE&& Player.getDir()==UP ) {
				delete Ghost[i];
				Ghost.erase(Ghost.begin() + i);
			}*/
			
	}
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		for (size_t j = 0; j < Bala.size(); j++)
		{

		if (Player.samePos(Ghost[i]->getCollision())) {

			Player.isHurt();
			delete Ghost[i];


			Ghost.erase(Ghost.begin() + i);
		}
		if (Bala[j]->samePos(Ghost[i]->getCollision())+0.1) {

			Player.moreScore();
			delete Ghost[i];
			delete Bala[j];


			Ghost.erase(Ghost.begin() + i);
			Bala.erase(Bala.begin() + i);
		}

		}


		//NAO FUNCIONA MT BEM N SEI PQ
		/*
		if (Player.samePos(Ghost[i]->getCollision())&& Personaje::ST_IDLE&& Player.getDir()==UP ) {
			delete Ghost[i];
			Ghost.erase(Ghost.begin() + i);
		}*/

	}
}



void GameScene::render()
{
	
	HUD.render();
	Map.render();
	Player.render();
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->render();
	}
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		Ghost[i]->render();
	}
	Nopino.render();
	for (size_t i = 0; i < Bala.size(); i++)
	{
		Bala[i]->render();

	}
	for (size_t i = 0; i < Umb.size(); i++){
		
			Umb[i]->render();
	}


	


}

void GameScene::reinit()
{
}






