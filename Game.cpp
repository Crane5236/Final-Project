#include "Game.h"

void Game::loadMap() {
	f.open("map.txt");

	if (!f.is_open()) {
		cout << "File could not be opened" << endl;

		return;
	}

	while (f.good() && !f.eof()) {
		for (int y = 0; y < 15; y++) {
			getline(f, tempMapLine);
			for (int x = 0; x < 20; x++) {
				map[y][x] =	tempMapLine[x];

				if (map[y][x] == '@') {
					player.setPlayerX(x);
					player.setPlayerY(y);
				}
			}
		}
	}
	f.close();
}

void Game::draw() {
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 20; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
}

void Game::run() {
	loadMap();

	do {
		draw();
		player.keyInput();
		player.action();
		system("pause");
	} while (gameRun);
}