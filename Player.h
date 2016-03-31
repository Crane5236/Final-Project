#pragma once
#include <iostream>

using namespace std;

class Player {
private:
	int playerXPos;
	int playerYPos;
public:
	void setPlayerX(int value);
	void setPlayerY(int value);

	int getPlayerX();
	int getPlayerY();
};