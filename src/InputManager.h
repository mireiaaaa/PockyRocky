#pragma once
#include "sdl.h"
class InputManager
{
	private:
	InputManager();
	static InputManager* unica_instancia;
	SDL_Event test_event;

	bool right;
	bool left;
	bool up; 
	bool down;
	bool _ataque;
	bool _parado;
	bool _protect;
	bool _slide;
	bool _special;
public:
	
	~InputManager();
	void update();
	bool getRight();
	bool getLeft();
	bool getDown();
	bool getUp();
	bool getAtaque();
	bool getParado();
	bool getProtect();
	bool getSlide();
	bool getSpecial();


	static InputManager* getInstance()
	{
		if (unica_instancia == NULL)
			unica_instancia = new InputManager();

		return unica_instancia;
	}
	
};

