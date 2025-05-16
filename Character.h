#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

//Abstract base class that will be inherited by player and enemy
class Character {
	protected:
		string name; //characters name
		int health; //characters health
	public:
		//constructor
		Character(const string& name, int health);
		
		//destructor
		virtual ~Character();
		
		//getters
		string getName() const;
		int getHealth() const;
		
		//setters
		void setName(const string& newName);
		void setHealth(int newHealth);
		
		//make sure character is alive
		virtual bool isAlive() const;
		
		//game methods
		virtual void attack(Character* target) = 0;
		virtual void takeDamage(int amount) = 0;

};

#endif
