#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "gFunctions.h"
#include "texture.h"
#include "mainmenu.h"
#include "base.h"
#include "options.h"
#include "buildmenu.h"
#include "buildings.h"
#include "worksmen.h"
#include "bandits.h"
#include "resources.h"
#include "notificate.h"
#include "music.h"

//Screen dimension constants
int SCREEN_WIDTH = 1366;
int SCREEN_HEIGHT = 600;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

state currState;

// Pair strikerLimit[] = {Pair{}};

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
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
		gWindow = SDL_CreateWindow( "Townsville", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow,  -1 ,  SDL_RENDERER_ACCELERATED  | SDL_RENDERER_PRESENTVSYNC );
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
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//mainMenu and UI 
    if(!loadMedia_mainMenu()) return false;

    // ingame base graphics
    if(!loadMedia_base()) return false;

    // ingame options graphics
    if(!loadMedia_options()) return false;

    // buildmenu
    if(!loadMedia_buildMenu()) return false;

	// buildings
	if(!loadMedia_Townhouses()) return false;
	if(!loadMedia_forestersHut()) return false;
	if(!loadMedia_mine()) return false;
	if(!loadMedia_bakery()) return false;
	if(!loadMedia_farm()) return false;
	if(!loadMedia_barracks()) return false;
	if(!loadMedia_fishery()) return false;
	if(!loadMedia_guardTower()) return false;
	if(!loadMedia_prayerHall()) return false;
	if(!loadMedia_banditCamp()) return false;
	if(!init_bandits()) return false;
	if(!loadMedia_guards()) return false;
	if(!loadMedia_notifbar()) return false;
	if(!loadMedia_topbar()) return false;
	// worksman
	if(!loadMedia_Music()) return false;
	// if(!loadMedia_worksman()) return false;

	return true;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
