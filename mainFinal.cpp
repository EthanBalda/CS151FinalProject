#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Game game;
        game.start();
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}
