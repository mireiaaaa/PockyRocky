#include "sdl.h"

class Timer
{
	Timer();
	SDL_Rect _windowRect;
	static Timer* unica_instancia;
	int _start;
public:
	~Timer();
	void Start();
	static Timer*getInstance()
	{
		if (unica_instancia == NULL)
			unica_instancia = new Timer();

		return unica_instancia;
	}
};