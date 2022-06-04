#include "Mapa.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "tinyxml2.h"
#include "Camera.h"
#include "Defines.h"

extern Camera* sCamera;
extern SDL_Renderer* gRenderer;

Mapa::Mapa()
{
	 ID=0;
	 CellX=0, CellY=0;

	 tileSP=0;
	 tileH=0;
	 tileW=0;


	 offsetX=0;
	 offsetY=0;
	 tam=0;
}

Mapa::~Mapa()
{
}

void Mapa::init(const char* image)
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	tileSP = 1;
	tileH = 32;
	tileW = 32;
	
	//nomear os elementos
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("scroll_pocky.tmx") != tinyxml2::XML_SUCCESS) {
		cout << "Error XML: " << doc.ErrorStr();
	}

	tinyxml2::XMLElement* mapa = doc.FirstChildElement();
	tinyxml2::XMLElement* tileset = mapa->FirstChildElement();
	tinyxml2::XMLElement* BackgroundLayer = tileset->NextSiblingElement();
	tinyxml2::XMLElement* ForegroundLayer = mapa->LastChildElement();
	tinyxml2::XMLElement* BackgroundData = BackgroundLayer->FirstChildElement();
	tinyxml2::XMLElement* ForegroundData = ForegroundLayer->FirstChildElement();



	Background = BackgroundData->GetText();
	Foreground = ForegroundData->GetText();



	for (int z = 0; z < 30; z++) {
		for (int x = 0; x < 64; x++) {
			
			tam = Background.find_first_of(",");
			text=Background.substr(0,tam);
			Background= Background.substr(tam+1);

			_background[z][x] = std::stoi(text);
			cout << _background[z][x] << endl;


			
			tam2 = Foreground.find_first_of(",");
			text2 = Foreground.substr(0, tam2);
			Foreground = Foreground.substr(tam2 + 1);

			_foreground[z][x] = std::stoi(text2);
			
		}


	}
	SizeGfx.w = tileW * 64;
	SizeGfx.h = tileH * 30;

}

void Mapa::update()
{
	_firstTileX = sCamera->getX() / tileW;
	_firstTileY = sCamera->getY() / tileH;
	_totalTilesPintadosX = (SCREEN_WIDTH / tileW) + _firstTileX + 1;
	_totalTilesPintadosY = (SCREEN_HEIGHT / tileH) + _firstTileY + 1;

	if (_totalTilesPintadosX > 64) {
		_totalTilesPintadosX = 64;
	}
	if (_totalTilesPintadosY > 30) {
		_totalTilesPintadosY = 30;
	}
}


void Mapa::render()
{

	for (int i = _firstTileY; i < _totalTilesPintadosY; i++) {//tmY
		for (int j = _firstTileX; j < _totalTilesPintadosX;j++) {//tmX
			rectT.x = j * tileW - sCamera->getX();
			rectT.y = i * tileH - sCamera->getY();
			rectT.w = tileW;
			rectT.h = tileH;

			int IDTile = _background[i][j] - 1;


			if (IDTile >= 0) {
				CellX = IDTile % 7;//tmY
				CellY = IDTile / 7;//tmX
				rectS.x = CellX * tileW + tileSP * CellX;
				rectS.y = CellY * tileW + tileSP * CellY;
				rectS.w = tileW;
				rectS.h = tileH;
				Video::getInstance()->renderGraphic(IDGfx, rectS.x, rectS.y, rectS.w, rectS.h, rectT.x, rectT.y);
				
			}

			//foreground
			IDTile = _foreground[i][j] - 1;


			if (IDTile >= 0) {
				CellX = IDTile % 7;//tmY
				CellY = IDTile / 7;//tmX
				rectS.x = CellX * tileW + tileSP * CellX;
				rectS.y = CellY * tileW + tileSP * CellY;
				rectS.w = tileW;
				rectS.h = tileH;
				Video::getInstance()->renderGraphic(IDGfx, rectS.x, rectS.y, rectS.w, rectS.h, rectT.x, rectT.y);

			}
		}
	}
}

bool Mapa::getIDfromLayer(int PosX, int PosY)
{
	int _tileX = PosX / tileW;
	int _tileY = PosY / tileH;
	
 	if (_background[_tileY][_tileX] != 17 && _background[_tileY][_tileX] != 18 && _background[_tileY][_tileX] != 19 && _background[_tileY][_tileX] != 24 && _background[_tileY][_tileX] != 25 && _background[_tileY][_tileX] != 26) {
		return false;
	}
	return true;
}

