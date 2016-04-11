#include "Game.h"

void Game::loadMap() {
	f.open("map.txt");

	if (!f.is_open()) {
		cout << "File could not be opened" << endl;

		return;
	}

	while (f.good() && !f.eof()) {
		for (int y = 0; y < 16; y++) {
			getline(f, tempMapLine);
			for (int x = 0; x < 30; x++) {
				map[y][x] =	tempMapLine[x];
			}
		}
	}
	f.close();
}

void Game::draw() {
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 30; x++) {
			cout << map[y][x];
			if (map[y][x] == '@') {
				player.setPlayerX(x);
				player.setPlayerY(y);
			}
		}
		cout << endl;
	}
}

void Game::run() {
	loadMap();

	do {
		draw();
		cout << "--------------------------------------------------------------------------------";
		cout << "Health: " << endl;
		cout << "Level: " << endl;
		cout << "Gold: " << endl;
		cout << "Floor: " << endl << endl;
		cout << "Input key (w/s/a/d/e): ";
		keyInput();
		system("cls");
	} while (gameRun);
}

void Game::keyInput() {
	key = _getch();

	switch (key) {
	case 'w':
		if (map[player.getPlayerY() - 1][player.getPlayerX()] == ' ') {
			map[player.getPlayerY() - 1][player.getPlayerX()] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
		}
		else {
			return;
		}

		break;
	case 's':
		if (map[player.getPlayerY() + 1][player.getPlayerX()] == ' ') {
			map[player.getPlayerY() + 1][player.getPlayerX()] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
		}
		else {
			return;
		}

		break;
	case 'a':
		if (map[player.getPlayerY()][player.getPlayerX() - 1] == ' ') {
			map[player.getPlayerY()][player.getPlayerX() - 1] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
		}
		else {
			return;
		}

		break;
	case 'd':
		if (map[player.getPlayerY()][player.getPlayerX() + 1] == ' ') {
			map[player.getPlayerY()][player.getPlayerX() + 1] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
		}
		else {
			return;
		}

		break;

	case 'e':
		if (map[player.getPlayerY() - 1][player.getPlayerX()] == 'C') {
			openChest(player.getPlayerY() - 1, player.getPlayerX());
		}
		else if (map[player.getPlayerY() + 1][player.getPlayerX()] == 'C') {
			openChest(player.getPlayerY() + 1, player.getPlayerX());
		}
		else if (map[player.getPlayerY()][player.getPlayerX() - 1] == 'C') {
			openChest(player.getPlayerY(), player.getPlayerX() - 1);
		}
		else if (map[player.getPlayerY()][player.getPlayerX() + 1] == 'C') {
			openChest(player.getPlayerY(), player.getPlayerX() + 1);
		}
		else {
			return;
		}

			break;
	}
}

void Game::openChest(int yCord, int xCord) {
	map[yCord][xCord] = ' ';
	system("cls");
	draw();
	cout << "--------------------------------------------------------------------------------";
	cout << "You got an item!" << endl;
	system("pause");

	return;
}