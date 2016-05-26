#include "Game.h"

void Game::loadMap(int floor) {
	switch (floor){
	case 0:
		f.open("Hub.txt");
		p.setHealth(p.getMaxHealth());
		p.setMana(p.getMaxMana()); 
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
				p.setPlayerX(x);
				p.setPlayerY(y);
			}
		}
		cout << endl;
	}
}

void Game::run() {
	while (gameRun == true) {
		menu();
		srand(time(NULL));
		floor = 0;
		TP5 = false;
		TP10 = false;
		loadMap(floor);
		inventory.push_back(temp);
		inventory.push_back(temp);

		while (loopRun == true && p.getHealth() > 0) {
			draw();
			cout << "________________________________________________________________________________";
			cout << "Health: " << p.getHealth() << "/" << p.getMaxHealth() << endl;
			cout << "Mana: " << p.getMana() << "/" << p.getMaxMana() << endl;
			cout << "Level: " << p.getLevel() << endl;
			cout << "Floor: ";
			if (floor == 0) {
				cout << "Hub" << endl << endl;
			}
			else {
				cout << floor << endl << endl;
			}
			cout << "Input key (w/s/a/d/e/i): ";
			keyInput();

			if (movement == true) {
				if (floor == 0 || floor == 10 || floor == 11) {
				}
				else {
					randomNumber = rand() % 24 + 1;

					if (randomNumber == 1) {
						loadMonster(m, floor);
						battle(p, m);
					}
				}
			}
			system("cls");
		}
	}
	return;
}

