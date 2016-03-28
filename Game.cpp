#include "Game.h"

/*void Game::loadMap() {
	f.open("map.txt");

	if (!f.is_open()) {
		cout << "File could not be opened" << endl;

		return;
	}

	while (f.good() && !f.eof()) {
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 15; y++) {
				f >> map[x][y];
			}
		}
	}

	f.close();
}*/

void Game::makeMap() {
	map[0] = '*';
}

void Game::draw() {
	for (int x = 0; x < 5; x++) {
		cout << map[x];
	}
	cout << endl;
}

void Game::run() {
	makeMap();

	do {
		draw();
		system("pause");
	} while (gameRun);
}