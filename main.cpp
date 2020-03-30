#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 507;
const std::string WINDOW_TITLE = "This game is made by Thaehan";

int main(int argc, char* argv[])
{
    SDL_Surface* background = NULL;
    SDL_Surface* windowSurface = NULL;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Background game
    backgroundgame(background, windowSurface, window);
    
    //ve game o day - SDL_RenderPresent(renderer)



    waitKeyPressed();
    quitSDL(window, renderer, background, windowSurface);
    return 0;
}
