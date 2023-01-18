#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <bits/stdc++.h>
#include "worksmen.h"
#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void render_buildings();
struct workBuildings{
    std::string buildingType;
    int posx, posy;
    SDL_Rect rect;
    int idx;
    int pTime, qTime;
};

bool loadMedia_Townhouses();
void render_townHouses();
struct townHouses{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    worksmen worksman[2];
    bool checkreq();
};

bool loadMedia_forestersHut();
void render_forestersHut(int i);
struct forestersHut{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_mine();
void render_mine(int i);
struct mine{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_farm();
void render_farm(int i);
struct farm{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_bakery();
void render_bakery(int i);
struct bakery{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_fishery();
void render_fishery(int i);
struct fishery{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_prayerHall();
void render_prayerHall();
struct prayerHall{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_barracks();
void render_barracks();
struct barracks{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};

bool loadMedia_guardTower();
void render_guardTower();
struct guardTower{
    int posx, posy;
    LTexture tex;
    SDL_Rect rect;
    bool checkreq();
};


#endif