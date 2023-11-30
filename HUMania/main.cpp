#include "game.hpp"
using namespace std;


int main(int argc, char* argv[]) {
    Game game;
    srand(time(NULL));

    if (!game.init()) {
        std::cout << "Failed to initialize!\n";
        return 0;
    }

    if (!game.loadMedia()) {
        std::cout << "Failed to load media!\n";
        return 0;
    }

    game.run();
    game.close();

    return 0;
}