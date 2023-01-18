#include "gFunctions.h"
#include "texture.h"
#include "base.h"

bool occupiedspace[1921][1081];
extern elderTree eldertree;
void occupied(SDL_Rect rect){
    for(int i = rect.x; i <= rect.x+rect.w && i <= 1920; i++){
        for(int j = rect.y; j <= rect.y+rect.h && j <= 1080; j++){
            occupiedspace[i][j] = true;
        }
    }
}

bool isOccupied(int x, int y){
    int lx = x-(eldertree.tex.mWidth*0.25);
    int mx = x+(eldertree.tex.mWidth*0.25);
    int ly = y-(eldertree.tex.mHeight*0.25);
    int my = y+(eldertree.tex.mHeight*0.25);
    for(int i = lx; i < mx; i++){
        for(int j = ly; j < my; j++){
            if(occupiedspace[i][j]) return true;
        }
    }
    return false;
}