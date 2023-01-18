#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

Mix_Chunk *click = NULL;
Mix_Music *BGM = NULL;
Mix_Chunk *warning = NULL;
Mix_Chunk *selectionGame = NULL;


void play_clickSound(){
    // Mix_HaltMusic();
    Mix_PlayChannel(-1, click, 0);
}

void play_warning(){
    Mix_PlayChannel(-1, warning, 0);
}

void play_BGM(){
    Mix_PlayMusic(BGM, -1);
}

void play_selectionGame(){
    Mix_PlayChannel(-1, selectionGame, 0);
}

bool loadMedia_Music(){
    click = Mix_LoadWAV("Music/click.wav");
    if(click == NULL){
        printf("Could not load wav\n");
        return false;
    }
    BGM = Mix_LoadMUS("Music/Cobblestone Village.mp3");
    if(BGM == NULL){
        printf("Could not load BGM\n");
        return false;
    }
    warning = Mix_LoadWAV("Music/warning-sound.mp3");
    if(warning == NULL){
        printf("Could not load music\n");
        return false;
    }
    selectionGame = Mix_LoadWAV("Music/selectiongame.wav");
    if(selectionGame == NULL){
        printf("Could not load music\n");
        return false;
    }
    return true;
}