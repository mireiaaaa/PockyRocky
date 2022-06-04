#include "SceneDirector.h"
#include "InputManager.h"
//#include "Audio.h"
//#include "SoundManager.h"
#include "Video.h"
#include "ResourceManager.h"
//#include "Timer.h"
#include "Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include"SoundManager.h"
#include"Sound.h"

//#include "Highscore.h"

Uint32 				global_elapsed_time = 0;
bool				gameOn = true;
int					characterPicked = -1;

SceneDirector* sDirector = NULL;
InputManager* sInputControl = NULL;
Video* sVideo = NULL;
ResourceManager* sResourceManager = NULL;
Sound* sSound = NULL;
SoundManager* sSoundManager = NULL;

Camera* sCamera = NULL;


int main(int argc, char* argv[]) {

	srand(time(NULL));
	
	sCamera = Camera::getInstance();
	sResourceManager = ResourceManager::getInstance();
	sVideo = Video::getInstance();
	sSoundManager = SoundManager::getInstance();
	sSound = Sound::getInstance();
	sInputControl = InputManager::getInstance();
	
	sDirector = SceneDirector::getInstance();
	
	sSound->playAudio(0, sSoundManager->loadAndGetAudioID("mainTheme.ogg"), 1);
	
	//Main Loop
	// Init Time control
	//Timer* globalTimer = new Timer();
	//globalTimer->start();
	//Uint32 last_time = 0;
	sVideo->setRenderColor(8,64,8,255);
	while (gameOn) {
		//ReInit o no
		sVideo->clearScreen();
		if (sDirector->getCurrentScene()->mustReInit()) {
			sDirector->getCurrentScene()->reinit();
		}
		// Read controls
		sInputControl->update();

		//Update time
		/*Uint32 actualtime = globalTimer->getTicks();
		global_elapsed_time = actualtime - last_time;
		last_time = actualtime;
		*/
		// Updates scene
 		sDirector->getCurrentScene()->update();

		
			sDirector->getCurrentScene()->render();
			sVideo->updateScreen();
		
	}

	sVideo->close();
	sSound->close();
	return 0;
}