#pragma once
#include <string>

using namespace std;

class Item {
private:
	string name;
	int quantity;
	int cost;
public:
	string getName();
	int getQuantity();
	int getCost();

	void setName(string value);
	void setQuantity(int value);
	void setCost(int value);

	Item();
	Item(string n);
	Item(string n, int q);
	Item(string n, int q, int c);
};