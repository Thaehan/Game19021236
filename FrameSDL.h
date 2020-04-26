#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <Windows.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "Simple Snake by Do Van Dat";

const std::string bgFile = "background.jpg";
const std::string fontFile = "font.ttf";
const int fontSize = 20;

const int STEP_DELAY = 70;
const int boxSize = 30;

//This function will show the Error: standard output - Name of error - check funtion
void logSDLError(std::ostream& os, const std::string& msg, bool fatal = false);

//Create window and renderer
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, int SCREEN_WITDH, int SCREEN_HEIGHT, const std::string& WINDOW_TITLE);

//quit SDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* bgImage);

//Wait for a click or pressed key
void waitKeyPressed();

#endif