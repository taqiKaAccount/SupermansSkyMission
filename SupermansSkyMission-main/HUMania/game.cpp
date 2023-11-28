#include "game.hpp"
#include "HUMania.hpp"

#include "health.hpp"

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
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

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
	
	//assets = loadTexture("assets.png");


	assets = loadTexture("supermen1.png");
	assets1 = loadTexture("assets.png");


    gTexture = loadTexture("StartScreen.png");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}


void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	SDL_DestroyTexture(assets1);
	assets1=NULL;
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
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
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
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


	bool quit = false;
	SDL_Event e;
	bool start = false;
	Uint32 lastSpawnTimeOfFlying = SDL_GetTicks(); // Initialize lastSpawnTime
	Uint32 lastSpawnTimeOfWalking = SDL_GetTicks();
	int i = 0 ;
	Uint32 delayTime = static_cast<Uint32>(1000.0 / 120.0);
	while( !quit )
	{
		std::cout<<"is this running"<<std::endl;
		if (shouldLive() == false)
			{
				SDL_DestroyTexture(assets);
				SDL_DestroyTexture(assets1);

				std::cout<<"check this fucntion";
			  	gTexture = loadTexture("SuperManGameOver.png");
			}

		SDL_Delay(delayTime);
		
		Uint32 currentTimeFlying = SDL_GetTicks();
        Uint32 elapsedTimeFlying = currentTimeFlying - lastSpawnTimeOfFlying;

		Uint32 currentTimeWalking = SDL_GetTicks();
        Uint32 elapsedTimeWalking = currentTimeFlying - lastSpawnTimeOfFlying;

        if (start && elapsedTimeFlying >= 5000) // Adjust the interval (3000 milliseconds) as needed
        {
            int n = rand() % 3;
            if (n == 1)
            {
                createObject_flying(900, 200);
            }
			else if(n==2){
				createObject_flying(900, 50);
			}
            else
            {
                createObject_flying(900, 400);
            }

            lastSpawnTimeOfFlying = currentTimeFlying; // Update lastSpawnTime for the next interval
        }

		if (start && elapsedTimeWalking >= 5000) // Adjust the interval (3000 milliseconds) as needed
        {
            int n = rand() % 2;
            if (n == 1)
            {
                createObject_walking(900, 525);
            }
            else
            {
                createObject_walking2(0, 525);
            }

            lastSpawnTimeOfWalking = currentTimeWalking; // Update lastSpawnTime for the next interval
        }
		
			
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			// if (start == true){
			// int n = rand() % 1;
			// if(n = 0){
			// 	createObject_flying(900, 200);
			// 	}
			// 	else{
			// 		createObject_flying(900, 400);
			// 	}
			// }	
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                gTexture = loadTexture("gameBG.jpg");
				createObject(50, 100);
				// int n = rand() % 1;
				// if(n = 0){
				// createObject_flying(900, 200);
				// }
				// else{
				// 	createObject_flying(900, 200);
				// }
				start = true;
				
				drawObjects(gRenderer, assets);
				drawObjectsflying(gRenderer,assets1);
				
				drawObjectswalking(gRenderer,assets1);
				drawObjectswalking2(gRenderer,assets1);
				drawObjectsprojectile(gRenderer,assets1);

			}
//working on this line here changing functionality to q key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q) {
				SDL_DestroyTexture(assets);
				SDL_DestroyTexture(assets1);
	    		// SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds

				
	    			//causes sdl engine to delay for specified miliseconds
				
				//SDL_RenderClear(gTexture);

                gTexture = loadTexture("SuperManGameOver.png");
				createObject(50, 100);
				// createObject_flying(900, 200);
				drawObjects(gRenderer, assets);
				// drawObjectsprojectile(gRenderer,assets1);
				// drawObjectsflying(gRenderer, assets1);
				// SDL_Delay(200);
				//quit = true;
            }


			if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        std::cout << "Up arrow key pressed!" << std::endl;
                        up(gRenderer, assets);
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down arrow key pressed!" << std::endl;
                        down(gRenderer, assets);
                        break;
                    case SDLK_LEFT:
                        std::cout << "Left arrow key pressed!" << std::endl;
                        left(gRenderer, assets);
                        break;
                    case SDLK_RIGHT:
                        std::cout << "Right arrow key pressed!" << std::endl;
                        right(gRenderer, assets);
                        break;
                    case SDLK_m:
                        std::cout << "M key pressed!" << std::endl;
                        animation(gRenderer, assets);
						drawObjectsprojectile(gRenderer,assets1);
                        break;
                    default:
                        drawObjects(gRenderer, assets);
                        break;
                }
			}
			// if(e.type == SDL_MOUSEBUTTONDOWN){
			// //this is a good location to add pigeon in linked list.
			// 	int xMouse, yMouse;
			// 	SDL_GetMouseState(&xMouse,&yMouse);
				
			// }
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		drawObjects(gRenderer, assets);
		drawObjectsflying(gRenderer, assets1);
		drawObjectswalking(gRenderer,assets1);
		drawObjectswalking2(gRenderer,assets1);
		drawObjectsprojectile(gRenderer,assets1);
		

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}
