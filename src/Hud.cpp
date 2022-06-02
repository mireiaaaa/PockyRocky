
#include "Hud.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


Hud::~Hud()
{
}

Hud::Hud()
{
	frame = 0;
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;


}

void Hud::init()
{
	_mScore = _instancePersonaje->getScore();

	
    IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "pontuacionNum.png");
    IDHeart = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "heart.png");
    

    _corazon.setSize(256, 224);
    _corazon.setPositionXY(300, 202);
    
    _icono.init("icono.png");
    _icono.setSize(16, 16);
    _icono.setPositionXY(17, 202);

}

void Hud::update()
{
	switch (_img)
	{
	case Hud::PONTUACIONCERO:
		pontuacionCero();
		break;
	case Hud::PONTUACIONNUM:
		pontuacionNum();
		break;
	case Hud::CORAZON:
		corazon();
		break;
	case Hud::ICONO:
		icono();
		break;

	default:
		break;
	}

}

void Hud::ShowScore(int posY, int posX, int _score)
{
	int offset = 0;
	int numero = 0;
	int nScore = _score;

	
     offset = 9* 4;
     numero = 0;
     
     Video::getInstance()->renderGraphic(IDGfx,0, 9*numero, 9, 9, posX+offset,posY);
		
	
	numero = nScore % 100;
	if (numero != 0) {
		numero = numero / 10;
	}
	offset = 9* 3;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);
	numero = nScore % 1000;
	if (numero != 0) {
		numero = numero / 100;
	}
	offset = 9* 2;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);

	numero = nScore % 10000;
	if (numero != 0) {
		numero = numero / 1000;
	}
	offset = 9* 1;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);

	numero = nScore % 100000;
	if (numero != 0) {
		numero = numero / 10000;
	}
	offset = 9 * 0;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);


}

void Hud::ShowLife(int posY, int posX, int _HP)
{
	switch (_HP)
	{
	case 1:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		break;
	case 2:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		break;
	case 3:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		break;
	case 4:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		break;
	case 5:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		break;
	case 6:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 5, posY);
		break;
	case 7:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 5, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 6, posY);
		break;
	case 8:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 5, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 6, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 7, posY);
		break;
	case 9:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 5, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 6, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 7, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 8, posY);

		break;
	case 10:
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 0, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 1, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 2, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 3, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 4, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 5, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 6, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 7, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 8, posY);
		Video::getInstance()->renderGraphic(IDHeart, 0, 0, 16, 16, posX + 16 * 9, posY);
		break;
	default:
		break;
	}
}

void Hud::render()
{
	ShowScore(0, 0, _instancePersonaje->getScore());
	ShowLife(20, 20, _instancePersonaje->getHP());
	//_imgGameOver.render();
	int animX = SizeGfx.x + SizeGfx.w * frame;
	//_pontuacionCero.renderFrame(animX);
	//_pontuacionNum.renderFrame(animX);
	_corazon.renderFrame(animX);
	_icono.render();

}

void Hud::reinit()
{
}

void Hud::pontuacionCero()
{

}

void Hud::pontuacionNum()
{
}

void Hud::corazon()
{
}

void Hud::icono()
{
}






