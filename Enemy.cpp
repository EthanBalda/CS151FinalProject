#include "Enemy.h"
#include <iostream>

//constructor
Enemy::Enemy(const string& name, int health, int damage) : Character(name, health), damage(damage) { }

//destructor
Enemy::~Enemy() { }

int Enemy::getDamage() const {
	return damage;
}

//enemy attacks player
void Enemy::attack(Character* target) {
	cout << name << " attacks " << target->getName() << " for " << damage << " damage!" << endl;
	target->takeDamage(damage); 
}

//take damage from player
void Enemy::takeDamage(int amount) {
	health -= amount;
	if (health < 0) health = 0;
	cout << name << " takes " << amount << " damage. Remaining health: " << health << endl;
}
