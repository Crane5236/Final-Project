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

int Player::getPlayerX() {
	return playerXPos;
}

int Player::getPlayerY() {
	return playerYPos;
}

string Player::getName() {
	return name;
}

Player::Player() {
	setMaxHealth(13);
	setHealth(13);
	setStrength(7);
	setDefense(4);
	setLevel(1);
	setMana(15);
	setMaxMana(15);
}