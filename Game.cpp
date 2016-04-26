#include "Game.h"

void Game::loadMap(int floor) {
	switch (floor){
	case 0:
		f.open("Hub.txt");
		break;
	case 1:
		f.open("Level1.txt");
		break;
	case 2:
		f.open("Level2.txt");
		break;
	case 3:
		f.open("Level3.txt");
		break;
	case 4:
		f.open("Level4.txt");
		break;
	case 5:
		f.open("Level5.txt");
		break;
	case 6:
		f.open("Level6.txt");
		break;
	case 7:
		f.open("Level7.txt");
		break;
	case 8:
		f.open("Level8.txt");
		break;
	case 9:
		f.open("Level9.txt");
		break;
	case 10:
		f.open("Level10.txt");
		break;
	case 11:
		f.open("Final.txt");
		break;
	}

	if (!f.is_open()) {
		cout << "File could not be opened" << endl;

		return;
	}

	while (f.good() && !f.eof()) {
		for (int y = 0; y < 16; y++) {
			getline(f, tempMapLine);
			for (int x = 0; x < 40; x++) {
				map[y][x] =	tempMapLine[x];

				if (map[y][x] == 'K') {
					keyY = y;
					keyX = x;
				}
				if (map[y][x] == 'D') {
					doorY = y;
					doorX = x;
				}
			}
		}
	}
	f.close();
}

void Game::draw() {
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 40; x++) {
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
	menu();
	srand(time(NULL));
	floor = 0;
	loadMap(floor);

	do {
		draw();
		cout << "--------------------------------------------------------------------------------";
		cout << "Health: " << endl;
		cout << "Mana: " << endl;
		cout << "Level: " << endl;
		cout << "Floor: " << endl << endl;
		cout << "Input key (w/s/a/d/e): ";
		keyInput();

		if (movement == true) {
			randomNumber = rand() % 100 + 1;

			if (randomNumber >= 0 && randomNumber <= 8) {
				battle();
			}
		}

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
			movement = true;
		}
		else {
			return;
		}

		break;
	case 's':
		if (map[player.getPlayerY() + 1][player.getPlayerX()] == ' ') {
			map[player.getPlayerY() + 1][player.getPlayerX()] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;
	case 'a':
		if (map[player.getPlayerY()][player.getPlayerX() - 1] == ' ') {
			map[player.getPlayerY()][player.getPlayerX() - 1] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;
	case 'd':
		if (map[player.getPlayerY()][player.getPlayerX() + 1] == ' ') {
			map[player.getPlayerY()][player.getPlayerX() + 1] = '@';
			map[player.getPlayerY()][player.getPlayerX()] = ' ';
			movement = true;
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
		else if (map[player.getPlayerY() - 1][player.getPlayerX()] == 'K') {
			openDoor();
		}
		else if (map[player.getPlayerY() + 1][player.getPlayerX()] == 'K') {
			openDoor();
		}
		else if (map[player.getPlayerY()][player.getPlayerX() - 1] == 'K') {
			openDoor();
		}
		else if (map[player.getPlayerY()][player.getPlayerX() + 1] == 'K') {
			openDoor();
		}
		else if (map[player.getPlayerY() - 1][player.getPlayerX()] == 'S') {
			stairs();
		}
		else if (map[player.getPlayerY() + 1][player.getPlayerX()] == 'S') {
			stairs();
		}
		else if (map[player.getPlayerY()][player.getPlayerX() - 1] == 'S') {
			stairs();
		}
		else if (map[player.getPlayerY()][player.getPlayerX() + 1] == 'S') {
			stairs();
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

void Game::battle() {
	system("cls");

	cout << "--------------------------------------------------" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                    Battle!                     |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                                                |" << endl;
	cout << "--------------------------------------------------" << endl;

	system("pause");
	movement = false;
	return;
}

void Game::openDoor() {
	map[keyY][keyX] = ' ';
	map[doorY][doorX] = ' ';

	return;
}

void Game::stairs() {
	int choice;

	do {
		system("cls");
		draw();
		cout << "--------------------------------------------------------------------------------";
		cout << "Do you want to advance to the next floor?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 2);

	if (choice == 1) {
		floor++;
		loadMap(floor);
	}
	else {
		system("cls");
		return;
	}
	system("cls");
	return;
}

void Game::menu() {
	int choice;
	do {
		system("cls");
		cout << "Tower of Tartarus" << endl << endl;
		cout << "1. New Game" << endl;
		cout << "2. Load Game" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 2);
	system("cls");

	if (choice == 1) {
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, name);
	}

	system("cls");
}