
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

	switch (_img)
	{
	case Hud::PONTUACIONCERO:
		_pontuacionCero.init("pontuacionCero.png");
		_pontuacionCero.setSize(258, 226);
		_pontuacionCero.setPositionXY(0, 0);
		break;
	case Hud::PONTUACIONNUM:
		_pontuacionNum.init("pontuacionNum.png");
		_pontuacionNum.setSize(258, 226);
		_pontuacionNum.setPositionXY(0, 0);
		break;
	case Hud::CORAZON:
		_corazon.init("heart.png");
		
		_corazon.setSize(256, 224);
		_corazon.setPositionXY(300, 202);

		break;
	case Hud::ICONO:
		_icono.init("icono.png");
		
		_icono.setSize(16, 16);
		_icono.setPositionXY(245, 202);
		break;
		
	default:
		break;
	}
	

	
	
	
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



void Hud::render()
{
	//_imgGameOver.render();
	int animX = SizeGfx.x + SizeGfx.w * frame;
	_pontuacionCero.renderFrame(animX);
	_pontuacionNum.renderFrame(animX);
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






