#include "game.hpp"
#include "HUMania.hpp"
#include "drawing.hpp"
#include "Music.hpp"
#include "superman.hpp"
#include "Lazer.hpp"
#include "LazerMaker.hpp"


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
        }
    }
    return success;
}
bool Game::loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Drawing::assets = loadTexture("assets.png");
    //Drawing::assets = loadTexture("supermen1.png");
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
{
    // BackgroundMusic BGM("Mainbackgroundmusic.mp3");
    // BGM.play(-1);
    bool quit = false;
    SDL_Event e;
    bool start = false;
    
    HUMania humania;
    LazerMaker lazermachine ;
    Superman supermanObject(-100 , 200);
    Uint32 lastSpawnTimeOfFlying = SDL_GetTicks(); // Initialize lastSpawnTime
    Uint32 lastSpawnTimeOfWalking = SDL_GetTicks();
    while( !quit )
    {   
        
        supermanObject.draw(Drawing::gRenderer, Drawing::assets);
        Uint32 currentTimeFlying = SDL_GetTicks();
        Uint32 elapsedTimeFlying = currentTimeFlying - lastSpawnTimeOfFlying;

        Uint32 currentTimeWalking = SDL_GetTicks();
        Uint32 elapsedTimeWalking = (currentTimeWalking - lastSpawnTimeOfWalking);

        if (start == true and elapsedTimeWalking >= (4250 - rand() % 1000 ) ) // Adjust the interval (3000 milliseconds) as needed
        {       
            humania.createObjectwalking(700, 450);
            lastSpawnTimeOfWalking = currentTimeWalking; // Update lastSpawnTime for the next interval
        }

        if (start == true and elapsedTimeFlying >= (3750 - rand()%600 ) ) // Adjust the interval (3000 milliseconds) as needed
        {
            humania.createObjectflying(700, 450);
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

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                start = true;
                gTexture = loadTexture("gameBG.jpg");
                //move superman onto the screen
                supermanObject.right(Drawing::gRenderer , Drawing::assets);
                supermanObject.right(Drawing::gRenderer , Drawing::assets);
			}
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        std::cout << "Up arrow key pressed!" << std::endl;
                        supermanObject.up(Drawing::gRenderer , Drawing::assets);
                        humania.checkSupermanCollision(supermanObject); 
                        //checking is health working
                        supermanObject.testHealth();
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down arrow key pressed!" << std::endl;
                        supermanObject.down(Drawing::gRenderer , Drawing::assets);
                        humania.checkSupermanCollision(supermanObject); 
                        supermanObject.testHealth();

                        break;
                    case SDLK_LEFT:
                        std::cout << "Left arrow key pressed!" << std::endl;
                        supermanObject.left(Drawing::gRenderer , Drawing::assets);
                        humania.checkSupermanCollision(supermanObject); 
                        supermanObject.testHealth();

                        break;
                    case SDLK_RIGHT:
                        std::cout << "Right arrow key pressed!" << std::endl;
                        supermanObject.right(Drawing::gRenderer , Drawing::assets);
                        humania.checkSupermanCollision(supermanObject); 
                        supermanObject.testHealth();
                        
                        break;
                    case SDLK_z:
                        std::cout << "z pressed!" << std::endl;
                        //supermanObject.up(Drawing::gRenderer , Drawing::assets);
                        supermanObject.animation(Drawing::gRenderer,Drawing::assets);

                        lazermachine.createObject(supermanObject.getMoverRectX(), supermanObject.getMoverRectY());
                        // supermanObject.draw(Drawing::gRenderer , Drawing::assets);
                        break;
            }
        }

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q) {
				SDL_DestroyTexture(Drawing::assets);
                gTexture = loadTexture("SuperManGameOver.png");
            }

        }
        SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
        SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
        //***********************draw the objects here********************
        humania.drawObjects();
        humania.checkSupermanCollision(supermanObject); 
        lazermachine.drawObjects();
        supermanObject.draw(Drawing::gRenderer, Drawing::assets);
        //****************************************************************
        SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
        SDL_Delay(100); //causes sdl engine to delay for specified miliseconds
    }
            
}