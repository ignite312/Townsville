#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void play_clickSound();
void play_BGM();
void play_warning();
void play_selectionGame();

bool loadMedia_Music();

#endif