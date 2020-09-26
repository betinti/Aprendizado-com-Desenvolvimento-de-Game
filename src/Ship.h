#pragma once

#include "Shot.h"

class Ship : public AbstractGO
{
private:
	float interval = 0;

public:
	Ship();
	void update(float s);
};

