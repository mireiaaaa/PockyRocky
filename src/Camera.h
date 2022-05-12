#pragma once
#include "Personaje.h"
#include "Mapa.h"

class Camera
{
	static Camera* unica_instancia;
	Mapa* _instanceNivel;
	Personaje* _instancePocky;


	int _positionMap;

	int _CY;//coordenada y da camera
	int _CX;//coordenada x da camera
	int _CW;//anchura de la camera
	int _CH;//altura de la camera


public:
	Camera();
	~Camera();

	void setPos(Personaje* _pocky) { _instancePocky = _pocky; };
	void setPos(Mapa* _nivel) { _instanceNivel = _nivel; };


	int getX() { return _CX; };
	int getY() { return _CY; };
	
	void init();
	void update();

	static Camera* getInstance()
	{
		if (unica_instancia == nullptr)
			unica_instancia = new Camera();

		return unica_instancia;
	}
};

