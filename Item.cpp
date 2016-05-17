#include "Item.h"

string Item::getName() {
	return name;
}

int Item::getQuantity() {
	return quantity;
}

int Item::getCost() {
	return cost;
}

void Item::setName(string value) {
	name = value;
}

void Item::setQuantity(int value) {
	quantity = value;
}

void Item::setCost(int value) {
	cost = value;
}

Item::Item() {
	name = "Missing";
	quantity = 0;
	cost = 0;
}

Item::Item(string n) {
	name = n;
	quantity = 0;
	cost = 0;
}

Item::Item(string n, int q) {
	name = n;
	quantity = q;
	cost = 0;
}

Item::Item(string n, int q, int c) {
	name = n;
	quantity = q;
	cost = c;
}