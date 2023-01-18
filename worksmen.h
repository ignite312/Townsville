#ifndef WORKSMEN_H
#define WORKSMEN_H
#include "texture.h"

struct worksmen
{
    int srcx, srcy;
    int dstx, dsty;
    int posx, posy;
    int showframe;
    bool isEmployed;
    SDL_RendererFlip flip;
    LTexture walkframes[7];
    // LTexture workingframes[3];
    // LTexture tex;
    SDL_Rect rect;

};

void initworksman(int i, int j);
bool loadMedia_worksman(int i, int j);
void handleWorksmen(int frame, int i, int j);
void render_worksman(int i, int j);

bool loadMedia_guards();
struct guard{
    LTexture frames[7];
    int showframe;
    SDL_Rect rect;
    SDL_RendererFlip flip;
    int srcx, srcy;
    int posx, posy;
    int dstx, dsty;
    std::string dstb;
    void setsrc(int x, int y);
    void setdst(int x, int y);
    void backdst();
    void handle(int frame);
    void render();
};

#endif