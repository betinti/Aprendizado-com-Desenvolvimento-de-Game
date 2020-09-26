#pragma once

#include <vector>
#include <typeinfo> 
#include "GameObject.h";

#define MANAGER GameManager::getInstance()

class GameManager
{
private:
	std::vector<GameObject*> objects;

	GameManager();

	GameManager(const GameManager&) = delete;
	GameManager operator = (const GameManager&) = delete;

public:
	static GameManager& getInstance();
	void add(GameObject* object);
	void setup();
	void update();
	void draw() const;
	//void checkCollide();
};

