#include "Monster.h"

void Monster::setName(string value) {
	name = value;
}

Monster::Monster() {
	name = "Slime";
	setMaxHealth(3);
	setHealth(3);
	setStrength(5);
	setDefense(3);
} 