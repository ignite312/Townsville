#ifndef BASE_H
#define BASE_H

#include "texture.h"

class grassField{
    public:
    LTexture tex;
    SDL_Rect rect;
};

class castle{
    public:
    LTexture tex;
    SDL_Rect rect;
};

class elderTree{
    public:
    LTexture tex;
    SDL_Rect rect;
};

bool loadMedia_base();
void render_base();
void render_grassfield();
void render_Castle();

#endif
