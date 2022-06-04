#include "Camera.h"
#include "Defines.h"
Camera* Camera::unica_instancia = nullptr;
Camera::Camera()
{
	_CX = 0;
	_CY = 0;

	
}

Camera::~Camera()
{
}

void Camera::init()
{
	_CX = (_instancePocky->getPositionX() + (_instancePocky->getSizeWidth() / 2)) - (SCREEN_WIDTH / 2);
	_CY = (_instancePocky->getPositionY() + (_instancePocky->getSizeHeight() / 2)) - (SCREEN_HEIGHT/ 2);
	//se _CX>do de mede o mapa entao CX=o que o mapa mede(mesmo com _CY mas com _CY=0)
	
}

void Camera::update()
{
	_CX = (_instancePocky->getPositionX() + (_instancePocky->getSizeWidth() / 2)) - (SCREEN_WIDTH / 2);
	_CY = (_instancePocky->getPositionY() + (_instancePocky->getSizeHeight() / 2)) - (SCREEN_HEIGHT / 2);

	if(_CX> _instanceNivel->getSizeWidth()){
		_CX= _instanceNivel->getSizeWidth();
	}
	if (_CY <0) {
		_CY = 0;
	}
}
