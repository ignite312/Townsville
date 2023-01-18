#include "texture.h"
#include "gFunctions.h"
#include "worksmen.h"
#include "game.h"
#include "buildings.h"
#include "bandits.h"

extern SDL_Renderer * gRenderer;
extern townHouses townHouse[50];
extern forestersHut forestershut[10];
extern workBuildings workBuilding[100];
extern int totalTownHouses;
extern int totalWorkBuildings;
extern int totalForestersHut;
// extern bandits bandit[5];

void initworksman(int i, int j){
    if(!loadMedia_worksman(i, j)) return;
    townHouse[i].worksman[j].posx = townHouse[i].worksman[j].srcx;
    townHouse[i].worksman[j].posy = townHouse[i].worksman[j].srcy;
    townHouse[i].worksman[j].rect.h = townHouse[i].worksman[j].walkframes[0].mHeight/6;
    townHouse[i].worksman[j].rect.w = townHouse[i].worksman[j].walkframes[0].mWidth/6;
    printf(" size %d %d\n", townHouse[i].worksman[j].rect.h, townHouse[i].worksman[j].rect.w);
    townHouse[i].worksman[j].showframe = 0;
    townHouse[i].worksman[j].isEmployed = false;
    townHouse[i].worksman[j].flip = SDL_FLIP_NONE;
}

void handleWorksmen(int frame, int i, int j){
    for(int i = 0; i < totalWorkBuildings && i <= totalTownHouses+totalTownHouses; i++){
        townHouse[i/2].worksman[i%2].dstx = workBuilding[i].posx;
        townHouse[i/2].worksman[i%2].dsty = workBuilding[i].posy;
        townHouse[i/2].worksman[i%2].isEmployed = true;
    }
    if(townHouse[i].worksman[j].dstx == townHouse[i].worksman[j].posx && townHouse[i].worksman[j].dsty == townHouse[i].worksman[j].posy){
        townHouse[i].worksman[j].isEmployed = false;
    }
    if(!townHouse[i].worksman[j].isEmployed) return;
    if(townHouse[i].worksman[j].posx < townHouse[i].worksman[j].dstx){
        townHouse[i].worksman[j].posx++;
        townHouse[i].worksman[j].flip = SDL_FLIP_NONE;
    }
    else if(townHouse[i].worksman[j].posx > townHouse[i].worksman[j].dstx){
        townHouse[i].worksman[j].posx--;
        townHouse[i].worksman[j].flip = SDL_FLIP_HORIZONTAL;
    }
    if(townHouse[i].worksman[j].posy < townHouse[i].worksman[j].dsty){
        townHouse[i].worksman[j].posy++;
    }
    if(townHouse[i].worksman[j].posy > townHouse[i].worksman[j].dsty){
        townHouse[i].worksman[j].posy--;
    }
    if(frame%5 == 0) {
        townHouse[i].worksman[j].showframe++;
        townHouse[i].worksman[j].showframe %= 7;
    }
    render_worksman(i, j);
}

void render_worksman(int i, int j){
    // SDL_RenderClear(gRenderer);
    townHouse[i].worksman[j].rect.x = townHouse[i].worksman[j].posx;
    townHouse[i].worksman[j].rect.y = townHouse[i].worksman[j].posy;
    SDL_RenderCopyEx(gRenderer, townHouse[i].worksman[j].walkframes[townHouse[i].worksman[j].showframe].mTexture, NULL, &townHouse[i].worksman[j].rect, 0, NULL, townHouse[i].worksman[j].flip);
    // SDL_RenderPresent(gRenderer);
    // printf("%d %d %d %d\n", townHouse[i].worksman[j].rect.x, townHouse[i].worksman[j].rect.y, townHouse[i].worksman[j].rect.h, townHouse[i].worksman[j].rect.w);
}

bool loadMedia_worksman(int i, int j){
    if(!townHouse[i].worksman[j].walkframes[0].loadFromFile("images/walkframe1.png")){
        printf("could not load image for walkframe1\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[1].loadFromFile("images/walkframe2.png")){
        printf("could not load image for walkframe2\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[2].loadFromFile("images/walkframe3.png")){
        printf("could not load image for walkframe3\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[3].loadFromFile("images/walkframe4.png")){
        printf("could not load image for walkframe4\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[4].loadFromFile("images/walkframe5.png")){
        printf("could not load image for walkframe5\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[5].loadFromFile("images/walkframe6.png")){
        printf("could not load image for walkframe6\n");
        return false;
    }
    if(!townHouse[i].worksman[j].walkframes[6].loadFromFile("images/walkframe7.png")){
        printf("could not load image for walkframe7\n");
        return false;
    }
    return true;
}

int totalGuards = 0;
guard guards[50];

bool loadMedia_guards(){
    for(int i = 0; i < 50; i++){
        if(!guards[i].frames[0].loadFromFile("images/guard1.png")){
            return false;
        }
        if(!guards[i].frames[1].loadFromFile("images/guard2.png")){
            return false;
        }
        if(!guards[i].frames[2].loadFromFile("images/guard3.png")){
            return false;
        }
        if(!guards[i].frames[3].loadFromFile("images/guard4.png")){
            return false;
        }
        if(!guards[i].frames[4].loadFromFile("images/guard5.png")){
            return false;
        }
        if(!guards[i].frames[5].loadFromFile("images/guard6.png")){
            return false;
        }
        if(!guards[i].frames[6].loadFromFile("images/guard7.png")){
            return false;
        }
        guards[i].rect.h = guards[i].frames[0].mHeight/5;
        guards[i].rect.w = guards[i].frames[0].mWidth/5;
        guards[i].showframe = 0;
    }
    return true;
}

void guard::setsrc(int x, int y){
    posx = srcx = x;
    posy = srcy = y;
}

void guard::render(){
    rect.x = posx;
    rect.y = posy;
    SDL_RenderCopyEx(gRenderer, frames[showframe].mTexture, NULL, &rect, 0, NULL, flip);
}

long long int distance(int x, int y, int posx, int posy){
    return (x - posx)*1ll*(x - posx) + (y - posy)*1ll*(y - posy);
}

void guard::backdst(){
    dstx = srcx;
    dsty = srcy;
}

void guard::setdst(int x, int y){
    dstx = x;
    dsty = y;
}

void guard::handle(int frame){
    int idx = 0;
    long long int min = INT_MAX, minx = 20, miny = 40;
    for(int i = 0; i < 5; i++){
        int x = getposx(i);
        int y = getposy(i);
        if(distance(x, y, posx, posy) < min && getbacking(i) == false){
            idx = i;
            min = distance(x, y, posx, posy);
            minx = x;
            miny = y;
        }
    }
    if(min < 400){
        if(frame%5 == 0) showframe++;
        showframe %= 7;
        setdst(minx, miny);
        if(posx == dstx && posy == dsty){
            setbackdst(idx);
            backdst();
        }
        if(posx > dstx){
            flip = SDL_FLIP_HORIZONTAL;
            posx--;
        }
        else if(posx < dstx){
            flip = SDL_FLIP_NONE;
            posx++;
        }
        if(posy < dsty) posy++;
        else posy--;
    }
    else {
        showframe = 0;
        posx = srcx;
        posy = srcy;
    }
}