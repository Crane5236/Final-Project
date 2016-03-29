#pragma once
#include <iostream>

using namespace std;

class Player {
private:
	char key;
	int playerXPos;
	int playerYPos;
public:
	void keyInput();
	void action();
	void setPlayerX(int value);
	void setPlayerY(int value);
};