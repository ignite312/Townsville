#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include "gFunctions.h"
#include "texture.h"
#include "mainmenu.h"
#include "game.h"
#include "worksmen.h"
#include "buildings.h"
#include "maths.h"

using namespace std;


extern int totalTownHouses;
extern townHouses townHouse[50];
extern enum state currState;
extern SDL_Renderer * gRenderer;
bool buildMenuState;
int frame;
bool quit;
int timer;

unsigned long long int Resources, woods, goldCoins, bread, fish, stone, wheat;


int main() 
{
	// Start up SDL and create window
	if (!init())
		printf("Failed to initialize!\n");
	else
	{
		// Load media
		if (!loadMedia())
			printf("Failed to load media!\n");
		else
		{
			// Main loop flag
			quit = false;

			// Event handler
			SDL_Event e;
			// initAllPieces();
            frame = 0;
            buildMenuState = false;
			currState = mainMenu;
			bread = 50, woods = 20, goldCoins = 1000, fish = 20, stone = 80, wheat = 50;
			Resources = bread*5 + woods*10 + goldCoins + fish*5 + stone*15 + wheat*2;
			unsigned currTime, lastTime = 0;
			timer = 0;

			// While application is running
			while (!quit)
			{
				frame++;
				frame%=800;
				while (SDL_PollEvent(&e) != 0)
				{
					
					// User requests quit
					if (e.type == SDL_QUIT)
					{

						quit = true;
					}
                    switch (currState)
                    {
                    case mainMenu:
                        handleEvent_mainMenu(e);
                        break;
                    case game:
    					// cout << buildCommand << endl;
                        buildMenuState = handleEvent_Game(e);
                        break;
                    }
				}
				switch (currState){
					case game:
						handleGame(frame);
						break;
					case mainMenu:
						render_mainMenu();
				}
				currTime = SDL_GetTicks64();
				if(currTime >= lastTime+1000) {
					if(currState == game){
						timer++;
						// cout << timer << endl;
						timeAndResourceManagement();
						timer %= 3600;
					}
					lastTime = currTime;
				}
				// cout << currTime << endl;
				SDL_Delay(10);
			}
		}
	}

	// Free resources and close SDL
	close();

	return 0;
}