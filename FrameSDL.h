#ifndef DEBUG
#define DEBUG

#include "MainObj.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <Windows.h>



//This function will show the Error: standard output - Name of error - check funtion
void logSDLError(std::ostream& os, const std::string& msg, bool fatal = false);

//Create window and renderer
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, int SCREEN_WITDH, int SCREEN_HEIGHT, const std::string& WINDOW_TITLE);

//quit SDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

//Wait for a click or pressed key
void waitKeyPressed();

#endif