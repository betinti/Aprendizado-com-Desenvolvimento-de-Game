#include "AbstractGO.h"

AbstractGO::AbstractGO(const string& imgName)
	: imgName(imgName), dead(false)
{
}

void AbstractGO::setup(float x, float y, int tipo)
{
	this->x = x;
	this->y = y;
	this->tipo = tipo;

	this->imgH = 90;
	this->imgW = 90;
	
	img.load(imgName);
	img.setAnchorPercent(0.5f, 0.5f);
	img.resize(imgW, imgH);
}

void AbstractGO::update(float s)
{
}

void AbstractGO::draw() const
{
	ofSetColor(255, 255, 255, 255);
	//ofDrawRectangle(this->getRect());
	img.draw(x, y);
}

bool AbstractGO::finished() const
{
	return dead;
}

void AbstractGO::kill()
{
	dead = true;
}

ofRectangle AbstractGO::getRect() const
{
	float hw = img.getWidth() / 2.0f;
	float hh = img.getHeight() / 2.0f;

	ofRectangle rect(x - hw, y - hh, imgW, imgH);
	return rect;
}

int AbstractGO::getTipo() {
	return this->tipo;
}

void AbstractGO::hit(const GameObject& other)
{
}

AbstractGO::~AbstractGO()
{
}