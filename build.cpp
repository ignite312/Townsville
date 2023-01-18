#include "build.h"
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "buildings.h"
#include "occspace.h"
#include "notificate.h"
#include "music.h"
#include "game.h"
#include "worksmen.h"

using namespace std;

extern int totalWorkBuildings, totalUnemployed;
extern int totalTownHouses;
extern int totalGuards;
extern int totalForestersHut, totalmines, totalfarms, totalbakeries, totalfisheries, totalguardTowers;
extern int totalPrayingHall, totalBarracks;
extern unsigned long long int stone, woods, goldCoins;
extern townHouses townHouse[50];
extern forestersHut forestershut[10];
extern workBuildings workBuilding[100];
extern farm farms[5];
extern mine mines[2];
extern bakery bakeries[5];
extern fishery fisheries[5];
extern prayerHall prayingHall;
extern barracks barrackss;
extern guardTower guardTowers[10];
extern guard guards[50];


string build(string buildCommand, SDL_Event e){
    if(buildCommand == "townHouse"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!townHouse[totalTownHouses].checkreq()){
                    printf("Not enough Resources\n");

                    return "NULL";
                }
                play_clickSound();
                totalTownHouses++;
                totalUnemployed+=2;
                woods -= 2;
                goldCoins -= 10;
                townHouse[totalTownHouses-1].rect.x = x-townHouse[totalTownHouses-1].rect.w/2;
                townHouse[totalTownHouses-1].rect.y = y-townHouse[totalTownHouses-1].rect.h/2;
                townHouse[totalTownHouses-1].posx = townHouse[totalTownHouses-1].worksman[0].srcx = x;
                townHouse[totalTownHouses-1].posy = townHouse[totalTownHouses-1].worksman[0].srcy = y;
                initworksman(totalTownHouses-1, 0);
                townHouse[totalTownHouses-1].posx = townHouse[totalTownHouses-1].worksman[1].srcx = x;
                townHouse[totalTownHouses-1].posy = townHouse[totalTownHouses-1].worksman[1].srcy = y;
                initworksman(totalTownHouses-1, 1);
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "forestershut"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!forestershut[totalForestersHut].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalForestersHut++;
                totalUnemployed-=1;
                workBuilding[totalWorkBuildings].buildingType = "ForestersHut";
                workBuilding[totalWorkBuildings].idx = totalForestersHut-1;
                workBuilding[totalWorkBuildings].pTime = workBuilding[totalWorkBuildings].qTime = 0;
                totalWorkBuildings++;
                woods -= 2;
                goldCoins -= 5;
                forestershut[totalForestersHut-1].rect.x = x-forestershut[totalForestersHut-1].rect.w/2;
                forestershut[totalForestersHut-1].rect.y = y-forestershut[totalForestersHut-1].rect.h/2;
                forestershut[totalForestersHut-1].posx = x;
                forestershut[totalForestersHut-1].posy = y;
                workBuilding[totalWorkBuildings-1].posx = x;
                workBuilding[totalWorkBuildings-1].posy = y;
                workBuilding[totalWorkBuildings-1].rect = forestershut[totalForestersHut-1].rect;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "mine"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!mines[totalmines].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalmines++;
                totalUnemployed-=2;
                workBuilding[totalWorkBuildings].buildingType = "Mine";
                workBuilding[totalWorkBuildings].idx = totalmines-1;
                workBuilding[totalWorkBuildings].pTime = workBuilding[totalWorkBuildings].qTime = 0;
                totalWorkBuildings++;
                woods -= 7;
                goldCoins -= 15;
                stone -= 5;
                mines[totalmines-1].rect.x = x-mines[totalmines-1].rect.w/2;
                mines[totalmines-1].rect.y = y-mines[totalmines-1].rect.h/2;
                mines[totalmines-1].posx = x;
                mines[totalmines-1].posy = y;
                workBuilding[totalWorkBuildings-1].posx = x;
                workBuilding[totalWorkBuildings-1].posy = y;
                workBuilding[totalWorkBuildings-1].rect = mines[totalmines-1].rect;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "farm"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!farms[totalfarms].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalfarms++;
                totalUnemployed-=2;
                workBuilding[totalWorkBuildings].buildingType = "Farm";
                workBuilding[totalWorkBuildings].idx = totalfarms-1;
                workBuilding[totalWorkBuildings].pTime = workBuilding[totalWorkBuildings].qTime = 0;
                totalWorkBuildings++;
                woods -= 7;
                goldCoins -= 10;
                farms[totalfarms-1].rect.x = x-farms[totalfarms-1].rect.w/2;
                farms[totalfarms-1].rect.y = y-farms[totalfarms-1].rect.h/2;
                farms[totalfarms-1].posx = x;
                farms[totalfarms-1].posy = y;
                workBuilding[totalWorkBuildings-1].posx = x;
                workBuilding[totalWorkBuildings-1].posy = y;
                workBuilding[totalWorkBuildings-1].rect = farms[totalfarms-1].rect;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "bakery"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!bakeries[totalbakeries].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalbakeries++;
                totalUnemployed-=1;
                workBuilding[totalWorkBuildings].buildingType = "Bakery";
                workBuilding[totalWorkBuildings].idx = totalbakeries-1;
                workBuilding[totalWorkBuildings].pTime = workBuilding[totalWorkBuildings].qTime = 0;
                totalWorkBuildings++;
                woods -= 7;
                goldCoins -= 10;
                bakeries[totalbakeries-1].rect.x = x-bakeries[totalbakeries-1].rect.w/2;
                bakeries[totalbakeries-1].rect.y = y-bakeries[totalbakeries-1].rect.h/2;
                bakeries[totalbakeries-1].posx = x;
                bakeries[totalbakeries-1].posy = y;
                workBuilding[totalWorkBuildings-1].posx = x;
                workBuilding[totalWorkBuildings-1].posy = y;
                workBuilding[totalWorkBuildings-1].rect = bakeries[totalbakeries-1].rect;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "fishery"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!fisheries[totalfisheries].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalfisheries++;
                totalUnemployed-=1;
                workBuilding[totalWorkBuildings].buildingType = "Fishery";
                workBuilding[totalWorkBuildings].idx = totalfisheries-1;
                workBuilding[totalWorkBuildings].pTime = workBuilding[totalWorkBuildings].qTime = 0;
                totalWorkBuildings++;
                woods -= 7;
                goldCoins -= 10;
                fisheries[totalfisheries-1].rect.x = x-fisheries[totalfisheries-1].rect.w/2;
                fisheries[totalfisheries-1].rect.y = y-fisheries[totalfisheries-1].rect.h/2;
                fisheries[totalfisheries-1].posx = x;
                fisheries[totalfisheries-1].posy = y;
                workBuilding[totalWorkBuildings-1].posx = x;
                workBuilding[totalWorkBuildings-1].posy = y;
                workBuilding[totalWorkBuildings-1].rect = fisheries[totalfisheries-1].rect;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "guard"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            play_clickSound();
            if(!isOccupied(x, y)){
                if(!guardTowers[totalguardTowers].checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalguardTowers++;
                totalGuards += 2;
                woods -= 10;
                goldCoins -= 50;
                stone -= 10;
                guardTowers[totalguardTowers-1].rect.x = x-guardTowers[totalguardTowers-1].rect.w/2;
                guardTowers[totalguardTowers-1].rect.y = y-guardTowers[totalguardTowers-1].rect.h/2;
                guardTowers[totalguardTowers-1].posx = x;
                guardTowers[totalguardTowers-1].posy = y;
                guards[totalGuards-1].setsrc(x-30, y+guardTowers[totalguardTowers-1].rect.h/2);
                guards[totalGuards-2].setsrc(x, y+guardTowers[totalguardTowers-1].rect.h/2);
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "church"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!prayingHall.checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalPrayingHall++;
                woods -= 15;
                goldCoins -= 200;
                stone -= 15;
                prayingHall.rect.x = x-prayingHall.rect.w/2;
                prayingHall.rect.y = y-prayingHall.rect.h/2;
                prayingHall.posx = x;
                prayingHall.posy = y;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    else if(buildCommand == "barracks"){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            if(!isOccupied(x, y)){
                if(!barrackss.checkreq()){
                    printf("Not Enough Resources\n");
                    return "NULL";
                }
                play_clickSound();
                totalBarracks++;
                woods -= 25;
                goldCoins -= 400;
                stone -= 25;
                barrackss.rect.x = x-barrackss.rect.w/2;
                barrackss.rect.y = y-barrackss.rect.h/2;
                barrackss.posx = x;
                barrackss.posy = y;
                return "NULL";
            }
            else{
                toggleMessage("Try a little further from other objects");
            }
        }
    }
    return buildCommand;
}
