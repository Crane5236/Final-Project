#include "Entity.h"
#include <stdlib.h>

int Entity::getMaxHealth() {
	return maxHealth;
}

int Entity::getHealth() {
	return health;
}

int Entity::getMana() {
	return mana;
}

int Entity::getMaxMana() {
	return maxMana;
}

int Entity::getStrength() {
	return strength;
}

int Entity::getDefense() {
	return defense;
}

int Entity::getLevel() {
	return level;
}

void Entity::setMaxHealth(int value) {
	maxHealth = value;
}

void Entity::setHealth(int value) {
	health = value;
}

void Entity::setMana(int value) {
	mana = value;
}

void Entity::setMaxMana(int value) {
	maxMana = value;
}

void Entity::setStrength(int value) {
	strength = value;
}

void Entity::setDefense(int value) {
	defense = value;
}

void Entity::setLevel(int value) {
	level = value;
}

bool Entity::hit() {
	int randomNumber;

	randomNumber = rand() % 10 + 1;

	if (randomNumber == 1) {
		return false;
	}
	else {
		return true;
	} 
}

int Entity::attack(Entity &other) {
	int h = other.getHealth();
	int d = getDamage(other);

	h -= d;
	other.setHealth(h);

	return d;
}

int Entity::getDamage(Entity &other) {
	if (getStrength() < other.getDefense()) {
		return (getStrength() - (other.getDefense() / 2)) / 2;
	}
	else {
		return (getStrength() + 4) / 6;
	}
}