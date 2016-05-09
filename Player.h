#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Player : public Entity {
private:
	int playerXPos;
	int playerYPos;
	string name;
public:
	void setPlayerX(int value);
	void setPlayerY(int value);
	void setName(string value);

	int getPlayerX();
	int getPlayerY();
	string getName();

	Player();
};