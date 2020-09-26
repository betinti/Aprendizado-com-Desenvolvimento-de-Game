#include "Ship.h"
#include "GameManager.h"

Ship::Ship() : AbstractGO("jogador.png")
{
}

void Ship::update(float s)
{
	//Move
	float speed = 0;
	if (x >= 100 && ofGetKeyPressed('a'))
	{
		speed = -300;
	}
	else if (x < 900 && ofGetKeyPressed('d'))
	{
		speed = 300;
	}
	x += speed * s;

	//Tiro
	interval += s;
	if (ofGetKeyPressed(' ') && interval > 0.3)
	{
		interval = 0;
		Shot* shot = new Shot();
		shot->setup(x, y, 2);
		MANAGER.add(shot);
	}
}