#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "This game is made by Thaehan";
const std::string filebackground = "background.jpg";
const int stepDelay = 40;

//This function will show the Error: standard output - Name of error - check funtion
void logSDLError(std::ostream& os, const std::string& msg, bool fatal = false);

//Create window and renderer
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, int SCREEN_WITDH, int SCREEN_HEIGHT, const std::string& WINDOW_TITLE);

//quit SDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* background, SDL_Surface* windowSurface);

//Wait for a click or pressed key
void waitKeyPressed();

#endif