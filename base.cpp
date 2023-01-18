#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "base.h"
#include "gFunctions.h"
#include "texture.h"
#include "maths.h"
#include "occspace.h"

extern SDL_Renderer * gRenderer;
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
grassField grassfield[200];
castle Castle;
elderTree eldertree;

void render_grassfield(){
    int gcd = getgcd();
    int k = 0;
    for(int i = -gcd; i < SCREEN_WIDTH; i+=gcd){
        for(int j = -gcd; j < SCREEN_HEIGHT; j+=gcd){
            grassfield[k].tex.render(i, j, NULL, 15, NULL, SDL_FLIP_NONE);
            grassfield[k].rect.x = i;
            grassfield[k].rect.y = j;
            k++;
        }
    }
}

void render_Castle(){
    SDL_Rect rect;
    rect.x = 1200;
    rect.y = 300;
    rect.h = int(eldertree.tex.mHeight*2);
    rect.w = int(eldertree.tex.mWidth*2);
    occupied(rect);
    SDL_RenderCopyEx(gRenderer, Castle.tex.mTexture, NULL, &rect, 10, NULL, SDL_FLIP_NONE);
    rect.x = 1400;
    rect.y = 450;
    rect.h = int(eldertree.tex.mHeight*1.25);
    rect.w = int(eldertree.tex.mWidth*1.25);
    occupied(rect);
    SDL_RenderCopyEx(gRenderer, eldertree.tex.mTexture, NULL, &rect, 10, NULL, SDL_FLIP_NONE);
}

bool loadMedia_base(){
    for(int i = 0; i < 200; i++){
        if(!grassfield[i].tex.loadFromFile("images/grass.jpeg"))
            return false;
        grassfield[i].rect.h = grassfield[i].tex.mHeight;
        grassfield[i].rect.w = grassfield[i].tex.mWidth;
    }
    if(!Castle.tex.loadFromFile("images/castle.png"))
        return false;
    Castle.rect.h = Castle.tex.mHeight;
    Castle.rect.w = Castle.tex.mWidth;
    if(!eldertree.tex.loadFromFile("images/elderTree.png"))
        return false;
    eldertree.rect.h = eldertree.tex.mHeight;
    eldertree.rect.w = eldertree.tex.mWidth;
    return true;
}