void Game::keyInput() {
	key = _getch();

	switch (key) {
	case 'w':
		if (map[p.getPlayerY() - 1][p.getPlayerX()] == ' ') {
			map[p.getPlayerY() - 1][p.getPlayerX()] = '@';
			map[p.getPlayerY()][p.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;
	case 's':
		if (map[p.getPlayerY() + 1][p.getPlayerX()] == ' ') {
			map[p.getPlayerY() + 1][p.getPlayerX()] = '@';
			map[p.getPlayerY()][p.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;
	case 'a':
		if (map[p.getPlayerY()][p.getPlayerX() - 1] == ' ') {
			map[p.getPlayerY()][p.getPlayerX() - 1] = '@';
			map[p.getPlayerY()][p.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;
	case 'd':
		if (map[p.getPlayerY()][p.getPlayerX() + 1] == ' ') {
			map[p.getPlayerY()][p.getPlayerX() + 1] = '@';
			map[p.getPlayerY()][p.getPlayerX()] = ' ';
			movement = true;
		}
		else {
			return;
		}

		break;

	case 'e':
		if (map[p.getPlayerY() - 1][p.getPlayerX()] == 'C') {
			openChest(p.getPlayerY() - 1, p.getPlayerX());
		}
		else if (map[p.getPlayerY() + 1][p.getPlayerX()] == 'C') {
			openChest(p.getPlayerY() + 1, p.getPlayerX());
		}
		else if (map[p.getPlayerY()][p.getPlayerX() - 1] == 'C') {
			openChest(p.getPlayerY(), p.getPlayerX() - 1);
		}
		else if (map[p.getPlayerY()][p.getPlayerX() + 1] == 'C') {
			openChest(p.getPlayerY(), p.getPlayerX() + 1);
		}
		else if (map[p.getPlayerY() - 1][p.getPlayerX()] == 'K') {
			openDoor();
		}
		else if (map[p.getPlayerY() + 1][p.getPlayerX()] == 'K') {
			openDoor();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() - 1] == 'K') {
			openDoor();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() + 1] == 'K') {
			openDoor();
		}
		else if (map[p.getPlayerY() - 1][p.getPlayerX()] == 'S') {
			stairs();
		}
		else if (map[p.getPlayerY() + 1][p.getPlayerX()] == 'S') {
			stairs();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() - 1] == 'S') {
			stairs();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() + 1] == 'S') {
			stairs();
		}
		else if (map[p.getPlayerY() - 1][p.getPlayerX()] == 'M') {
			store();
		}
		else if (map[p.getPlayerY() + 1][p.getPlayerX()] == 'M') {
			store();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() - 1] == 'M') {
			store();
		}
		else if (map[p.getPlayerY()][p.getPlayerX() + 1] == 'M') {
			store();
		}
		else if (map[p.getPlayerY() - 1][p.getPlayerX()] == 'T') {
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
			else if (map[p.getPlayerY() + 1][p.getPlayerX()] == 'T') {
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
			else if (map[p.getPlayerY()][p.getPlayerX() - 1] == 'T') {
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
			else if (map[p.getPlayerY()][p.getPlayerX() + 1] == 'T') {
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
			case 'i':
				inventoryScreen();
				break;
		}
	}

void Game::openChest(int yCord, int xCord) {
	map[yCord][xCord] = ' ';
	system("cls");
	draw();
	int randItem = rand() % 3 + 1;
	
	if (randItem == 1) {
		inventory[0].setQuantity(inventory[0].getQuantity() + 1);
		cout << "________________________________________________________________________________";
		cout << "You got a Health Potion!" << endl;
		system("pause");
	}
	else if (randItem == 2) {
		inventory[1].setQuantity(inventory[1].getQuantity() + 1);
		cout << "________________________________________________________________________________";
		cout << "You got a Mana Potion!" << endl;
		system("pause");
	}
	else if (randItem == 3) {
		p.setGold(p.getGold() + 25);
		cout << "________________________________________________________________________________";
		cout << "You got 25 gold!" << endl;
		system("pause");
	}
	system("cls");
	return;
}

void Game::battle(Player &p, Monster &m) {
	char turn = 'P';
	bool run = false;
	system("cls");

	cout << "---------------------------------" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|    An enemy has appeared!     |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "---------------------------------" << endl;
	system("pause");
	
	while (p.getHealth() > 0 && m.getHealth() > 0 && run == false) {
		if (turn == 'P') {
			system("cls");
			battleScreen(p);
			cout << "Select an option: ";
			do {
				cin >> choice;
			} while (choice < 1 && choice > 4);
			switch (choice) {
			case 1:
				if (p.hit()) {
					cout << "You hit the " << m.getName() << " for " << p.attack(m) << endl;
					system("pause");
				}
				else {
					cout << "You missed!" << endl;
					system("pause");
				}
				turn = 'M';
				break;
			case 2:
				int spellChoice;
				do {
					system("cls");
					battleScreen(p);
					cout << "1. Heal  5 MP" << endl;
					cout << "2. Back" << endl;
					cin >> spellChoice;
				} while (spellChoice < 1 || spellChoice > 2);

				if (spellChoice == 1) {
					if (p.getMana() > 0) {
						p.setHealth(p.getHealth() + (p.getMaxHealth() * 0.50));
						p.setMana(p.getMana() - 5); 
						cout << "You have healed!" << endl;
						system("pause");
						turn = 'M';
					}
				}
				break;
			case 3:
				int itemOption;
				do {
					system("cls");
					battleScreen(p);
					cout << "     Item            Quantity" << endl;
					cout << "1. HP Potion" << setw(14) << right << inventory[0].getQuantity() << endl;
					cout << "2. MP Potion" << setw(14) << right << inventory[1].getQuantity() << endl;
					cout << "3. Back" << endl;
					cin >> itemOption;
				} while (itemOption < 1 || itemOption > 3);
				switch (itemOption) {
				case 1:
					if (inventory[0].getQuantity() > 0) {
						inventory[0].use(1, p);
						cout << "You have regained health." << endl;
						system("pause");
						turn = 'M';
					}
					break;
				case 2:
					if (inventory[1].getQuantity() > 0) {
						inventory[1].use(2, p);
						cout << "You have regained mana." << endl;
						system("pause");
						turn = 'M';
					}
					break;
				}
				break;
			case 4: 
				int randomNumber = rand() % 10 + 1;

				if (randomNumber == 1) {
					cout << "You have failed to escape!" << endl;
					turn = 'M';
					system("pause");
					break;
				}
				else {
					run = true;
					cout << "You have escaped!" << endl;
					system("pause");
				}
				
				break;
			}
		}
		else {
			if (m.hit()) {
				cout << "The " << m.getName() << " is attacking!" << endl;
				cout << "You lost " << m.attack(p) << " health!" << endl;
				system("pause");
			}
			else {
				cout << "The " << m.getName() << " missed!" << endl;
				system("pause");
			}
			turn = 'P';
		}
	}

	if (p.getHealth() == 0) {
		cout << "You have died! Game over!" << endl;
		system("pause");
	}
	else if (run == false) {
		cout << "You have won!" << endl;
		cout << "You have earned " << m.getGold() << " gold!" << endl;
		p.setGold(p.getGold() + m.getGold());
		cout << "You have earned " << m.getXP() << " XP!" << endl;
		p.setXP(p.getXP() + m.getXP());
		system("pause");
		if (p.getXP() >= p.getLevelUp()) {
			p.levelUp();
		}
	}

	movement = false;
	return;
}

void Game::battleScreen(Player p) {
	cout << "------------------" << endl;
	cout << "|" << setw(16) << left << p.getName() << "|" << endl;
	cout << "|" << "Level " << setw(10) << right << p.getLevel() << "|" << endl;
	cout << "|" << "HP" << setw(14) << right << p.getHealth() << "|" << endl;
	cout << "|" << "MP" << setw(14) << right << p.getMana() << "|" << endl;
	cout << "------------------" << endl;
	cout << "------------------------      ------------------------" << endl;
	cout << "|1. Attack     2. Spell|      |Enemy:                |" << endl;
	cout << "|3. Item       4. Run  |      |Level " << setw(2) << left << m.getLevel() << " " << setw(13) << left <<  m.getName() << "|" << endl;
	cout << "------------------------      ------------------------" << endl;
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
		cout << "2. Exit" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 2);
	system("cls");

	switch (choice) {
	case 1:
		cin.ignore();

		do {
			cout << "Enter your name: ";
			getline(cin, Pname);
			if (Pname.size() > 16) {
				cout << "Name must be at most 16 characters long." << endl;
			}
		} while (Pname.size() > 16);
		p.setName(Pname);
		loopRun = true;
		break;
	case 2:
		loopRun = false;
		gameRun = false;
		break;
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

void Game::inventoryScreen() {
	system("cls");
	cout << "------------------" << endl;
	cout << "|" << setw(16) << left << p.getName() << "|" << endl;
	cout << "|" << "Level " << setw(10) << right << p.getLevel() << "|" << endl;
	cout << "|" << "HP" << setw(14) << right << p.getHealth() << "|" << endl;
	cout << "|" << "MP" << setw(14) << right << p.getMana() << "|" << endl;
	cout << "|" << "Gold" << setw(12) << right << p.getGold() << "|" << endl;
	cout << "------------------" << endl;
	cout << "------------------" << endl;
	cout << "|1. Stats        |" << endl;
	cout << "|2. Items        |" << endl;
	cout << "|3. Escape       |" << endl;
	cout << "|4. Main Menu    |" << endl;
	cout << "|5. Exit         |" << endl;
	cout << "------------------" << endl;

	int choice;

	cout << "Enter an option: ";
	
	do {
		cin >> choice;
	} while (choice < 1 || choice > 5);

	switch (choice) {
	case 1:
		system("cls");
		cout << "------------------" << endl;
		cout << "|" << setw(16) << left << p.getName() << "|" << endl;
		cout << "|" << "Level " << setw(10) << right << p.getLevel() << "|" << endl;
		cout << "|" << "HP" << setw(14) << right << p.getHealth() << "|" << endl;
		cout << "|Max HP" << setw(10) << right << p.getMaxHealth() << "|" << endl;
		cout << "|" << "MP" << setw(14) << right << p.getMana() << "|" << endl;
		cout << "|Max MP" << setw(10) << right << p.getMaxMana() << "|" << endl;
		cout << "|XP" << setw(14) << right << p.getXP() << "|" << endl;
		cout << "|Level up" << setw(8) << p.getLevelUp() - p.getXP() << "|" << endl;
		cout << "|Strength" << setw(8) << right << p.getStrength() << "|" << endl;
		cout << "|Defense" << setw(9) << right << p.getDefense() << "|" << endl;
		cout << "------------------" << endl;
		system("pause");
		system("cls");
		break;
	case 2:
		int option;
		do {
			system("cls");
			char consume = true;

			cout << "     Item             Quantity" << endl;
			cout << "1. HP Potion            " << setw(2) << inventory[0].getQuantity() << "     -------------" << endl;
			cout << "2. MP Potion            " << setw(2) << inventory[1].getQuantity() << "     |HP" << setw(9) << p.getHealth() << "|" << endl;
			cout << "3. Exit" << setw(27) << right << "|MP" << setw(9) << p.getMana() << "|" << endl;
			cout << setw(44) << right << "-------------" << endl;
			cout << "Select an option: ";
			cin >> option;
			if (option == 1 || option == 2) {
				if (option == 1 && inventory[option - 1].getQuantity() <= 0) {
					cout << "You don't have any Health Potions." << endl;
					consume = false;
					system("pause");
				}
				if (option == 2 && inventory[option - 1].getQuantity() <= 0) {
					cout << "You don't have any Mana Potions." << endl;
					consume = false;
					system("pause");
				}
				if (consume) {
					inventory[option - 1].use(option, p);
				}
			}
		} while (option != 3);
		break;
	case 3:
		if (floor > 0) {
			cout << "Warping to base floor." << endl;
			system("pause");
			floor = 0;
			loadMap(floor);
		}
		else {
			cout << "You are already on the base floor." << endl;
			system("pause");
		}
		break;
	case 4:
		cout << "Are you sure you want to return to the main menu? (y/n):";
		char letter;
		cin >> letter;

		switch (letter) {
		case 'y':
			
			loopRun = false;
			break;
		case 'Y':
			loopRun = false;
			break;
		}
		break;
	case 5:
		break;
	}
}

void Game::store() {
	do{
		system("cls");
		cout << "   Item Name          Cost         Quantity Owned" << endl;
		cout << "1. HP Potion          10G             " << inventory[0].getQuantity() << endl;
		cout << "1. MP Potion          15G             " << inventory[1].getQuantity() << endl;
		cout << "3. Exit" << endl << endl;

		cout << "Player Gold: " << p.getGold() << endl;
		cout << "Select item to buy: ";
		int option;
		cin >> option;

		switch (option) {
		case 1:
			if (p.getGold() >= 10) {
				p.setGold(p.getGold() - 10);
				inventory[0].setQuantity(inventory[0].getQuantity() + 1);
			}
			else{
				cout << "You can not afford this item." << endl;
				system("pause");
			}
			break;
		case 2:
			if (p.getGold() >= 15) {
				p.setGold(p.getGold() - 15);
				inventory[1].setQuantity(inventory[1].getQuantity() + 1);
			}
			else{
				cout << "You can not afford this item." << endl;
				system("pause");
			}
			break;
		case 3:
			return;
		}
	} while (choice != 3); 
}

void Game::loadMonster(Monster &m, int value) {
	int random;
	switch (value) {
	case 1:
		random = rand() % 2 + 1;

		if (random == 1) {
			m.setName("Slime");
			m.setMaxHealth(3);
			m.setHealth(3);
			m.setStrength(5);
			m.setDefense(3);
			m.setLevel(1);
			m.setGold(5);
			m.setXP(2);
		}
		else {
			m.setName("Red Slime");
			m.setMaxHealth(3);
			m.setHealth(3);
			m.setStrength(7);
			m.setDefense(3);
			m.setLevel(2);
			m.setGold(10);
			m.setXP(4);
		}
		break;
	case 2:
		random = rand() % 2 + 1;

		if (random == 1) {
			m.setName("Ghost");
			m.setMaxHealth(6);
			m.setHealth(6);
			m.setStrength(9);
			m.setDefense(6);
			m.setLevel(3);
			m.setGold(6);
			m.setXP(4);
		}
		else {
			m.setName("Mage");
			m.setMaxHealth(3);
			m.setHealth(3);
			m.setStrength(7);
			m.setDefense(3);
			m.setLevel(4);
			m.setGold(12);
			m.setXP(6);
		}
		break;
	case 3:
		random = rand() % 2 + 1;
		if (random == 1) {
		m.setName("Zombie");
		m.setMaxHealth(10);
		m.setHealth(10);
		m.setStrength(11);
		m.setDefense(8);
		m.setLevel(5);
		m.setGold(8);
		m.setXP(8);
	}
		else {
			m.setName("Golem");
			m.setMaxHealth(14);
			m.setHealth(14);
			m.setStrength(12);
			m.setDefense(6);
			m.setLevel(6);
			m.setGold(12);
			m.setXP(12);
		}
		break;
	}
}