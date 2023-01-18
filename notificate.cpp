#include "notificate.h"
#include "texture.h"
#include "music.h"

extern SDL_Renderer * gRenderer;

LTexture notifbar;
LTexture ntext;

TTF_Font * nfont = NULL;
SDL_Color textcol = {0, 0, 0, 0xFF};

bool loadMedia_notifbar(){
    nfont = TTF_OpenFont("Fonts/font2.otf", 30);
    if(nfont == NULL){
        printf("Could not load Font\n");
        return false;
    }
    if(!notifbar.loadFromFile("images/notifbar.png")){
        printf("Could not load image\n");
        return false;
    }
    return true;
}

void render_message(std::string s){
    ntext.loadFromRenderedText(s, textcol, nfont);
    SDL_Rect rect;
    rect.h = 200, rect.w = 900;
    rect.x = 1070, rect.y = 0;
    SDL_RenderCopy(gRenderer, notifbar.mTexture, NULL, &rect);

    rect.h = 30, rect.w = ntext.mWidth;
    rect.x = 1180, rect.y = 70;
    SDL_RenderCopy(gRenderer, ntext.mTexture, NULL, &rect);
}
