#include "options.h"
#include "texture.h"
#include "base.h"
#include "gFunctions.h"

LTexture buildButton;
extern elderTree eldertree;
extern LTexture quitGameButton;
extern SDL_Renderer * gRenderer;

void render_inGameOptions(){
    SDL_Rect rect;
    rect.x = 1700;
    rect.y = 900;
    rect.h = int(eldertree.tex.mHeight*0.5);
    rect.w = int(eldertree.tex.mWidth*0.5);
    SDL_RenderCopy(gRenderer, buildButton.mTexture, NULL, &rect);
    rect.x = 50;
    rect.y = 900;
    rect.h = 120;
    rect.w = 240;
    SDL_RenderCopy(gRenderer, quitGameButton.mTexture, NULL, &rect);
}

bool loadMedia_options(){
    if(!buildButton.loadFromFile("images/buildMenuButton.png")) {
        printf("could not load image for builButton\n");
        return false;
    }
    return true;
}