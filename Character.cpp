#include "Character.h"

//constructor
Character::Character(const string& name, int health) {
	this->name = name;
	this->health = health;
}

//destructor
Character::~Character() { }

//getters
string Character::getName() const { return name; }
int Character::getHealth() const { return health; }

//setters
void Character::setName(const string& newName) { name = newName; }
void Character::setHealth(int newHealth) { health = newHealth; }

//alive if health > 0
bool Character::isAlive() const {
    return health > 0;
}
