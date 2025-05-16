#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <vector>
#include <string>
using namespace std;

//player class represents the controlled player and inherits from character
class Player : public Character {
	private:
		vector<string> inventory; //vector representing what items the player has
		int score; //players score
		
	public:
		//constructor
		Player(const string& name, int health);
		
		//desctructor
		virtual ~Player();
		
		//inventory operations
    	void addItem(const string& item);
    	void displayInventory() const;

    	//score handling
    	int getScore() const;
    	void increaseScore(int amount);

    	//override virtual game methods
    	void attack(Character* target) override;
    	void takeDamage(int amount) override;
};

#endif

