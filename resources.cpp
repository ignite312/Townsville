#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
#include "texture.h"
#include "bandits.h"

using namespace std;
extern unsigned long long int Resources;
extern unsigned long long int woods, goldCoins, bread, fish, stone, wheat;
extern SDL_Renderer * gRenderer;
extern int totalBanditKing;
extern int totalUnemployed;

LTexture text;
LTexture topbar;

SDL_Color textCol = {255, 255, 255, 0xFF};
TTF_Font * font = NULL;

bool loadMedia_topbar(){
    if(!topbar.loadFromFile("images/topbar.png")){
        printf("Could not load image\n");
        return false;
    }
    return true;
}

void render_resources(){
    SDL_Rect rect;
    string str;
    font = TTF_OpenFont("Fonts/font2.otf", 30);

    // Bandit Bar
    rect.h = 90, rect.w = 180;
    rect.x = 35, rect.y = 0;
    SDL_RenderCopy(gRenderer, topbar.mTexture, NULL, &rect);
    str = "BanditKings: " + to_string(totalBanditKing);
    rect.x = 75, rect.w = 120;
    rect.y = 30, rect.h = 30;
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    // Resource bar
    rect.h = 90, rect.w = 1200;
    rect.x = 770, rect.y = 0;
    SDL_RenderCopy(gRenderer, topbar.mTexture, NULL, &rect);

    if(font == NULL) {
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }

    rect.y = 30, rect.h = 30;

    str = "Unemployed: " + to_string(totalUnemployed);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1080, rect.w = 120;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "Wheat: " + to_string(wheat);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1220, rect.w = 90;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "Stone: " + to_string(stone);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1330, rect.w = 90;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "Fish: " + to_string(fish);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1440, rect.w = 70;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "Bread: " + to_string(bread);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1530, rect.w = 90;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "Woods: " + to_string(woods);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1640, rect.w = 90;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

    str = "GoldCoins: " + to_string(goldCoins);
    if(!text.loadFromRenderedText(str, textCol, font)){
        printf("Could not load font: %s\n", TTF_GetError());
        SDL_Quit();
    }
    rect.x = 1750, rect.w = 140;
    SDL_RenderCopy(gRenderer, text.mTexture, NULL, &rect);

}