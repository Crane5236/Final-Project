#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Player : public Entity {
private:
	int playerXPos;
	int playerYPos;
public:
	void setPlayerX(int value);
	void setPlayerY(int value);

	int getPlayerX();
	int getPlayerY();
};