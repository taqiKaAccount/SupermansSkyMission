#include <iostream>
#include "HUMania.hpp"
#include <vector>
#include <cstdlib>
#include <SDL.h>

using namespace std;

// Unit pigeon = {{7,88,155,103}, {30, 40, 50, 50}};
// Unit bee = {{540,370,193,115},{30,40,50,50}};
// Unit butterfly = {{257,24,173,134},{30,40,50,50}};
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
        if (superman.moverRect.x >= 950) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = 920;
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
        if (superman.moverRect.x <= 995) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x += 15;
        }
        // 5 is for a slightly faster movement speed; 2 was too slow

        //testing github commit directly 
        
    }
}


void up(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.y <= 0) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.y = 30;
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


void down(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.y >= 450) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.y = 400;
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



void left(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x <= 0) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x = 20;
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
        superman.moverRect.x -= 50;
        
    }
}

void animation(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        if (superman.moverRect.x <= 960) {
            // when the superman moves out of the screen reappear from the left
            superman.moverRect.x += 15;
            //edited to block any movement on x axis
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

// Unit butterfly = {{257,24,173,134},{30,40,50,50}};
// vector<Unit> butterflies;

// void projectile(){
//     createObjectprojectile();





// void createObjectprojectile(int x, int y) {
//     if (butterflies.size()  < 1 ){
//     int n = 0;
    
//     SDL_Rect randomSrcRect;
//     SDL_Rect randomMoverRect;
//     Unit randomObject;

//     switch (n) {
//         case 0:
//             randomSrcRect = {257, 24, 173, 134};
//             randomMoverRect = {x, y, 75, 75};
//             randomObject = {randomSrcRect, randomMoverRect};
//             butterflies.push_back(randomObject);
//             break;
//     }
//     }
// }

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







Unit flying = {{7, 88, 155, 103}, {30, 40, 50, 50}};

// Create vectors to store multiple units of each type
    vector<Unit> flies;

// Function to handle keyboard input and move superman accordingly




void drawObjectsflying(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& flying : flies) {
        if (flying.moverRect.x >= 999) {
            // when the flying moves out of the screen reappear from the left
            flying.moverRect.x = -20;
        }

        // create the flying on the screen
        SDL_RenderCopy(gRenderer, assets, &flying.srcRect, &flying.moverRect);

      
        flying.srcRect.x = 0;
            flying.srcRect.y = 237;
            flying.srcRect.w = 153;
            flying.srcRect.h = 84;
       
        // Update srcRect for flying animation
        if (flying.srcRect.x == 0) {
            flying.srcRect.x = 2;
            flying.srcRect.y = 361;
            flying.srcRect.w = 159;
            flying.srcRect.h = 124;
        } 
        else {
            flying.srcRect.x = 0;
            flying.srcRect.y = 237;
            flying.srcRect.w = 153;
            flying.srcRect.h = 84;
        }

        // 5 is for a slightly faster movement speed; 2 was too slow
        flying.moverRect.x -= 5;
        //testing github commit directly 
        
    }
}


void animation_flying(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& flying : flies) {
        if (flying.moverRect.x >= 999) {
            // when the flying moves out of the screen reappear from the left
            flying.moverRect.x += 30;
            //edited to block any movement on x axis
        }

        // create the flying on the screen
        SDL_RenderCopy(gRenderer, assets, &flying.srcRect, &flying.moverRect);

       
        // Update srcRect for flying animation
          flying.srcRect.x = 2;
        flying.srcRect.y = 361;
        flying.srcRect.w = 159;
        flying.srcRect.h = 124;


        // 5 is for a slightly faster movement speed; 2 was too slow
        
        
    }
}





void createObject_flying(int x, int y) {
    if (flies.size()  < 50 ){
    int n = 0;
    SDL_Rect randomSrcRect;
    SDL_Rect randomMoverRect;
    Unit randomObject;

    switch (n) {
        case 0:
            randomSrcRect = {7, 88, 155, 103};
            randomMoverRect = {x, y, 75, 75};
            randomObject = {randomSrcRect, randomMoverRect};
            flies.push_back(randomObject);
            break;
    }

    }
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}




