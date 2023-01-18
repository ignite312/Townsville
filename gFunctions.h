#ifndef gFUNCTIONS
#define gFUNCTIONS

// the state of the program
enum state
{
	mainMenu,
	game
};

// Window info
    

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

#endif //gFUNCTIONS