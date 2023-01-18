#include "buildings.h"
#include "gFunctions.h"
#include "texture.h"
#include <bits/stdc++.h>
#include "buildings.h"
#include "base.h"
#include "occspace.h"
#include "worksmen.h"
#include "game.h"

extern SDL_Renderer* gRenderer;
extern elderTree eldertree;
extern int frame;
extern unsigned long long int stone, woods, goldCoins;

int totalUnemployed = 0;

int totalWorkBuildings = 0;
workBuildings workBuilding[100];

// townhouse
int totalTownHouses = 0;
townHouses townHouse[50];

bool townHouses::checkreq(){
    if(goldCoins < 10||woods < 2){
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalTownHouses > 49){
        toggleMessage("Can't build more townhouses");
    }
    return true;
}

bool loadMedia_Townhouses(){
    for(int i = 0; i < 50; i++){
        if(!townHouse[i].tex.loadFromFile("images/townhouse.png")){
            printf("could not load texture for townHouses\n");
            return false;
        }
        townHouse[i].rect.h = eldertree.tex.mHeight*0.75;
        townHouse[i].rect.w = eldertree.tex.mWidth*0.75;
    }
    return true;
}

void render_townHouses(){
    for(int i = 0; i < totalTownHouses; i++){
        occupied(townHouse[i].rect);
        SDL_RenderCopy(gRenderer, townHouse[i].tex.mTexture, NULL, &townHouse[i].rect);
    }
}

// foresterHut
int totalForestersHut = 0;
forestersHut forestershut[10];

bool forestersHut::checkreq(){
    if(woods < 2||goldCoins < 5||totalUnemployed < 1){
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalForestersHut > 9){
        toggleMessage("Can't build more Forester's Hut");
        return false;
    }
    return true;
}

bool loadMedia_forestersHut(){
    for(int i = 0; i < 10; i++){
        if(!forestershut[i].tex.loadFromFile("images/forestershut.png")){
            printf("could not load image for forestershut\n");
            return false;
        }
        forestershut[i].rect.h = eldertree.tex.mHeight*0.6;
        forestershut[i].rect.w = eldertree.tex.mWidth*0.6;
    }
    return true;
}

void render_forestersHut(int i){
    // for(int i = 0; i < totalForestersHut; i++){
        occupied(forestershut[i].rect);
        SDL_RenderCopy(gRenderer, forestershut[i].tex.mTexture, NULL, &forestershut[i].rect);
    // }
}

// Mines
int totalmines = 0;
mine mines[2];

bool mine::checkreq(){
    if(woods < 7||goldCoins < 15||totalUnemployed < 2||stone < 5){
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalmines > 1){
        toggleMessage("Can't build more mines");
        return false;
    }
    return true;
}

