#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Player : public Entity {
private:
	int playerXPos;
	int playerYPos;
	int gold;
	string name;
	int nextLevel = 10;
	int xp = 0;
public:
	void setPlayerX(int value);
	void setPlayerY(int value);
	void setName(string value);
	void setXP(int value);
	void setLevelUp(int value);

	int getPlayerX();
	int getPlayerY();
	int getXP();
	int getLevelUp();
	string getName();

	int getGold();
	void setGold(int value);

	void levelUp();

	Player();
};