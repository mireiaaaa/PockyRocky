
#include "GameScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SceneDirector.h"
#include <iostream>
#include "Hud.h"
#include "SoundManager.h"
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


	HUD.setPos(&Player);
	Nopino.setPos(&Player);
	Nopino.setPos(&nopinoBala);
	Player.setPos(&Bala);


	


	Esquelety* EsqueVector;
	
	
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");


	
	

	
	Player.setPos(&Map);
	Nopino.setPos(&Map);


	sCamera->setPos(&Player);
	sCamera->setPos(&Map);
	





}

void GameScene::update()
{

	HUD.update();
	Player.update();
	
	for (size_t i = 0; i < Bala.size(); i++)
	{
		Bala[i]->update();
	}
	for (size_t i = 0; i < nopinoBala.size(); i++)
	{
		nopinoBala[i]->update();
	}
	
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

	bool quit = false;
	for (size_t i = 0; i < Ghost.size(); i++)
	{
		if (quit) {
			break;
		}
		if (Player.samePos(Ghost[i]->getCollision())) {

			if (Player.PockyEstado() != 4) {
				Player.isHurt();
			}
			else {
				Player.moreScore();
			}
			delete Ghost[i];


			Ghost.erase(Ghost.begin() + i);
			break;
		}
		for (size_t j = 0; j < Bala.size(); j++)
		{
   			if (Ghost[i]->samePos(Bala[j]->getCollision())) {
				
				Player.moreScore();
				delete Ghost[i];
				delete Bala[j];

				Ghost.erase(Ghost.begin() + i);
				Bala.erase(Bala.begin() + j);
				quit = true;
				break;
			}

		}
		


	}
	for (size_t j = 0; j < nopinoBala.size(); j++)
		{
			if (Player.samePos(nopinoBala[j]->getCollision())) {

				Player.isHurt();
				
				delete nopinoBala[j];

				
				nopinoBala.erase(nopinoBala.begin() + j);
				quit = true;
				break;
			}

		}
	//colision esque
	for (size_t i = 0; i < Esque.size(); i++)
	{
		if (quit) {
			break;
		}
		if (Player.samePos(Esque[i]->getCollision())) {

			if (Player.PockyEstado() != 4) {
				Player.isHurt();
			}
			else {
				Player.moreScore();
			}
			delete Esque[i];


			Esque.erase(Esque.begin() + i);
			break;
		}
		for (size_t j = 0; j < Bala.size(); j++)
		{
			if (Esque[i]->samePos(Bala[j]->getCollision())) {

				Player.moreScore();
				delete Esque[i];
				delete Bala[j];

				Esque.erase(Esque.begin() + i);
				Bala.erase(Bala.begin() + j);
				quit = true;
				break;
			}

		}


	}
	//collision Nopino
	if(Nopino.samePos(Player.getCollision())) {

		if (Player.PockyEstado() != 4) {
			Player.isHurt();
		}
		

	}
	for (size_t j = 0; j < Bala.size(); j++)
	{
		if (Nopino.samePos(Bala[j]->getCollision())) {


			Nopino.isHurt();
			Player.moreScore();
			delete Bala[j];

			
			Bala.erase(Bala.begin() + j);
			quit = true;
			break;
		}

	}
	//colision Umb
	for (size_t i = 0; i < Umb.size(); i++)
	{
		if (quit) {
			break;
		}
		if (Player.samePos(Umb[i]->getCollision())) {

			if (Player.PockyEstado() != 4) {
				Player.isHurt();
			}
			else {
				Player.moreScore();
			}
			delete Umb[i];


			Umb.erase(Umb.begin() + i);
			break;
		}
		for (size_t j = 0; j < Bala.size(); j++)
		{
			if (Umb[i]->samePos(Bala[j]->getCollision())) {

				Player.moreScore();
				delete Umb[i];
				delete Bala[j];

				Umb.erase(Umb.begin() + i);
				Bala.erase(Bala.begin() + j);
				quit = true;
				break;
			}

		}


	}
	if (Nopino.getDead() == true) {
		
		for (size_t i = 0; i < Ghost.size(); i++)
		{

			delete Ghost[i];


		}
		Ghost.resize(0);
		for (size_t i = 0; i < Umb.size(); i++)
		{

			delete Umb[i];


		}

		Umb.resize(0);
		for (size_t i = 0; i < Esque.size(); i++)
		{

			delete Esque[i];




		}
		Esque.resize(0);
		for (size_t i = 0; i < Bala.size(); i++)
		{

			delete Bala[i];


			Bala.erase(Bala.begin() + i);



		}
		Bala.resize(0);
		for (size_t i = 0; i < nopinoBala.size(); i++)
		{

			delete nopinoBala[i];


			nopinoBala.erase(nopinoBala.begin() + i);



		}
		nopinoBala.resize(0);
		sDirector->changeScene(YOUWIN, 1);
	
	}
	if (Player.getDead() == true) {
		for (size_t i = 0; i < Ghost.size(); i++)
		{
			
				delete Ghost[i];


		}
		Ghost.resize(0);
		for (size_t i = 0; i < Umb.size(); i++)
		{

			delete Umb[i];


		}

		Umb.resize(0);
		for (size_t i = 0; i < Esque.size(); i++)
		{

			delete Esque[i];




		}
		Esque.resize(0);
		for (size_t i = 0; i < Bala.size(); i++)
		{

			delete Bala[i];


			Bala.erase(Bala.begin() + i);



		}
		Bala.resize(0);
		for (size_t i = 0; i < nopinoBala.size(); i++)
		{

			delete nopinoBala[i];


			nopinoBala.erase(nopinoBala.begin() + i);



		}
		nopinoBala.resize(0);
		sDirector->changeScene(GAMEOVER, 1);
	}
}



