// #include <iostream>
// #include "HUMania.hpp"
// #include <vector>
// #include <cstdlib>
// #include <SDL.h>

// using namespace std;
// // Define three units: superman, bee, and butterfly
// Unit superman = {{7,88,155,103}, {30, 40, 50, 50}};

// // Create vectors to store multiple units of each type
// vector<Unit> supermans;


// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {
//     for (Unit &superman : supermans) {
//         if (superman.moverRect.x >= 999) {
//             //when the superman moves out of the screen reappear from the left 

//             superman.moverRect.x = -20;
//         }
//         // create the superman on the screen
//         SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

//         // Update srcRect for superman animation
//         if (superman.srcRect.x == 0) {
//             superman.srcRect.x = 2;
//             superman.srcRect.y = 361;
//             superman.srcRect.w = 159;
//             superman.srcRect.h = 124;
//         } 
//         else {
//             superman.srcRect.x = 0;
//             superman.srcRect.y = 237;
//             superman.srcRect.w = 153;
//             superman.srcRect.h = 84; 
//         }
//         //5 is for a slightly faster movement speed 2 was too slow 
//         superman.moverRect.x += 5;
        
//     }
// }


// void createObject(int x, int y) {
//     int n = 0;
//     SDL_Rect randomSrcRect;
//     SDL_Rect randomMoverRect;
//     Unit randomObject;

//     switch (n) {
//         case 0:
//             randomSrcRect = {7, 88, 155, 103};
//             randomMoverRect = {x, y, 75, 75};
//             randomObject = {randomSrcRect, randomMoverRect};
//             supermans.push_back(randomObject);
//             break;

//     }

//     std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
// }



#include <iostream>
#include "HUMania.hpp"
#include <vector>
#include <cstdlib>
#include <SDL.h>

using namespace std;

// Define three units: superman, bee, and butterfly
Unit superman = {{7, 88, 155, 103}, {30, 40, 50, 50}};

// Create vectors to store multiple units of each type
vector<Unit> supermans;

// Function to handle keyboard input and move superman accordingly
void handleInput(SDL_Event& e) {
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        // Adjust the movement speed based on your preference
        int movementSpeed = 5;

        // Check which key was pressed
        switch (e.key.keysym.sym) {
            case SDLK_w:
                superman.moverRect.y -= movementSpeed;
                break;
            case SDLK_s:
                superman.moverRect.y += movementSpeed;
                break;
            case SDLK_a:
                superman.moverRect.x -= movementSpeed;
                break;
            case SDLK_d:
                superman.moverRect.x += movementSpeed;
                break;
        }
    }
}



void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x >= 999) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = -20;
        }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

      
        superman.srcRect.x = 0;
            superman.srcRect.y = 237;
            superman.srcRect.w = 153;
            superman.srcRect.h = 84;
       
        // Update srcRect for superman animation
        // if (superman.srcRect.x == 0) {
        //     superman.srcRect.x = 2;
        //     superman.srcRect.y = 361;
        //     superman.srcRect.w = 159;
        //     superman.srcRect.h = 124;
        // } 
        // else {
        //     superman.srcRect.x = 0;
        //     superman.srcRect.y = 237;
        //     superman.srcRect.w = 153;
        //     superman.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        superman.moverRect.x += 15;
        
    }
}


void up(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x >= 999) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = -20;
        }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

       
        // Update srcRect for superman animation
        // if (superman.srcRect.x == 0) {
        //     superman.srcRect.x = 2;
        //     superman.srcRect.y = 361;
        //     superman.srcRect.w = 159;
        //     superman.srcRect.h = 124;
        // } else {
        //     superman.srcRect.x = 0;
        //     superman.srcRect.y = 237;
        //     superman.srcRect.w = 153;
        //     superman.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        superman.moverRect.y += 15;
        
    }
}


void down(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x >= 999) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = -20;
        }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

       
        // Update srcRect for superman animation
        // if (superman.srcRect.x == 0) {
        //     superman.srcRect.x = 2;
        //     superman.srcRect.y = 361;
        //     superman.srcRect.w = 159;
        //     superman.srcRect.h = 124;
        // } else {
        //     superman.srcRect.x = 0;
        //     superman.srcRect.y = 237;
        //     superman.srcRect.w = 153;
        //     superman.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        superman.moverRect.y -= 15;
        
    }
}


void left(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x >= 999) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = -20;
        }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

       
        // Update srcRect for superman animation
        // if (superman.srcRect.x == 0) {
        //     superman.srcRect.x = 2;
        //     superman.srcRect.y = 361;
        //     superman.srcRect.w = 159;
        //     superman.srcRect.h = 124;
        // } else {
        //     superman.srcRect.x = 0;
        //     superman.srcRect.y = 237;
        //     superman.srcRect.w = 153;
        //     superman.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        superman.moverRect.x -= 30;
        
    }
}

void animation(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x >= 999) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = -20;
        }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

       
        // Update srcRect for superman animation
          superman.srcRect.x = 2;
        superman.srcRect.y = 361;
        superman.srcRect.w = 159;
        superman.srcRect.h = 124;


        // 5 is for a slightly faster movement speed; 2 was too slow
        
        
    }
}

void moveRight(){
    superman.moverRect.x += 5;
};

void moveLeft(){
    superman.moverRect.x -= 5;
    
};

void moveUp(){
     superman.moverRect.y += 5;
};

void moveDown(){
     superman.moverRect.y -= 5;
};



void createObject(int x, int y) {
    if (supermans.size()  < 1 ){
    int n = 0;
    SDL_Rect randomSrcRect;
    SDL_Rect randomMoverRect;
    Unit randomObject;

    switch (n) {
        case 0:
            randomSrcRect = {7, 88, 155, 103};
            randomMoverRect = {x, y, 75, 75};
            randomObject = {randomSrcRect, randomMoverRect};
            supermans.push_back(randomObject);
            break;
    }

    }
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

// int main() {
//     // Initialize SDL and create a window and renderer
//     // (Add your SDL initialization code here)

//     SDL_Event e;
//     bool quit = false;

//     while (!quit) {
//         // Handle events
//         while (SDL_PollEvent(&e) != 0) {
//             if (e.type == SDL_QUIT) {
//                 quit = true;
//             } else if (e.type == SDL_MOUSEBUTTONDOWN) {
//                 createObject(e.button.x, e.button.y);
//             } else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
//                 handleInput(e);
//             }
//         }

//         // Clear the screen (Add your code to clear the screen here)

//         // Draw objects
//         drawObjects(/* pass your renderer and texture here */);

//         // Update screen (Add your code to update the screen here)
//     }

//     // Clean up and exit SDL (Add your cleanup code here)

//     return 0;
// }




