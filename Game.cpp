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
				map[y][x] = tempMapLine[x];

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
	TP5 = false;
	TP10 = false;
	loadMap(floor);

	

	/*do {
		draw();
		cout << "________________________________________________________________________________";
		cout << "Health: " << endl;
		cout << "Mana: " << endl;
		cout << "Level: " << endl;
		cout << "Floor: ";
		if (floor == 0) {
			cout << "Hub" << endl << endl;
		}
		else {
			cout << floor << endl << endl;
		}
		cout << "Input key (w/s/a/d/e): ";
		keyInput();

		if (movement == true) {
			if (floor == 0 || floor == 10 || floor == 11) {
			}
			else {
				randomNumber = rand() % 24 + 1;

				if (randomNumber == 1) {
					battle(p, m);
				}
			}
		}

		system("cls");
	} while (gameRun);*/
	battleScreen(p);
	system("pause");
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
		else if (map[player.getPlayerY() - 1][player.getPlayerX()] == 'T') {
			if (floor == 0) {
				teleporter();
			}
			else if (floor == 5) {
				if (TP5 == false) {
					activateTP(floor);
				}
				else {
					teleporter();
				}
			}
			else if (floor == 10) {
				if (TP10 == false) {
					activateTP(floor);
				}
				else {
					teleporter();
				}
			}
		}
			else if (map[player.getPlayerY() + 1][player.getPlayerX()] == 'T') {
				if (floor == 0) {
					teleporter();
				}
				else if (floor == 5) {
					if (TP5 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
				else if (floor == 10) {
					if (TP10 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
			}
			else if (map[player.getPlayerY()][player.getPlayerX() - 1] == 'T') {
				if (floor == 0) {
					teleporter();
				}
				else if (floor == 5) {
					if (TP5 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
				else if (floor == 10) {
					if (TP10 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
			}
			else if (map[player.getPlayerY()][player.getPlayerX() + 1] == 'T') {
				if (floor == 0) {
					teleporter();
				}
				else if (floor == 5) {
					if (TP5 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
				else if (floor == 10) {
					if (TP10 == false) {
						activateTP(floor);
					}
					else {
						teleporter();
					}
				}
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
	cout << "________________________________________________________________________________";
	cout << "You got an item!" << endl;
	system("pause");

	return;
}

void Game::battle(Player p, Monster m) {
	system("cls");
	char turn = 'P';
	
	/*while (p.getHealth() == 0 && m.getHealth() == 0) {
		if (turn == 'P') {
			if (p.hit()) {
				cout << "You hit the enemy!" << endl;
			}
		}
	}*/

	system("pause");
	movement = false;
	return;
}

void Game::battleScreen(Player p) {
	cout << "------------------" << endl;
	cout << "|" << setw(16) << left << p.getName() << "|" << endl;
	cout << "|" << "Level " << setw(10) << right << p.getLevel() << "|" << endl;
	cout << "|" << "HP" << setw(14) << right << p.getHealth() << "|" << endl;
	cout << "|" << "MP" << setw(14) << p.getMana() << "|" << endl;
	cout << "------------------" << endl;
	cout << "------------------------" << endl;
	cout << "|1. Attack     2. Spell|" << endl;
	cout << "|3. Item       3. Run  |" << endl;
	cout << "------------------------" << endl;
	cout << "________________________________________________________________________________";
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
		cout << "________________________________________________________________________________";
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
		getline(cin, Pname);
		p.setName(Pname);
	}

	system("cls");
}

void Game::teleporter() {
	int choice;
	bool loopRun = true;
	do {
		system("cls");
		cout << "Enter the floor number to teleport:" << endl << endl;
		cout << "Floor 0" << endl;

		if (TP5) {
			cout << "Floor 5" << endl;
		}

		if (TP10) {
			cout << "Floor 10" << endl;
		}
		cin >> choice;
		switch (choice) {
		case 0:
			loopRun = false;
			break;
		case 5:
			loopRun = false;
			break;
		case 10:
			loopRun = false;
			break;
		default:
			break;
		}
	} while (loopRun);

		if (choice == 0) {
			if (floor == 0) {
				cout << "You are already on that floor." << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				floor = 0;
				loadMap(floor);
				system("cls");
				return;
			}
		}

		if (choice == 5) {
			if (floor == 5) {
				cout << "You are already on that floor." << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (TP5 == false) {
				cout << "You cannot teleport to that floor." << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				floor = 5;
				loadMap(floor);
				system("cls");
				return;
			}
		}

		if (choice == 10) {
			if (floor == 10) {
				cout << "You are already on that floor." << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (TP10 == false) {
				cout << "You cannot teleport to that floor." << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				floor = 10;
				loadMap(floor);
				system("cls");
				return;
			}
		}
}

void Game::activateTP(int floor) {
	if (floor == 5) {
		TP5 = true;
		system("cls");
		draw();
		cout << "________________________________________________________________________________";
		cout << "Teleporter has been activated!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (floor == 10) {
		TP10 = true;
		system("cls");
		draw();
		cout << "________________________________________________________________________________";
		cout << "Teleporter has been activated!" << endl;
		system("pause");
		system("cls");
		return;
	}
}