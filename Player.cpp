#include "Player.h"
#include <iostream>

//constructor
Player::Player(const string& name, int health) : Character(name, health), score(0) { }

//destructor
Player::~Player() {}

//add item to inventory
void Player::addItem(const string& item) {
	inventory.push_back(item);
	cout << name << " picked up: " << item << endl;
}

//display inventory
void Player::displayInventory() const {
	cout << name << "'s Inventory:" << endl;
	if (inventory.empty()) {
		cout << " (empty)" << endl;
	} else {
		for (const string& item : inventory) {
			cout << "  - " << item << endl;
		}
	}
}

//get current score
int Player::getScore() const { return score; }

//increase the score
void Player::increaseScore(int amount) { score += amount; }

//attack another character
void Player::attack(Character* target) {
	int damage = 10;
	cout << name << " attacks " << target->getName() << " for " << damage << " damage!" << endl;
	target->takeDamage(damage);
}

//take damage
void Player::takeDamage(int amount) {
	health -=amount;
	if (health < 0) health = 0;
	cout << name << " takes " << amount << " damage. Remaing Health: " << health << endl;
}
