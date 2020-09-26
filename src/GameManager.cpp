#include "GameManager.h"
#include "ofMain.h";
#include "Shot.h"
#include "Alien.h"


using namespace std;

GameManager::GameManager() {

}

GameManager& GameManager::getInstance() {
	static GameManager instance;
	return instance;
}

void GameManager::add(GameObject* object)
{
	objects.push_back(object);
}

void GameManager::setup()
{
}

void GameManager::update()
{
	auto temp = objects;

	for (GameObject* obj : temp)
	{
            obj->update(ofGetLastFrameTime());
			// parece q algum obj que não existe mais esta tentando acessar
	}

	for (int i = 0; i < objects.size()-1; i++)
	{
		for (int j = i+1; j < objects.size(); j++)
		{
			GameObject* obj1 = objects[i];
			GameObject* obj2 = objects[j];

			//Um objeto colidiu com outro
			if (obj1->getRect().intersects(obj2->getRect()))
			{
				obj1->hit(*obj2);
				obj2->hit(*obj1);
			}
		}
	}

	vector<GameObject*> alive;
	for (GameObject* obj : objects) 
	{
		if (obj->finished()) 
		{
			delete obj;
		}
		else 
		{
			alive.push_back(obj);
		}
	}
	swap(alive, objects);

}

void GameManager::draw() const 
{
	for (const GameObject* obj : objects)
	{
		obj->draw();
	}
}

/*
void GameManager::checkCollide()
{
	for (GameObject* obj : objects)
	{
		if (obj->getTipo() == 2)	//2 -> Shot
		{
			for (GameObject* ob : objects) 
			{
				if (ob->getTipo() == 3)	//3 -> Alien
				{
					if (obj->getRect().intersects(ob->getRect()))
					{
						ob->kill();
						obj->kill();
						break;
					}
				}
			}
		}

		if (obj->getTipo() == 3)	//3 -> Alien
		{
			for (GameObject* ob : objects)
			{
				if (ob->getTipo() == 1)	//1 -> Ship
				{
					if (obj->getRect().intersects(ob->getRect()))
					{
						ob->kill();
						obj->kill();
						break;
					}
				}
			}
		}
	}
}
*/