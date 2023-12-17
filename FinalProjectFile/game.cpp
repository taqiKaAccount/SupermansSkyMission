#include "game.hpp"
#include "object_engine.hpp"
#include "drawing.hpp"
#include "Music.hpp"
#include "superman.hpp"
#include "Lazer.hpp"
#include "LazerMaker.hpp"
#include "health.hpp"
#include "HealthDisplay.hpp"
#include "score.hpp"
#include <SDL_ttf.h>


SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        //Create window
        gWindow = SDL_CreateWindow( "Superman Flying Mission", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( Drawing::gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
            if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
        }
    }
    return success;
}
bool Game::loadMedia()
{
    //Loading success flag
    bool success = true;
    
    Drawing::assets = loadTexture("Mastersheet.png");
    gTexture = loadTexture("StartScreen.png");
    //gTexture = loadTexture("gameBG.jpg");
    if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
    return success;
}
void Game::close()
{
    //Free loaded images
    SDL_DestroyTexture(Drawing::assets);
    Drawing::assets=NULL;
    SDL_DestroyTexture(gTexture);
    
    //Destroy window
    SDL_DestroyRenderer( Drawing::gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    Drawing::gRenderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
SDL_Texture* Game::loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}
void Game::run( )
{   // Initialize background music
    BackgroundMusic BGM("Mainbackgroundmusic.mp3");
    BGM.play(-1);
    // Initialize game-related variables and objects
    bool quit = false;
    SDL_Event e;
    bool start = false;
    bool gameRunning = true;
    Score score;
    health supermanHealth;
    object_engine object_engine;
    LazerMaker lazermachine ;
    bool DecreaseHealth = false;
    bool IncreaseScore = true;
    int gamespeed=150;
    Superman supermanObject(-100 , 200);
    int timestop = 0;
    HealthDisplay displayHealth;
    Uint32 lastTimeStop = 0;  // Variable to track the time when 'm' key is pressed
    const Uint32 timeStopDuration = 2000;
    // BulletMaker bulletMaker;
    
    // Initialize spawn times for walking and flying objects
    Uint32 lastSpawnTimeOfFlying = SDL_GetTicks(); // Initialize lastSpawnTime
    Uint32 lastSpawnTimeOfWalking = SDL_GetTicks();
    // Main game loop
    while( !quit )
    {   
        if (start == true){
            // Display the score during gameplay
            score.draw(Drawing::gRenderer);
            SDL_RenderPresent(Drawing::gRenderer);
            const char* sdlError = SDL_GetError();
            if (*sdlError != '\0') {
                std::cerr << "SDL Error: " << sdlError << std::endl;
            }
        }
        // Clear the renderer
        SDL_RenderClear(Drawing::gRenderer);
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);
        // Draw Superman
        supermanObject.draw(Drawing::gRenderer, Drawing::assets);

        // Calculate elapsed time for flying objects
        Uint32 currentTimeFlying = SDL_GetTicks();
        Uint32 elapsedTimeFlying = currentTimeFlying - lastSpawnTimeOfFlying;

        Uint32 currentTimeWalking = SDL_GetTicks();
        Uint32 elapsedTimeWalking = (currentTimeWalking - lastSpawnTimeOfWalking);

        // Spawn walking objects
        if (start == true and elapsedTimeWalking >= (1500 - rand() % 600 ) and timestop == 0 ) // Adjust the interval (3000 milliseconds) as needed
        {       
            object_engine.createObjectwalking(700, 450);
            lastSpawnTimeOfWalking = currentTimeWalking; // Update lastSpawnTime for the next interval
        }

        if (start == true and elapsedTimeFlying >= (4500 - rand()%600 ) and timestop == 0) // Adjust the interval (3000 milliseconds) as needed
        {
            object_engine.createObjectflying(700, 450);
            lastSpawnTimeOfFlying = currentTimeFlying;
             // Update lastSpawnTime for the next interval
        }

        

        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {   
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            if (start == false && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_h ){
                gamespeed = 50;
            }
            if (start == false && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e ){
                gamespeed = 150;
            }

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                start = true;
                gTexture = loadTexture("gameBG.jpg");
                //move superman onto the screen
                supermanObject.right(Drawing::gRenderer , Drawing::assets);
                supermanObject.right(Drawing::gRenderer , Drawing::assets);
			}
            // Handle game over conditions
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        supermanObject.up(Drawing::gRenderer , Drawing::assets);                        
                        break;
                    case SDLK_DOWN:
                        supermanObject.down(Drawing::gRenderer , Drawing::assets);                     
                        break;
                    case SDLK_LEFT:
                        supermanObject.left(Drawing::gRenderer , Drawing::assets);              
                        break;
                    case SDLK_RIGHT:
                        supermanObject.right(Drawing::gRenderer , Drawing::assets);                        
                        break;
                    case SDLK_z:
                        supermanObject.animation(Drawing::gRenderer,Drawing::assets);

                        lazermachine.createObject(supermanObject.getMoverRectX()+40, supermanObject.getMoverRectY()+20);
                        //similar working to object_engine, but for lazers
                        break;
                    // Handle time-stop feature
                    case SDLK_m:
                    if(score.getScore()/50>0){
                        timestop = 1;
                        // Check if the time stop duration has passed
                        lastTimeStop = SDL_GetTicks();
                        score--;
                        break;
                    }
                    
            }
        }

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q or (supermanHealth.getLife()<=0)) {
				SDL_DestroyTexture(Drawing::assets);
                gTexture = loadTexture("gameover.jpeg");
                gameRunning = false;
                score.render(Drawing::gRenderer, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3,100,100);  // Render the final score
                SDL_Rect gameOverRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 };
                SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, &gameOverRect);
            }

        }
        if (timestop == 1)
        {
            Uint32 currentTime = SDL_GetTicks();

            // Check if the time stop duration has passed
            if (currentTime - lastTimeStop >= timeStopDuration)
            {
                timestop = 0;  // Reset time stop after the specified duration
            }
        }
        SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
        //***********************draw the objects here********************
        if (gameRunning)
        {
            object_engine.drawObjects(timestop);
            IncreaseScore = object_engine.checkLazerCollision(lazermachine.returnLazerVector()); 
            if (IncreaseScore != 0){
                score++;
            }
            DecreaseHealth = object_engine.checkSupermanCollision(supermanObject);

            supermanHealth.reduceHealth(DecreaseHealth);
            // Display health during gameplay
            if (start == true){
                displayHealth.RedrawHearts(Drawing::gRenderer, Drawing::assets, supermanHealth.getLife());
            }
            // Check Superman's health
            supermanHealth.testHealth();
            // Draw lazers, Superman, and score
            lazermachine.drawObjects();
            supermanObject.draw(Drawing::gRenderer, Drawing::assets);
            score.render(Drawing::gRenderer,825,10,100,100);
        }
        else{
            // Display game over screen
            SDL_DestroyTexture(Drawing::assets);
            gTexture = loadTexture("gameover.jpeg");

            // Render final score with a larger font in the middle of the screen
            score.render(Drawing::gRenderer, SCREEN_WIDTH / 2-100, SCREEN_HEIGHT / 2-50,200,150);  // Render the final score

            // Adjust position for the game over message
            
        }
        // Display the updated renderer
        //****************************************************************
        SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
        SDL_Delay(gamespeed); //causes sdl engine to delay for specified miliseconds
    }
            
}