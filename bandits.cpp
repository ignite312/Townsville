#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
#include "bandits.h"
#include "texture.h"
#include "base.h"
#include "game.h"
#include "buildings.h"
#include "occspace.h"
using namespace std;

extern elderTree eldertree;
extern SDL_Renderer *gRenderer;
extern workBuildings workBuilding[100];
extern int totalWorkBuildings;
extern unsigned long long int Resources, woods, goldCoins, bread, fish, stone, wheat;


int totalBanditKing = 3;
banditCamp banditCamps;

bool loadMedia_banditCamp(){
    if(!banditCamps.tex.loadFromFile("images/banditCamp.png")){
        printf("could not load texture for townHouses\n");
        return false;
    }
    banditCamps.rect.h = eldertree.tex.mHeight;
    banditCamps.rect.w = eldertree.tex.mWidth;
    banditCamps.rect.x = banditCamps.posx;
    banditCamps.rect.y = banditCamps.posy;
    return true;
}

void render_banditCamp(){
    occupied(banditCamps.rect);
    SDL_RenderCopy(gRenderer, banditCamps.tex.mTexture, NULL, &banditCamps.rect);
}

const int totalBandits = 5;
bandits bandit[totalBandits];

bool init_bandits(){
    bandit[0].srcx = 100, bandit[0].srcy = 100;
    bandit[1].srcx = 1820, bandit[1].srcy = 100;
    bandit[2].srcx = 100, bandit[2].srcy = 980;
    bandit[3].srcx = 1820, bandit[3].srcy = 980;
    bandit[4].srcx = 1800+rand()%120, bandit[4].srcy = 980+rand()%100;
    for(int i = 0; i < 5; i++){
        if(!bandit[i].frames[0].loadFromFile("images/bandit1.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[1].loadFromFile("images/bandit2.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[2].loadFromFile("images/bandit3.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[3].loadFromFile("images/bandit4.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[4].loadFromFile("images/bandit5.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[5].loadFromFile("images/bandit6.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        if(!bandit[i].frames[6].loadFromFile("images/bandit7.png")){
            printf("Could not load bandit frame\n");
            return false;
        }
        bandit[i].posx = bandit[i].srcx, bandit[i].posy = bandit[i].srcy, bandit[i].flip = SDL_FLIP_NONE;
        bandit[i].rect.h = bandit[i].frames[0].mHeight/5;
        bandit[i].rect.w = bandit[i].frames[0].mWidth/5;
        bandit[i].showframe = 0;
        bandit[i].backing = false;
    }
    return true;
}

void bandits::backdst(){
    int dst[4][2];
    dst[0][0] = 1920;
    dst[0][1] = rand()%1080;
    dst[1][0] = 0;
    dst[1][1] = rand()%1080;
    dst[2][0] = rand()%1920;
    dst[2][1] = 0;
    dst[3][0] = rand()%1920;
    dst[3][1] = 1080;
    int x = rand()%4;
    dstx = dst[x][0];
    dsty = dst[x][1];
    backing = true;
}

void bandits::setdst(){
    if(totalWorkBuildings == 0) return;
    int x = rand()%totalWorkBuildings;
    posx = 1800 + rand()%120;
    posy = 980 + rand()%180;
    dstx = workBuilding[x].posx;
    dsty = workBuilding[x].posy;
    dstb = workBuilding[x].buildingType;
}

void bandits::render(){
    rect.x = posx;
    rect.y = posy;
    SDL_RenderCopyEx(gRenderer, frames[showframe].mTexture, NULL, &rect, 0, NULL, flip);
}

void bandits::raid(int frame){
    if(dstx == posx && dsty == posy){
        if(dstx == 0 || dstx == 1920 || dsty == 0 || dsty == 1080){
            setRaid(-1);
            backing = false;
            return;
        }
        backdst();
        if(dstb == "ForestersHut"){
            if(woods < 50) woods = 0;
            else woods-=50;
        }
        else if(dstb == "Mine"){
            if(stone < 50) stone = 0;
            else stone-=50;
        }
        else if(dstb == "Farm"){
            if(wheat < 30) wheat = 0;
            else wheat-=30;
        }
        else if(dstb == "Bakery"){
            if(bread < 20) bread = 0;
            else bread -= 20;
        }
        else if(dstb == "Fishery"){
            if(fish < 20) fish = 0;
            else fish -= 20;
        }
        else if(dstb == "Guard"){
            //Bad luck Robber
        }
    }
    if(dstx > posx){
        flip = SDL_FLIP_NONE;
        posx++;
    }
    else if(dstx < posx){
        flip = SDL_FLIP_HORIZONTAL;
        posx--;
    }
    if(dsty < posy){
        posy--;
    }
    else posy++;
    if(frame%5 == 0) showframe++;
    showframe%=7;
    render();
}

int getposx(int i){
    return bandit[i].posx;
}
int getposy(int i){
    return bandit[i].posy;
}

bool getbacking(int i){
    return bandit[i].backing;
}

void setbackdst(int i){
    bandit[i].backdst();
}