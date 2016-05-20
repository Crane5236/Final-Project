#include "Monster.h"

void Monster::setName(string value) {
	name = value;
}

string Monster::getName() {
	return name;
}

int Monster::getXP() {
	return xp;
}

int Monster::getGold() {
	return gold;
}

void Monster::setGold(int value) {
	gold = value;
}

void Monster::setXP(int value) {
	xp = value;
}

Monster::Monster() {
	name = "Slime";
	setMaxHealth(3);
	setHealth(3);
	setStrength(5);
	setDefense(3);
	setLevel(1);
	setGold(5);
	setXP(2);
} 