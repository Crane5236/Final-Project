#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Entity.h"
#include "Monster.h"

using namespace std;

class Game {
private:
	char map[16][40];
	char key;
	ifstream f;
	bool gameRun = true;
	bool movement = false;
	bool TP5;
	bool TP10;
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
	void teleporter();
	void activateTP(int floor);
};