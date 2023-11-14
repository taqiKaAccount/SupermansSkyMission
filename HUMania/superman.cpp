// #include "superman.hpp"

// superman::superman(SDL_Renderer *rend, SDL_Texture *ast) : Spaceship(rend, ast)
// {
//     mover = {300 - 32, 675 - 75, 75, 75};
//     src = {2013, 2291, 427, 253};
//     health = 8;
//     velocity = 15;
// }

// void superman::draw()
// {
//     Unit::draw(src, mover, SDL_FLIP_NONE);
//     for (auto *laser : lasers)
//     {
//         laser->draw();
//         if (laser->mover.y < 0)
//         {
//             lasers.remove(laser);
//             delete laser;
//         }
//     }
// }

// void superman::fire(SDL_Renderer *rend, SDL_Texture *ast)
// {
//     lasers.push_back(new Laser(rend, ast, mover.x, mover.y, 1)); // Adding laser to list.
// }

// // playerMovement
// void superman::moveRight()
// {
//     if (mover.x + 70 < 600)
//     {
//         mover.x += velocity;
//     }
//     else if (mover.x + 70 >= 600)
//         mover.x = 600 - 70;
// }
// void superman::moveLeft()
// {
//     if (mover.x > 0)
//         mover.x -= velocity;
//     else if (mover.x <= 0)
//         mover.x = 0;
// }
// void superman::decreaseHealth()
// {
//     health -= 1;
// }
// void superman::increaseHealth()
// {
//     if (health < 8)
//         health += 1;
// }

// // int Player::life_status(){
// //     return health;
// // }

// bool superman::checkHealth() // Checking if player is alive.
// {
//     if (health <= 0)
//     {
//         return false;
//     }
//     return true;
// }

// void superman::move()
// {
// }

// superman::~superman()
// {
//     for (auto *laser : lasers)
//         delete laser;
//     lasers.clear();
// }