bool loadMedia_mine(){
    for(int i = 0; i < 2; i++){
        if(!mines[i].tex.loadFromFile("images/mine.png")){
            printf("could not load image for mine\n");
            return false;
        }
        mines[i].rect.h = eldertree.tex.mHeight*0.75;
        mines[i].rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_mine(int i){
    occupied(mines[i].rect);
    SDL_RenderCopy(gRenderer, mines[i].tex.mTexture, NULL, &mines[i].rect);
}

// Farms
int totalfarms = 0;
farm farms[5];

bool farm::checkreq(){
    if(woods < 7||goldCoins < 10||totalUnemployed < 2){
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalfarms > 4){
        toggleMessage("Can't build more farms");
        return false;
    }
    return true;
}

bool loadMedia_farm(){
    for(int i = 0; i < 5; i++){
        if(!farms[i].tex.loadFromFile("images/farm.png")){
            printf("could not load image for farm\n");
            return false;
        }
        farms[i].rect.h = eldertree.tex.mHeight*0.75;
        farms[i].rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_farm(int i){
    occupied(farms[i].rect);
    SDL_RenderCopy(gRenderer, farms[i].tex.mTexture, NULL, &farms[i].rect);
}

// Bakery
int totalbakeries = 0;
bakery bakeries[5];

bool bakery::checkreq(){
    if(woods < 7||goldCoins < 10||totalUnemployed < 1) {
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalbakeries > 4){
        toggleMessage("Can't build more bakeries");
        return false;
    }
    return true;
}

bool loadMedia_bakery(){
    for(int i = 0; i < 5; i++){
        if(!bakeries[i].tex.loadFromFile("images/bakery.png")){
            printf("could not load image for bakery\n");
            return false;
        }
        bakeries[i].rect.h = eldertree.tex.mHeight*0.75;
        bakeries[i].rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_bakery(int i){
    occupied(bakeries[i].rect);
    SDL_RenderCopy(gRenderer, bakeries[i].tex.mTexture, NULL, &bakeries[i].rect);
}

// Fishery
int totalfisheries = 0;
fishery fisheries[5];

bool fishery::checkreq(){
    if(woods < 7||goldCoins < 10||totalUnemployed < 1) {
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalfisheries > 4){
        toggleMessage("Can't build more fisheries");
        return false;
    }
    return true;
}

bool loadMedia_fishery(){
    for(int i = 0; i < 5; i++){
        if(!fisheries[i].tex.loadFromFile("images/fishermanshut.png")){
            printf("could not load image for fishery\n");
            return false;
        }
        fisheries[i].rect.h = eldertree.tex.mHeight*0.75;
        fisheries[i].rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_fishery(int i){
    occupied(fisheries[i].rect);
    SDL_RenderCopy(gRenderer, fisheries[i].tex.mTexture, NULL, &fisheries[i].rect);
}

// Praying hall
int totalPrayingHall = 0;
prayerHall prayingHall;

bool prayerHall::checkreq(){
    if(woods < 15||goldCoins < 200||stone < 15) {
        toggleMessage("Not Enough Resources");
        return false;
    }
    if(totalPrayingHall > 0){
        toggleMessage("Can't build more prayer Halls");
        return false;
    }
    return true;
}

bool loadMedia_prayerHall(){
    for(int i = 0; i < 1; i++){
        if(!prayingHall.tex.loadFromFile("images/Church.png")){
            printf("could not load image for prayerHall\n");
            return false;
        }
        prayingHall.rect.h = eldertree.tex.mHeight*0.75;
        prayingHall.rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_prayerHall(){
    occupied(prayingHall.rect);
    SDL_RenderCopy(gRenderer, prayingHall.tex.mTexture, NULL, &prayingHall.rect);
}

// Barracks
int totalBarracks = 0;
barracks barrackss;

bool barracks::checkreq(){
    if(woods < 25||goldCoins < 400||stone < 25) {
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalBarracks > 0){
        toggleMessage("Can't build more Barracks");
        return false;
    }
    return true;
}

bool loadMedia_barracks(){
    for(int i = 0; i < 1; i++){
        if(!barrackss.tex.loadFromFile("images/Barracks.png")){
            printf("could not load image for barracks\n");
            return false;
        }
        barrackss.rect.h = eldertree.tex.mHeight*0.75;
        barrackss.rect.w = eldertree.tex.mWidth*0.9;
    }
    return true;
}

void render_barracks(){
    occupied(barrackss.rect);
    SDL_RenderCopy(gRenderer, barrackss.tex.mTexture, NULL, &barrackss.rect);
}


// guardTower
int totalguardTowers = 0;
guardTower guardTowers[10];

bool guardTower::checkreq(){
    if(woods < 10||goldCoins < 50||totalBarracks < 1||stone<10) {
        toggleMessage("Not enough resources");
        return false;
    }
    if(totalguardTowers > 9){
        toggleMessage("Can't build more guardTowers");
        return false;
    }
    return true;
}

bool loadMedia_guardTower(){
    for(int i = 0; i < 10; i++){
        if(!guardTowers[i].tex.loadFromFile("images/guardtower.png")){
            printf("could not load image for guardTower\n");
            return false;
        }
        guardTowers[i].rect.h = eldertree.tex.mHeight*0.9;
        guardTowers[i].rect.w = eldertree.tex.mWidth*0.75;
    }
    return true;
}

void render_guardTower(){
    for(int i = 0; i < totalguardTowers; i++){
        occupied(guardTowers[i].rect);
        SDL_RenderCopy(gRenderer, guardTowers[i].tex.mTexture, NULL, &guardTowers[i].rect);
    }
}

void render_buildings(){
    for(int i = 0; i < totalWorkBuildings; i++){
        if(workBuilding[i].buildingType == "ForestersHut"){
            render_forestersHut(workBuilding[i].idx);
        }
        else if(workBuilding[i].buildingType == "Mine"){
            render_mine(workBuilding[i].idx);
        }
        else if(workBuilding[i].buildingType == "Farm"){
            render_farm(workBuilding[i].idx);
        }
        else if(workBuilding[i].buildingType == "Bakery"){
            render_bakery(workBuilding[i].idx);
        }
        else if(workBuilding[i].buildingType == "Fishery"){
            render_fishery(workBuilding[i].idx);
        }
        // else if(workBuilding[i].buildingType == "Guard"){
        //     render_guardTower(workBuilding[i].idx);
        // }
    }
}