Unit bee = {{540,370,193,115},{30,40,50,50}};
vector<Unit> bees;
vector<Unit> bees2;
void drawObjectswalking(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& bee : bees) {
        if (bee.moverRect.x >= 999) {
            // when the bees moves out of the screen reappear from the left
            bee.moverRect.x = -20;
        }

        // create the bees on the screen
        SDL_RenderCopy(gRenderer, assets, &bee.srcRect, &bee.moverRect);

      
        bee.srcRect.x = 540;
            bee.srcRect.y = 370;
            bee.srcRect.w = 193;
            bee.srcRect.h = 115;


        if (bee.srcRect.y == 232) {
            bee.srcRect.x = 540;
            bee.srcRect.y = 370;
            bee.srcRect.w = 193;
            bee.srcRect.h = 115;
           
        } 
        else if (bee.srcRect.y == 138) {
            bee.srcRect.x = 527;
            bee.srcRect.y = 252;
            bee.srcRect.w = 194;
            bee.srcRect.h = 115;
        }
        else{
            bee.srcRect.x = 527;
            bee.srcRect.y = 138;
            bee.srcRect.w = 194;
            bee.srcRect.h = 115;

        }
       
        // // Update srcRect for bees animation
        // if (bee.srcRect.x == 0) {
        //     bee.srcRect.x = 2;
        //     bee.srcRect.y = 361;
        //     bee.srcRect.w = 159;
        //     bee.srcRect.h = 124;
        // } 
        // else {
        //     bee.srcRect.x = 0;
        //     bee.srcRect.y = 237;
        //     bee.srcRect.w = 153;
        //     bee.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        bee.moverRect.x -= 5;
        //testing github commit directly 
        
    }
}

void drawObjectswalking2(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& bee : bees2) {
        if (bee.moverRect.x >= 999) {
            // when the bees moves out of the screen reappear from the left
            bee.moverRect.x = -20;
        }

        // create the bees on the screen
        SDL_RenderCopy(gRenderer, assets, &bee.srcRect, &bee.moverRect);

      
        bee.srcRect.x = 540;
            bee.srcRect.y = 370;
            bee.srcRect.w = 193;
            bee.srcRect.h = 115;


        if (bee.srcRect.y == 232) {
            bee.srcRect.x = 540;
            bee.srcRect.y = 370;
            bee.srcRect.w = 193;
            bee.srcRect.h = 115;
           
        } 
        else if (bee.srcRect.y == 138) {
            bee.srcRect.x = 527;
            bee.srcRect.y = 252;
            bee.srcRect.w = 194;
            bee.srcRect.h = 115;
        }
        else{
            bee.srcRect.x = 527;
            bee.srcRect.y = 138;
            bee.srcRect.w = 194;
            bee.srcRect.h = 115;

        }
       
        // // Update srcRect for bees animation
        // if (bee.srcRect.x == 0) {
        //     bee.srcRect.x = 2;
        //     bee.srcRect.y = 361;
        //     bee.srcRect.w = 159;
        //     bee.srcRect.h = 124;
        // } 
        // else {
        //     bee.srcRect.x = 0;
        //     bee.srcRect.y = 237;
        //     bee.srcRect.w = 153;
        //     bee.srcRect.h = 84;
        // }

        // 5 is for a slightly faster movement speed; 2 was too slow
        bee.moverRect.x += 5;
        //testing github commit directly 
        
    }
}








// void animation_walking(SDL_Renderer* gRenderer, SDL_Texture* assets) {
//     for (Unit& bee : bees) {
//         if (bee.moverRect.x >= 999) {
//             // when the bees moves out of the screen reappear from the left
//             bee.moverRect.x += 30;
//             //edited to block any movement on x axis
//         }

//         // create the bees on the screen
//         SDL_RenderCopy(gRenderer, assets, &bee.srcRect, &bee.moverRect);

       
//         // Update srcRect for bees animation
//           bee.srcRect.x = 2;
//         bee.srcRect.y = 361;
//         bee.srcRect.w = 159;
//         bee.srcRect.h = 124;


//         // 5 is for a slightly faster movement speed; 2 was too slow
        
        
//     }
// }



void createObject_walking(int x, int y) {
    if (bees.size()  < 50 ){
    int n = 0;
    SDL_Rect randomSrcRect;
    SDL_Rect randomMoverRect;
    Unit randomObject;

    switch (n) {
        case 0:
            randomSrcRect = {540, 370, 193, 115};
            randomMoverRect = {x, y, 75, 75};
            randomObject = {randomSrcRect, randomMoverRect};
            bees.push_back(randomObject);
    }

    }
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void createObject_walking2(int x, int y) {
    if (bees2.size()  < 50 ){
    int n = 0;
    SDL_Rect randomSrcRect;
    SDL_Rect randomMoverRect;
    Unit randomObject;

    switch (n) {
        case 0:
            randomSrcRect = {540, 370, 193, 115};
            randomMoverRect = {x, y, 75, 75};
            randomObject = {randomSrcRect, randomMoverRect};
            bees2.push_back(randomObject);
    }

    }
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}
