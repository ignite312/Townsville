#ifndef BANDIT_H
#define BANDIT_H

#include "texture.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <bits/stdc++.h>

bool loadMedia_banditCamp();
void render_banditCamp();
struct banditCamp{
    int posx = 100, posy = 100;
    LTexture tex;
    SDL_Rect rect;
};

int getposx(int i);
int getposy(int i);
bool getbacking(int i);
void setbackdst(int i);
bool init_bandits();
struct bandits{
    LTexture frames[7];
    int showframe;
    bool backing;
    SDL_Rect rect;
    SDL_RendererFlip flip;
    int srcx, srcy;
    int posx, posy;
    int dstx, dsty;
    std::string dstb;
    void setdst();
    void backdst();
    void raid(int frame);
    void render();
};

#endif