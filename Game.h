#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

class Game {
private:
	char map[16][40];
	char key;
	ifstream f;
	bool gameRun = true;
	bool movement = false;
	int randomNumber;
	int keyX;
	int keyY;
	int doorX;
	int doorY;
	int floor;
	string tempMapLine;
	string name;
	Player player;
public:
	void loadMap(int floor);
	void draw();
	void run();
	void keyInput();
	void openChest(int yCord, int xCord);
	void battle();
	void openDoor();
	void stairs();
	void menu();
};