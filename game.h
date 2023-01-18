#ifndef GAME_H
#define GAME_H

#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>

bool handleEvent_Game(SDL_Event e);
void handleGame(int frame);
void toggleMessage(std::string s);
void setRaid(int x);
#endif