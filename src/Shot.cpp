#include "Shot.h"
#include "Alien.h";

Shot::Shot() : AbstractGO("bullet.png")
{
}

void Shot::update(float s)
{
	this->y -= 500.0f * s;

}

void Shot::hit(const GameObject& other)
{
	const Alien* alien = dynamic_cast<const Alien*>(&other);
	if (alien)
	{
		kill();
	}
}

bool Shot::finished() const
{
	if (dead)
	{
		return dead;
	}
	else 
	{
		return y < 0;
	}
}