#include <SDL2/SDL.h>
#include "buildmenu.h"
#include "texture.h"
#include "gFunctions.h"

extern SDL_Renderer * gRenderer;
LTexture buildmenu;
LTexture townhousebuild;
LTexture forestershutbuild;
LTexture minebuild;
LTexture farmbuild, bakerybuild, fisherybuild, churchbuild, barrackbuild, guardtowerbuild;
void render_buildMenu(){
    SDL_Rect rect;
    rect.x = 1000;
    rect.y = 400;
    rect.h = 500;
    rect.w = 800;
    SDL_RenderCopy(gRenderer, buildmenu.mTexture, NULL, &rect);
    rect.x = 1022;
    rect.y = 416;
    rect.w = 108;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, townhousebuild.mTexture, NULL, &rect);
    rect.x = 1175;
    rect.y = 416;
    SDL_RenderCopy(gRenderer, forestershutbuild.mTexture, NULL, &rect);
    rect.x = 1323;
    rect.y = 427;
    rect.w = 100;
    rect.h = 80;
    SDL_RenderCopy(gRenderer, minebuild.mTexture, NULL, &rect);
    rect.x = 1470;
    rect.y = 425;
    rect.w = 120;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, farmbuild.mTexture, NULL, &rect);
    rect.x = 1625;
    rect.y = 415;
    rect.w = 120;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, bakerybuild.mTexture, NULL, &rect);
    rect.x = 1025;
    rect.y = 555;
    rect.w = 120;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, fisherybuild.mTexture, NULL, &rect);
    rect.x = 1170;
    rect.y = 555;
    rect.w = 120;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, churchbuild.mTexture, NULL, &rect);
    rect.x = 1315;
    rect.y = 555;
    rect.w = 120;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, barrackbuild.mTexture, NULL, &rect);
    rect.x = 1470;
    rect.y = 555;
    rect.w = 100;
    rect.h = 100;
    SDL_RenderCopy(gRenderer, guardtowerbuild.mTexture, NULL, &rect);
}
bool loadMedia_buildMenu(){
    if(!buildmenu.loadFromFile("images/buildMenu.png")){
        printf("could not load image for buildmenu\n");
        return false;
    }
    if(!townhousebuild.loadFromFile("images/townhouse.png")){
        printf("could not load image for townhousebuild\n");
        return false;
    }
    if(!forestershutbuild.loadFromFile("images/forestershut.png")){
        printf("could not load image for forestershut\n");
        return false;
    }
    if(!minebuild.loadFromFile("images/mine.png")){
        printf("could not load image for mine\n");
        return false;
    }
    if(!farmbuild.loadFromFile("images/farm.png")){
        printf("could not load image for farm\n");
        return false;
    }
    if(!bakerybuild.loadFromFile("images/bakery.png")){
        printf("could not load image for farm\n");
        return false;
    }
    if(!fisherybuild.loadFromFile("images/fishermanshut.png")){
        printf("could not load image for fisherman\n");
        return false;
    }
    if(!churchbuild.loadFromFile("images/Church.png")){
        printf("could not load image for church\n");
        return false;
    }
    if(!barrackbuild.loadFromFile("images/Barracks.png")){
        printf("could not load image for Barracks\n");
        return false;
    }
    if(!guardtowerbuild.loadFromFile("images/guardtower.png")){
        printf("could not load image for guardtower\n");
        return false;
    }
    return true;
}
bool handleEvent_buildCommand(int x, int y){
    if(x >= 1500 && x <= 1800 && y >= 200 && y <= 700){
        return true;
    }
    return false;
}