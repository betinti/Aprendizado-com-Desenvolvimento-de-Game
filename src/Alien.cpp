#include "Alien.h"
#include "ofMain.h"

Alien::Alien() : AbstractGO("enemy.png")
{
}

void Alien::hit(const GameObject& other) {
	kill();
}

void Alien::update(float s) 
{
	if (xDirection)
	{
		this->x = x + speed * s;
		xCont++;
		if (xCont == xRange) xDirection = false;
	}
	else
	{
		this->y = y + 0.25;

		this->x = x - speed * s;
		xCont--;
		if (xCont == 0) xDirection = true;
	}
}