#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"

using namespace std;
// system("cls")
class Game {
private:
	char map[15][20];
	ifstream f;
	bool gameRun = true;
	string tempMapLine;
	Player player;
public:
	void loadMap();
	void draw();
	void run();
};