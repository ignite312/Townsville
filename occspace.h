#ifndef OCCSPACE_H
#define OCCSPACE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void occupied(SDL_Rect rect);
bool isOccupied(int x, int y);

#endif