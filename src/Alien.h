#pragma once

#include "AbstractGO.h";

class Alien : public AbstractGO
{
private:
	int xRange = 40;
	int speed = 30;
	bool xDirection = true;
	int xCont = 0;

public:
	Alien();
	virtual void hit(const GameObject& other) override;
	void update(float s);
};

