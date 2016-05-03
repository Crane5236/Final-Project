#pragma once

class Entity {
private:
	int maxHealth;
	int health;
	int mana;
	int strength;
	int defense;
public:
	int getHealth();
	int getMaxHealth();
	int getMana();
	int getStrength();
	int getDefense();

	void setMaxHealth(int value);
	void setHealth(int value);
	void setMana(int value);
	void setStrength(int value);
	void setDefense(int value);

	bool hit();
	int attack(Entity *other);
	int getDamage(Entity *other);
};