#pragma once
#include "Principal.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Mapa:public Principal
{


	MyRectangle rectS, rectT;
	int ID;
	int CellX, CellY;

	int tileSP;
	int tileH;
	int tileW;
	int _background[30][64];
	int _foreground[30][64];

	int offsetX;
	int offsetY;


	int _firstTileX;//primero tile que se pintara x
	int _firstTileY;//primero tile que se pintara y


	int _totalTilesPintadosX;//tiles que se van a pintar 
	int _totalTilesPintadosY;//tiles que se van a pintar 



	int tam;
	string text;
	int tam2;
	string text2;
	string Background;
	string Foreground;

public: 

	Mapa();
	~Mapa();
	void init(const char* image);
	void update();
	void render();
	bool getIDfromLayer(int PosX, int PosY);
	
};

