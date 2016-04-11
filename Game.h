#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Player.h"

using namespace std;

class Game {
private:
	char map[16][30];
	char key;
	ifstream f;
	bool gameRun = true;
	string tempMapLine;
	Player player;
public:
	void loadMap();
	void draw();
	void run();
	void keyInput();
	void openChest(int yCord, int xCord);
};