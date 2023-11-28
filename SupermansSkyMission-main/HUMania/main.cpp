#include "game.hpp"
using namespace std;
// int main(int argc, char *argv[]){
//     Game game;
//     srand(time(NULL));
//     if( !game.init() ){
// 		printf( "Failed to initialize!\n" );
//         return 0;
// 	}
// 		//Load media
//     if( !game.loadMedia() ){
//         printf( "Failed to load media!\n" );
//         return 0;
//     }
    
//     game.run();
//     game.close();

//     return 0;
// }


int main(int argc, char* argv[]) {
    Game game;
    srand(time(NULL));

    if (!game.init()) {
        cout << "Failed to initialize!\n";
        return 0;
    }

    if (!game.loadMedia()) {
        cout << "Failed to load media!\n";
        return 0;
    }

    game.run();
    game.close();

    return 0;
}