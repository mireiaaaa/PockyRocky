#include "Fantasmita.h"

Fantasmita::~Fantasmita()
{
}

Fantasmita::Fantasmita()
{
	frame = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;
}

void Fantasmita::init(const char* image)
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.y = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.w = 16; // RAFEL: Cambio valores para ejemplo con guybush
	SizeGfx.h = 24; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.h = SizeGfx.h; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.w = SizeGfx.w; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.x = 59; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	PositionRender.y = 133; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	//mudar variaveis pelas variaveis que tenho em video
	_dir = DOWN;

}

void Fantasmita::update()
{
	/*timeFrame += Video::getInstance()->getDeltaTime();
	if (timeFrame >= maxTimeFrame) {
		frame++;
		int maxf = 2;


		if (_estado == DOWN) {
			maxf = 1;
			if (frame > 1) frame = 0;

		}
		if (frame > maxf) frame = 0;
		timeFrame = 0;
	}*/
	PositionRender.y += 5;
	/*
	//zig-zag
	PositionRender.x +=2;
	PositionRender.x -= 2;
	*/
	//_estado = MOVE;
	_dir = DOWN;


	//si pocky esta proxima ir en su direccion

	switch (_dir)
	{
	case DOWN:
		// RAFEL2 : Crea su propio enum de estados
		//if (_estado == MOVE) {
		//	SizeGfx.x = 0;
		//	SizeGfx.y = (27 * 3) + (7 * 3);

		//	//colocar animacao
		//}
		break;
	// RAFEL2 : DEAD no esta en el enum de _dir
	//case DEAD:
	//	break;

	default:
		break;
	}
}

void Fantasmita::render()
{
	int animX = SizeGfx.x + SizeGfx.w * frame;

	Video::getInstance()->renderGraphic(IDGfx, SizeGfx.x, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x, PositionRender.y );
		//Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x , PositionRender.y , 1);
	
	
}

void Fantasmita::collider(int _dir)
{
}
