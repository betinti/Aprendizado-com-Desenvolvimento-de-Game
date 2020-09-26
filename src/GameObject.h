#pragma once

#include "ofMain.h";

/*
	Tipos:
		Ship -> 1
		Shot -> 2
		Alien ->3
*/

class GameManager;

class GameObject 
{
public:
	virtual void setup(float x, float y, int tipo) = 0;
	virtual void update(float s) = 0;
	virtual void draw() const = 0;
	virtual bool finished() const = 0;
	virtual ofRectangle getRect() const = 0;
	virtual void kill() = 0;
	virtual int getTipo() = 0;

	virtual void hit(const GameObject& other) = 0;

	virtual ~GameObject() {};
};
