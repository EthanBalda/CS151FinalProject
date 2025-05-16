#include "Game.h"
#include "Enemy.h"
#include <iostream>
#include <limits>
#include <stdexcept>

//constructor
Game::Game() {
	player = new Player("Adventurer", 100);
	initializeLevels();
	currentLevel = levels[0];
}

//destructor
Game::~Game() {
    delete player;
    for (Level* level : levels) {
        delete level;
    }
}

//create levels
void Game::initializeLevels() {
	Level* l1 = new Level("Entrance Hall", "The beginning of the Dungeon where you will face low level enemies.");
	Level* l2 = new Level("Cursed Mine", "You've made it past the first room and venture into the mine where the souls of deceased miners have been waiting there for years.");
	Level* l3 = new Level("Forgotten Library", "As you enter the creaky library you see the walls lined with untouched shelves of books protected by the ghosts of nobles.");
	Level* l4 = new Level("Champions Treasury", "You approach the final door guarded by a Grand Knight but behind lies lost treasure.");
	
	l1->addExit(l2);
    l2->addExit(l1);
    l2->addExit(l3);
    l3->addExit(l2);
    l3->addExit(l4);
    l4->addExit(l3);
    
    //l1->setEnemy(new Enemy("Skeleton", 15, 5));
    l2->setEnemy(new Enemy("Zombie Miner", 25, 7));
    l3->setEnemy(new Enemy("Noble Ghost", 30, 10));
    l4->setEnemy(new Enemy("Grand Knight", 50, 15));

    levels.push_back(l1);
    levels.push_back(l2);
    levels.push_back(l3);
    levels.push_back(l4);

}

//move to another level by index
void Game::moveToLevel(int index) {
    if (!currentLevel->isCleared()) {
        cout << "You must complete this level before moving on!" << endl;
        return;
    }
    vector<Level*> exits = currentLevel->getExits();
    if (index >= 1 && index <= exits.size()) {
        currentLevel = exits[index - 1];
    } else {
        throw runtime_error("Invalid level.");
    }
}

//handle combat with enemy
void Game::handleCombat(Enemy* enemy) {
	cout << "\nYou have encountered a " << enemy->getName() << "!" << endl;
	while (player->isAlive() && enemy->isAlive()){
		player->attack(enemy);
		if (enemy->isAlive()) {
			enemy->attack(player);
		}
	}
	
	if (!player->isAlive()) {
		cout << "You have been defeated..." << endl;
	} else {
		cout << "You defeated the enemy!" << endl;
		player->increaseScore(10);
		currentLevel->markCleared();
	}
}

//main game playthrough
void Game::start() {
	cout << "Welcome, " << player->getName() << "!" << endl;
	
	while (player->isAlive()) {
		currentLevel->markVisited();
		currentLevel->describe();
		
		//fight enemy
		if (currentLevel->hasEnemy()) {
			handleCombat(currentLevel->getEnemy());
			if (!player->isAlive()) break;
		}
		
		//show inventory
		cout << "\nType 'i' to view inventory, or pick a number to move: ";
		string input;
		getline(cin, input);
		
		if (input == "i") {
			player->displayInventory();
			continue;
		}
		
		try {
			int choice = stoi(input);
			moveToLevel(choice);
		} catch (exception& e) {
			cout << "Invalid input. Try again." << endl;
		}
		
		if (currentLevel->getName() == "Champions Treasury" && !currentLevel->hasEnemy()) {
			cout << "Congrats! You've cleared all levels!" << endl;
			break;
		}
	}
	
	cout << "\nGame Over. Final Score: " << player->getScore() << endl;
}

