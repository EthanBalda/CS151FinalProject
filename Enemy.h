#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>
using namespace std;

//a character that can attack the player

class Enemy: public Character {
	private:
		int damage; 
	
	public:
		//constructor
		Enemy(const string& name, int health, int damage);
		
		//destructor
		virtual ~Enemy();
		
		//getter
		int getDamage() const;
		
		//virtual methods
		void attack(Character* target) override;
		void takeDamage(int amount) override;
};

#endif
