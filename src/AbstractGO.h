#pragma once

#include "ofMain.h";
#include "GameManager.h";
#include "GameObject.h";

class AbstractGO :public GameObject
{
protected:
	string imgName;
	float x;
	float y;
	ofImage img;
	float imgH;
	float imgW;
	bool dead;
	int tipo;

	virtual void kill();

public:
	AbstractGO(const string& imgName);

	//Proibindo copia
	AbstractGO(const AbstractGO&) = delete;
	AbstractGO& operator = (const AbstractGO&) = delete;

	virtual void setup(float x, float y, int tipo);
	virtual void update(float s);
	virtual void draw() const;
	virtual bool finished() const;
	virtual ofRectangle getRect() const;
	virtual int getTipo();

	virtual void hit(const GameObject& other);

	virtual ~AbstractGO();

};

