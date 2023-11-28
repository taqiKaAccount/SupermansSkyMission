#include <iostream>
#include "HUMania.hpp"
#include <vector>
#include <cstdlib>
#include <SDL.h>
#include <algorithm>  

#include "health.hpp"

using namespace std;
Unit bee = {{540,370,193,115},{30,40,50,50}};
vector<Unit> bees;
vector<Unit> bees2;

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

health h;

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

void right(SDL_Renderer* gRenderer, SDL_Texture* assets) {
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
        superman.moverRect.x += 50;
        
        
    }
}
bool supermancollision(SDL_Rect* A, SDL_Rect* B) {
    SDL_bool Collided = SDL_HasIntersection(A, B);
    return Collided == SDL_TRUE;
}

void animation(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (Unit& superman : supermans) {
        // if (superman.moverRect.x <= 960) {
        //     // when the superman moves out of the screen reappear from the left
        //     superman.moverRect.x += 15;
        //     //edited to block any movement on x axis
        // }

        // create the superman on the screen
        SDL_RenderCopy(gRenderer, assets, &superman.srcRect, &superman.moverRect);

       
        // Update srcRect for superman animation
        superman.srcRect.x = 2;
        superman.srcRect.y = 361;
        superman.srcRect.w = 159;
        superman.srcRect.h = 124;

        
        // 5 is for a slightly faster movement speed; 2 was too slow
        createObjectprojectile(superman.moverRect.x,superman.moverRect.y+10);
        
    }
}

Unit butterfly = {{257,24,173,134},{30,40,50,50}};
vector<Unit> butterflies;


void createObjectprojectile(int x, int y) {
    if (butterflies.size()  < 100 ){
    int n = 0;
    
    SDL_Rect randomSrcRect;
    SDL_Rect randomMoverRect;
    Unit randomObject;

    switch (n) {
        case 0:
            randomSrcRect = {257, 24, 173, 134};
            randomMoverRect = {x, y, 75, 75};
            randomObject = {randomSrcRect, randomMoverRect};
            butterflies.push_back(randomObject);
            break;
    }
    }
}



void drawObjectsprojectile(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Create vectors to store butterflies and bees that need to be removed
    std::vector<Unit*> butterfliesToRemove;
    std::vector<Unit*> beesToRemove;
    std::vector<Unit*> beesToRemove2;
    // Iterate through the butterflies vector
    for (auto itB = butterflies.begin(); itB != butterflies.end();) {
        Unit& butterfly = *itB; // Get a reference to the current butterfly

        // Check if butterfly has reached the bottom of the screen
        if (butterfly.moverRect.y >= 999) {
            // Store the butterfly pointer for later removal
            butterfliesToRemove.push_back(&butterfly);
            itB = butterflies.erase(itB); // Erase the current element and get the next iterator
            continue; // Skip rendering and moving for this iteration
        }

        // Render the butterfly on the screen
        SDL_RenderCopy(gRenderer, assets, &butterfly.srcRect, &butterfly.moverRect);

        // Move the butterfly down
        butterfly.moverRect.y += 68;

        // Iterate through the bees vector for collision detection
        for (auto it = bees2.begin(); it != bees2.end();) {
            Unit& bee = *it; // Get a reference to the current bee

            // Check for collision with bee
            if (supermancollision(&butterfly.moverRect, &bee.moverRect)) {
                cout << "Butterfly collided with a bee!" << endl;
                // Add any additional actions you want to perform when a collision occurs

                // Store the bee pointer for later removal
                beesToRemove2.push_back(&bee);
                it = bees2.erase(it); // Erase the current bee and get the next iterator
                continue; // Skip rendering for this iteration
            }

            ++it; // Move to the next iterator
        }
        for (auto it = bees.begin(); it != bees.end();) {
            Unit& bee = *it; // Get a reference to the current bee

            // Check for collision with bee
            if (supermancollision(&butterfly.moverRect, &bee.moverRect)) {
                cout << "Butterfly collided with a bee!" << endl;
                // Add any additional actions you want to perform when a collision occurs

                // Store the bee pointer for later removal
                beesToRemove.push_back(&bee);
                it = bees.erase(it); // Erase the current bee and get the next iterator
                continue; // Skip rendering for this iteration
            }

            ++it; // Move to the next iterator
        }

        ++itB; // Move to the next butterfly iterator
    }

    // Remove butterflies that have reached the bottom of the screen
    for (Unit* butterflyToRemove : butterfliesToRemove) {
        // Delete the butterfly object
        delete butterflyToRemove;
    }

    // Remove bees that have collided with butterflies
    for (Unit* beeToRemove : beesToRemove) {
        // Delete the bee object
        delete beeToRemove;
    }
}






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
    auto it = flies.begin();  // Iterator to keep track of the current position in the vector

    while (it != flies.end()) {
        Unit& flying = *it; // Get a reference to the current flying object

        if (flying.moverRect.x >= 999) {
            // when the flying moves out of the screen, reappear from the left
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
        } else {
            flying.srcRect.x = 0;
            flying.srcRect.y = 237;
            flying.srcRect.w = 153;
            flying.srcRect.h = 84;
        }

        // 5 is for a slightly faster movement speed; 2 was too slow
        flying.moverRect.x -= 5;

        // Testing github commit directly 
        if (!supermans.empty()) {
            SDL_Rect supermanRect = supermans[0].moverRect; // Assuming superman is the first object in the vector
            SDL_Rect flyingRect = flying.moverRect;

            if (supermancollision(&supermanRect, &flyingRect)) {
                cout << "Superman collided with a flying object!" << endl;
                h.reduceHealth() ;
                std::cout<<h.getLife()<<endl ;

                // Add any additional actions you want to perform when a collision occurs
                // Erase the flying object from the vector and get the next iterator
                it = flies.erase(it);
                continue;  // Skip the rest of the loop body to avoid using invalidated iterator
            }
        }

        ++it; // Move to the next iterator
    }
}


// void drawObjectsflying(SDL_Renderer* gRenderer, SDL_Texture* assets) {
//     for (Unit& flying : flies) {
//         if (flying.moverRect.x >= 999) {
//             // when the flying moves out of the screen reappear from the left
//             flying.moverRect.x = -20;
//         }

//         // create the flying on the screen
//         SDL_RenderCopy(gRenderer, assets, &flying.srcRect, &flying.moverRect);

      
//         flying.srcRect.x = 0;
//             flying.srcRect.y = 237;
//             flying.srcRect.w = 153;
//             flying.srcRect.h = 84;
       
//         // Update srcRect for flying animation
//         if (flying.srcRect.x == 0) {
//             flying.srcRect.x = 2;
//             flying.srcRect.y = 361;
//             flying.srcRect.w = 159;
//             flying.srcRect.h = 124;
//         } 
//         else {
//             flying.srcRect.x = 0;
//             flying.srcRect.y = 237;
//             flying.srcRect.w = 153;
//             flying.srcRect.h = 84;
//         }

//         // 5 is for a slightly faster movement speed; 2 was too slow
//         flying.moverRect.x -= 5;
//         //testing github commit directly 
//         if (!supermans.empty()) {
//         SDL_Rect supermanRect = supermans[0].moverRect; // Assuming superman is the first object in the vector
//         SDL_Rect flyingRect = flying.moverRect;

//             if (supermancollision(&supermanRect, &flyingRect)) {
//                 cout << "Superman collided with a flying object!" << endl;
//                 // Add any additional actions you want to perform when a collision occurs
//             }
//         }
        
        
//     }
// }


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


bool shouldLive() { 
    if (h.getLife() ==0)
    {
        return false;
    }
    else return true; 
}


