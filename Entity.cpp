#include "Entity.h"

int Entity::getHealth() {
	return health;
}

int Entity::getMana() {
	return mana;
}

int Entity::getAttack() {
	return attack;
}

int Entity::getDefense() {
	return defense;
}

void Entity::setHealth(int value) {
	health = value;
}

void Entity::setMana(int value) {
	mana = value;
}

void Entity::setAttack(int value) {
	attack = value;
}

void Entity::setDefense(int value) {
	defense = value;
}