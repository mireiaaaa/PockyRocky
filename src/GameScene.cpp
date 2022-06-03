
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
	HUD.setPos(&Player);
	//HUD.init();


	

	/*Umby* UmbyVector;
	UmbyVector = new Umby;
	Umb.push_back(UmbyVector);*/
		
	/*

	for (size_t i = 0; i < Umb.size(); i++)
	{
		Umb[i]->setPos(&Player);
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->setPos(&Player);
	}
*/
	Nopino.setPos(&Player);
	Player.setPos(&Bala);


	//Player.init("pocky.png");


	Esquelety* EsqueVector;
	/*
	for (size_t i = 0; i < 4; i++) {	


		EsqueVector = new Esquelety;
		EsqueVector->setPos(&Player);

		if (i >= 1 && i <= 2) {
			EsqueVector->init("esquelety.png", 300, 300);
		}
		else if (i >= 3 && i <= 4) {
			EsqueVector->init("esquelety.png", 300, 300);
		}
		else if (i >= 5 && i <= 6) {
			EsqueVector->init("esquelety.png", 300, 300);
		}
		//segunda fila
		else if (i >= 7 && i <= 8) {
			EsqueVector->init("esquelety.png", 300, 600);
		}
		Esque.push_back(EsqueVector);
	}

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
			GhostVector->init("fantasmita.png", 100, 600);
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
		
	
	}*/
	/*
	for(size_t i = 0; i < Umb.size(); i++){
		Umb[i]->init("umby.png");
	}*/
	
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");


	
	

	/*


	for (size_t i = 0; i < Umb.size(); i++) {
		Umb[i]->setPos(&Map);
	}
	for (size_t i = 0; i < Esque.size(); i++)
	{
		Esque[i]->setPos(&Map);
	}*/
	Player.setPos(&Map);
	Nopino.setPos(&Map);


	sCamera->setPos(&Player);
	sCamera->setPos(&Map);
	//sCamera->init();





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
		if (Player.samePos(Ghost[i]->getCollision())) {

      		Player.isHurt();
			delete Ghost[i];


			Ghost.erase(Ghost.begin() + i);
			continue;
		}
		for (size_t j = 0; j < Bala.size(); j++)
		{

		

 		if (Ghost[i]->samePos(Bala[j]->getCollision())) {

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
	if (Player.getHP() <= 0) {
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
	for (size_t i = 0; i < Umb.size(); i++){
		
			Umb[i]->render();
	}


	HUD.render();


}

void GameScene::reinit()
{
	mReinit = false;

	HUD.init();


	
	Umby* UmbyVector;
	UmbyVector = new Umby;
	Umb.push_back(UmbyVector);



	for (size_t i = 0; i < Umb.size(); i++)
	{
		Umb[i]->setPos(&Player);
	}
	

	


	Player.init("pocky.png");


	Esquelety* EsqueVector;
	for (size_t i = 0; i < 4; i++) {


		EsqueVector = new Esquelety;
		EsqueVector->setPos(&Player);

		if (i >= 1 && i <= 2) {
			EsqueVector->init("esquelety.png", 300, 300);
		}
		else if (i >= 3 && i <= 4) {
			EsqueVector->init("esquelety.png", 350, 300);
		}
		else if (i >= 5 && i <= 6) {
			EsqueVector->init("esquelety.png", 300, 300);
		}
		//segunda fila
		else if (i >= 7 && i <= 8) {
			EsqueVector->init("esquelety.png", 300, 600);
		}
		Esque.push_back(EsqueVector);
	}

	Fantasmita* GhostVector;
	for (size_t i = 0; i < 8; i++)
	{
		GhostVector = new Fantasmita;
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
	for (size_t i = 0; i < Umb.size(); i++) {
		Umb[i]->init("umby.png");
	}
	
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");








	for (size_t i = 0; i < Umb.size(); i++) {
		Umb[i]->setPos(&Map);
	}
	



	sCamera->init();



}






