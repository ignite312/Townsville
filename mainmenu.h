#ifndef MAINMENU_H
#define MAINMENU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void handleEvent_mainMenu(SDL_Event e);
void render_mainMenu();
bool loadMedia_mainMenu();
void play_backgroundMusic();
#endif