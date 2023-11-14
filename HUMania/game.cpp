#include "game.hpp"
#include "HUMania.hpp"
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

	


	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                gTexture = loadTexture("gameBG.jpg");
				createObject(50, 100);
				drawObjects(gRenderer, assets);
            }

//working on this line here changing functionality to q key
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q) {
				SDL_DestroyTexture(assets);
	    		SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds

				
	    			//causes sdl engine to delay for specified miliseconds
				
				//SDL_RenderClear(gTexture);
                gTexture = loadTexture("SuperManGameOver.png");
				createObject(50, 100);
				drawObjects(gRenderer, assets);
				SDL_Delay(200);
				//quit = true;
            }
	


			if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        std::cout << "Up arrow key pressed!" << std::endl;
                        moveUp();
                        up(gRenderer, assets);
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down arrow key pressed!" << std::endl;
                        moveDown();
                        down(gRenderer, assets);
                        break;
                    case SDLK_LEFT:
                        std::cout << "Left arrow key pressed!" << std::endl;
                        moveLeft();
                        left(gRenderer, assets);
                        break;
                    case SDLK_RIGHT:
                        std::cout << "Right arrow key pressed!" << std::endl;
                        moveRight();
                        drawObjects(gRenderer, assets);
                        break;
                    case SDLK_l:
                        std::cout << "L key pressed!" << std::endl;
                        animation(gRenderer, assets);
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
		

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}
