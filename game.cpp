#include <bits/stdc++.h>
#include <SDL2/SDL_mixer.h>
#include "options.h"
#include "game.h"
#include "gFunctions.h"
#include "base.h"
#include "buildmenu.h"
#include "build.h"
#include "buildings.h"
#include "worksmen.h"
#include "maths.h"
#include "resources.h"
#include "bandits.h"
#include "notificate.h"
#include "music.h"
using namespace std;


extern int totalTownHouses, totalBarracks, totalPrayingHall, totalWorkBuildings, totalGuards;
extern unsigned int Resources;
extern guard guards[50];
extern townHouses townHouse[50];
extern bandits bandit[5];
extern SDL_Renderer * gRenderer;
extern state currState;
extern bool buildMenuState;
string buildCommand = "NULL";
LTexture page1;
bool message = false;
string str = "";
int notiftime = 0;
int bandittimer = 0;
int raid = 0;
int musicflag = 0;

void toggleMessage(string s){
    message = !message;
    if(message){
        play_warning();
    }
    str = s;
}
void setRaid(int x){
    for(int i = 0; i < x; i++){
        bandit[i].setdst();
    }
    raid += x;
}

bool handleEvent_Game(SDL_Event e){
    if(buildMenuState == true){
        // render_buildMenu();
        // SDL_RenderPresent(gRenderer);
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            printf("%d %d\n", x, y);
            if(x >= 1705 && x <= 1792 && y >= 908 && y <= 985){
                play_clickSound();
                buildMenuState = !buildMenuState;
            }
            else if(buildMenuState == true){
                if(x >= 1000 && x <= 1800 && y >= 400 && y <= 900){
                    printf("inside buildMenu: %d %d\n", x, y);
                    if(x >= 1022 && x <= 1130 && y >= 416 && y <= 516){
                        play_clickSound();
                        buildCommand = "townHouse";
                        return false;
                    }
                    if(x >= 1175 && x <= 1283 && y >= 416 && y <= 516){
                        play_clickSound();
                        buildCommand = "forestershut";
                        return false;
                    }
                    if(x >= 1323 && x <= 1406 && y >= 427 && y <= 498){
                        play_clickSound();
                        buildCommand = "mine";
                        return false;
                    }
                    if(x >= 1470 && x <= 1590 && y >= 425 && y <= 525){
                        play_clickSound();
                        buildCommand = "farm";
                        return false;
                    }
                    if(x >=1625 && x <= 1725 && y >= 415 && y <= 515){
                        play_clickSound();
                        buildCommand = "bakery";
                        return false;
                    }
                    if(x >=1025 && x <= 1145 && y >= 555 && y <= 655){
                        play_clickSound();
                        buildCommand = "fishery";
                        return false;
                    }
                    if(x >=1170 && x <= 1290 && y >= 555 && y <= 655){
                        play_clickSound();
                        buildCommand = "church";
                        return false;
                    }
                    if(x >=1315 && x <= 1435 && y >= 555 && y <= 655){
                        play_clickSound();
                        buildCommand = "barracks";
                        return false;
                    }
                    if(x >=1465 && x <= 1565 && y >= 555 && y <= 655){
                        play_clickSound();
                        buildCommand = "guard";
                        return false;
                    }
                }
            }
        }
    }
    else{
        // SDL_RenderPresent(gRenderer);
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(e.type == SDL_MOUSEBUTTONUP && e.key.repeat == 0){
            printf("%d %d\n", x, y);
            if(x >= 1705 && x <= 1792 && y >= 908 && y <= 985){
                play_selectionGame();
                buildMenuState = !buildMenuState;
            }
            else if(x >= 70 && x <= 270 && y >= 920 && y <= 1000 && e.key.repeat == 0){
                play_selectionGame();
                currState = mainMenu;
            }
        }
        if(buildCommand != "NULL"){
            buildCommand = build(buildCommand, e);
            return false;
        }
    }
    return buildMenuState;
}

void handleGame(int frame){
    SDL_RenderClear(gRenderer);
    if(musicflag == 0){
        Mix_HaltMusic();
        play_BGM();
        musicflag = 1;
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    Resources = calculateResources();
    // timeAndResourceManagement();
    // cout << Resources << endl;
    render_grassfield();
    bandittimer++;
    if(bandittimer == 1250 || totalWorkBuildings == 0){
        bandittimer = 0;
        if(totalWorkBuildings) calcraid();
    }
    // raid = 5;
    if(raid){
        bandittimer = 0;
        for(int i = 0; i < raid; i++){
            bandit[i].raid(frame);
        }
    }
    for(int i = 0; i < totalTownHouses; i++){
        // cout << "worksman " << 0 << ": " << townHouse[i].worksman[0].isEmployed << endl;
        // cout << "worksman " << 1 << ": " << townHouse[i].worksman[1].isEmployed << endl;
        handleWorksmen(frame, i, 0);
        handleWorksmen(frame, i, 1);
        // SDL_RenderCopy(gRenderer, townHouse[i].worksman[0].walkframes[0].mTexture, NULL, &townHouse[i].worksman[0].rect);
    }
    render_banditCamp();
    render_Castle();
    // SDL_RenderCopy(gRenderer, townHouse[0].worksman[0].walkframes[0].mTexture, NULL, &townHouse[0].worksman[0].rect);
    render_townHouses();
    if(totalPrayingHall) render_prayerHall();
    if(totalBarracks) render_barracks();
    render_guardTower();
    for(int i = 0; i < totalGuards; i++){
        guards[i].handle(frame);
        guards[i].render();
    }
    render_buildings();

    render_inGameOptions();
    render_resources();
    if(message){
        notiftime++;
        // cout << "true to" << endl;
        render_message(str);
        if(notiftime == 200) {
            notiftime = 0;
            toggleMessage("");
        }
    }
    if(buildMenuState == true){
        render_buildMenu();
    }
    SDL_RenderPresent(gRenderer);
}