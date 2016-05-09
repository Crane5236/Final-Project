#pragma once
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

class Monster : public Entity {
private:
	string name;
public:
	void setName(string value);
	string getName();
	Monster();
};