void GameScene::render()
{
	
	
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
	for (size_t i = 0; i < nopinoBala.size(); i++)
	{
		nopinoBala[i]->render();

	}
	for (size_t i = 0; i < Umb.size(); i++){
		
			Umb[i]->render();
	}


	HUD.render();


}

void GameScene::reinit()
{
	mReinit = false;

	HUD.init();


	Player.init("pocky.png");


	Umby* UmbyVector;
	for (size_t i = 0; i < 4; i++) {
		UmbyVector = new Umby();
		UmbyVector->setPos(&Player);
		UmbyVector->setPos(&Map);

		if (i ==0) {
			UmbyVector->init("umby.png", 150, 320);
		}
		else if (i==1) {
			UmbyVector->init("umby.png", 100, 320);
		}
		else if (i == 2) {
			UmbyVector->init("umby.png", 180, 320);
		}
		//segunda fila
		else if (i==3) {
			UmbyVector->init("umby.png", 200, 320);
		}
		Umb.push_back(UmbyVector);



	}

	Esquelety* EsqueVector;
	for (size_t i = 0; i < 2; i++) {


		EsqueVector = new Esquelety();
		EsqueVector->setPos(&Player);
		EsqueVector->setPos(&Map);

		if (i==0) {
			EsqueVector->init("esquelety.png", 704, 296);
		}
		else if (i ==1) {
			EsqueVector->init("esquelety.png", 704, 396);
		}
		
		Esque.push_back(EsqueVector);
	}

	Fantasmita* GhostVector;
	for (size_t i = 0; i < 8; i++)
	{
		GhostVector = new Fantasmita();
		GhostVector->setPos(&Player);



		//6 fantasmitas juntos dos fileras
		//primera fila
		if (i == 0) {
			GhostVector->init("fantasmita.png", 100, 300);
		}
		else if (i == 1) {
			GhostVector->init("fantasmita.png", 80, 300);
		}
		else if (i == 2) {
			GhostVector->init("fantasmita.png", 60, 300);
		}
		//segunda fila
		else if (i == 3) {
			GhostVector->init("fantasmita.png", 100, 600);
		}
		else if (i == 4) {
			GhostVector->init("fantasmita.png", 80, 250);
		}
		else if (i == 5) {
			GhostVector->init("fantasmita.png", 60, 250);
		}

		//tres fantasmitas
		else if (i == 6) {
			GhostVector->init("fantasmita.png", 100, 100);
		}
		else if (i == 7) {
			GhostVector->init("fantasmita.png", 80, 100);
		}
		else if (i == 8) {
			GhostVector->init("fantasmita.png", 60, 100);
		}



		Ghost.push_back(GhostVector);


	}
	
	
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");




	sCamera->init();



}






