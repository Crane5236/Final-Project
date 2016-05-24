#include "Player.h"

void Player::setPlayerX(int value) {
	playerXPos = value;
}

void Player::setPlayerY(int value) {
	playerYPos = value;
}

void Player::setName(string value) {
	name = value;
}

void Player::setXP(int value) {
	xp = value;
}

void Player::setLevelUp(int value) {
	nextLevel = value;
}

int Player::getPlayerX() {
	return playerXPos;
}

int Player::getPlayerY() {
	return playerYPos;
}

int Player::getXP() {
	return xp;
}

int Player::getLevelUp() {
	return nextLevel;
}

string Player::getName() {
	return name;
}

int Player::getGold() {
	return gold;
}

void Player::setGold(int value) {
	gold = value;
}

void Player::levelUp() {
	cout << "You have leveled up!" << endl;
	cout << "Health went up by 2." << endl;
	setHealth(getMaxHealth() + 2);
	setMaxHealth(getHealth());
	cout << "Mana went up by 5." << endl;
	setMana(getMaxMana() + 5);
	setMaxMana(getMana());
	cout << "Strength went up by 2." << endl;
	setStrength(getStrength() + 2);
	cout << "Defense went up by 2." << endl;
	setDefense(getDefense() + 2);
	if (getXP() > getLevelUp()) {
		setXP(getXP() - getLevelUp());
	}
	else {
		setXP(0);
	}
	setLevelUp(getLevelUp() + 10);
	setLevel(getLevel() + 1);
	system("pause");
}

Player::Player() {
	setMaxHealth(13);
	setHealth(13);
	setStrength(7);
	setDefense(4);
	setLevel(1);
	setMana(15);
	setMaxMana(15);
	setGold(50);
}