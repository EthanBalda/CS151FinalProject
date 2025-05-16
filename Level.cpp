#include "Level.h"
#include <iostream>

Level::Level(const string& name, const string& description) 
: name(name), description(description), enemy(nullptr), visited(false), cleared(false) { }

//destructor
Level::~Level() {
	delete enemy;
}

//add way to next level
void Level::addExit(Level* neighbor) {
	exits.push_back(neighbor);
}

//getters
string Level::getName() const {
    return name;
}

string Level::getDescription() const {
    return description;
}

vector<Level*> Level::getExits() const {
    return exits;
}

Enemy* Level::getEnemy() const {
    return enemy;
}

bool Level::hasEnemy() const {
    return enemy != nullptr && enemy->isAlive();
}

bool Level::isVisited() const {
    return visited;
}

void Level::markVisited() {
    visited = true;
}

//describe level
void Level::describe() const {
	cout << "\nYou are in: " << name << endl;
	cout << description << endl;
	
	if(hasEnemy()) {
		cout << "!!Warning!! An enemy is here: " << enemy->getName() << endl;
	}
	
	cout << "\nPaths from here:" << endl;
	for (size_t i = 0; i < exits.size(); ++i) {
        cout << "  [" << i + 1 << "] " << exits[i]->getName() << endl;
    }
}


bool Level::isCleared() const {
    return cleared || !hasEnemy();
}

void Level::markCleared() {
    cleared = true;
}
