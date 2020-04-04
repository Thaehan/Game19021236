#ifndef OBJ
#define OBJ

#include "FrameSDL.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class snake {
public:
	int x, y, vx, vy;
};


//Get background for game
SDL_Surface* image(std::string file);

//Print background game
void backgroundgame(SDL_Surface* background, SDL_Surface* windowSurface, SDL_Window* window);



#endif
