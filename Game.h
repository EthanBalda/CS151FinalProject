#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Level.h"
#include <vector>

using namespace std;

//game logic and flow of it all

class Game {
	private:
		Player* player;
		vector<Level*> levels;
		Level* currentLevel;
		
		void initializeLevels();
		void handleCombat(Enemy* enemy);
		void moveToLevel(int index);
		
	public:
		//constructor
		Game();
		
		//destructor
		~Game();
		
		//start the game
		void start();
};

#endif
