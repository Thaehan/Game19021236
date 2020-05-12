#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <Windows.h>

const int topbar = 40;
const int edge = 5;

const int SCREEN_WIDTH = 800 + edge + edge;
const int SCREEN_HEIGHT = 800 + topbar + edge;
const std::string WINDOW_TITLE = "Simple Snake";

const std::string bgFile = "data/background.jpg";
const std::string fontFile = "data/font.ttf";
const int fontSize = 20;

const int STEP_DELAY = 80;
const int boxSize = 50;

//This function will show the Error: standard output - Name of error - check funtion
void logSDLError(std::ostream& os, const std::string& msg, bool fatal = false);

//Create window and renderer
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, int SCREEN_WITDH, int SCREEN_HEIGHT, const std::string& WINDOW_TITLE);

//quit SDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif