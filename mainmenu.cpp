#include <bits/stdc++.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "mainmenu.h"
#include "texture.h"
#include "game.h"
#include "gFunctions.h"
#include "music.h"

extern SDL_Renderer * gRenderer;
extern bool quit;
extern state currState;
LTexture mainMenuScreen;
LTexture startGameButton;
LTexture quitGameButton;

// Text renderer
SDL_Color TextColor = {245, 205, 60, 0xFF};
TTF_Font* gFont = NULL;
LTexture Title;

// Audio renderer
Mix_Music *mainMenuTheme = NULL;
Mix_Music *BGM2 = NULL;


void handleEvent_mainMenu(SDL_Event e){
    // render_mainMenu();
    int x, y;
    SDL_GetMouseState(&x, &y);
        // printf("%d %d\n", x, y);
        if(e.type == SDL_MOUSEBUTTONUP){
            if(x >= 1250 && x <= 1520 && y >= 280 && y <= 365 && e.key.repeat == 0){
                play_clickSound();
                currState = game;
            }
            else if(x >= 161 && x <= 361 && y >= 832 && y <= 919 && e.key.repeat == 0){
                play_clickSound();
                quit = true;
                return;
            }
        }
    // }
}

void render_mainMenu(){
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, mainMenuScreen.mTexture, NULL, NULL);
    startGameButton.render(1200, 150, NULL, 0, NULL, SDL_FLIP_NONE);
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 800;
    rect.h = 170;
    rect.w = 300;
    SDL_RenderCopy(gRenderer, quitGameButton.mTexture, NULL, &rect);
    rect.x = 1000;
    rect.y = 800;
    rect.h = 170;
    rect.w = 700;
    SDL_RenderCopy(gRenderer, Title.mTexture, NULL, &rect);
    SDL_RenderPresent(gRenderer);
}

bool loadMedia_mainMenu(){
    if(!mainMenuScreen.loadFromFile("images/mainMenu.jpeg")){
        printf("Could not load image for mainMenuScreen\n");
        return false;
    }
    if(!startGameButton.loadFromFile("images/startGameButton.png")){
        printf("Could not load image for startGameButton\n");
        return false;
    }
    if(!quitGameButton.loadFromFile("images/quitGameButton.png")){
        printf("Could not load image for quitGameButton\n");
        return false;
    }


    gFont = TTF_OpenFont("Fonts/font.ttf", 28);
	if (gFont == NULL)
	{
		printf("Can not open the font %s\n", TTF_GetError());
		return false;
	}
	if(!Title.loadFromRenderedText("TOWNSVILLE", TextColor, gFont)){
		printf("Text Render Failed");
		return false;
	}


    mainMenuTheme = Mix_LoadMUS("Music/Slavic Lands.mp3");
    BGM2 = Mix_LoadMUS("Music/Cobblestone Village.mp3");
    if(mainMenuTheme == NULL || BGM2 == NULL){
        printf("Could not load sound\n");
        return false;
    }

    play_backgroundMusic();
    return true;
}

void play_backgroundMusic(){
    if(Mix_PlayingMusic != 0){
        Mix_HaltMusic();
        Mix_PlayMusic(mainMenuTheme, -1);
    }
}