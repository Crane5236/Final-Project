#pragma once
#include <iostream>
#include <fstream>

using namespace std;
// system("cls")
class Game {
private:
	char map[5];
	char sprite = '@';
	ifstream f;
	bool gameRun = true;
public:
	void loadMap();
	void makeMap();
	void draw();
	void run();
};