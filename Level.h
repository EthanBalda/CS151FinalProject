#ifndef LEVEL_H
#define LEVEL_H

#include "Enemy.h"
#include <string>
#include <vector>

using namespace std;

//represents a level where a player can interact with enemies or it contains other prizes

class Level {
	private:
		string name; 
		string description; //description of the level
		vector<Level*> exits; //pointers to traverse through levels
		Enemy* enemy;
		bool visited; //if player has visited the level or not
		bool cleared; //true if the level has been completed
		
	public:
		//constructor
		Level(const string& name, const string& description);
		
		//destructor
		~Level();
		
		//add path to other level
		void addExit(Level* neighbor);
		
		//set an enemy in the level
		void setEnemy(Enemy* newEnemy);
		
		//getters
		string getName() const;
	    string getDescription() const;
	    vector<Level*> getExits() const;
	    Enemy* getEnemy() const;
	    bool hasEnemy() const;
	    bool isVisited() const;

	    //mark as visited
	    void markVisited();
	    
	    //print description of level
	    void describe() const;
	    
	    //to check if level has been cleared
	    bool isCleared() const;
    	void markCleared();
	    
};

#endif
