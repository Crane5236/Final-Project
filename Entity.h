#pragma once

class Entity {
private:
	int health;
	int mana;
	int attack;
	int defense;
public:
	int getHealth();
	int getMana();
	int getAttack();
	int getDefense();

	void setHealth(int &value);
	void setMana(int &value);
	void setAttack(int &value);
	void setDefense(int &value);
};