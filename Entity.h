#pragma once

class Entity {
private:
	int maxHealth;
	int health;
	int mana;
	int maxMana;
	int strength;
	int defense;
	int level;
public:
	int getHealth();
	int getMaxHealth();
	int getMana();
	int getMaxMana();
	int getStrength();
	int getDefense();
	int getLevel();

	void setMaxHealth(int value);
	void setHealth(int value);
	void setMana(int value);
	void setMaxMana(int value);
	void setStrength(int value);
	void setDefense(int value);
	void setLevel(int value);

	bool hit();
	int attack(Entity *other);
	int getDamage(Entity *other);
};