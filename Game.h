#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "Entity.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

class Game {
private:
	char map[16][40];
	char key;
	ifstream f;
	bool movement = false;
	bool gameRun = true;
	bool loopRun = true;
	bool TP5;
	bool TP10;
	int randomNumber;
	int keyX;
	int keyY;
	int doorX;
	int doorY;
	int floor;
	int choice;
	string tempMapLine;
	string Pname;
	Player p;
	Monster m;
	Item temp;
	vector<Item> inventory;
public:
	void loadMap(int floor);
	void draw();
	void run();
	void keyInput();
	void openChest(int yCord, int xCord);
	void battle(Player &p, Monster &m);
	void battleScreen(Player p);
	void openDoor();
	void stairs();
	void menu();
	void teleporter();
	void activateTP(int floor);
	void inventoryScreen();
	void store();
};