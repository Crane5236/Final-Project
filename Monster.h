#pragma once
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

class Monster : public Entity {
private:
	string name;
	int xp;
	int gold;
public:
	void setName(string value);
	string getName();
	int getXP();
	int getGold();
	void setGold(int value);
	void setXP(int value);
	Monster();
};