#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 507;
const std::string WINDOW_TITLE = "This game is made by Thaehan";

SDL_Surface* image(std::string file) {
    
    SDL_Surface* load_image = NULL;

    load_image = IMG_Load(file.c_str());

    if (load_image != NULL) {
        return load_image;
    }

    else {
        std::cout << "Could not be load background.jpg!" << std::endl;
        return NULL;
    }
}

int main(int argc, char* argv[])
{
    SDL_Surface* background = NULL;
    SDL_Surface* windowSurface = NULL;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Background game

    background = image("background.jpg");

    windowSurface = SDL_GetWindowSurface(window);

    SDL_BlitSurface(background, NULL, windowSurface, NULL);

    SDL_UpdateWindowSurface(window);
    
    //ve game o day - SDL_RenderPresent(renderer)



    waitKeyPressed();
    quitSDL(window, renderer, background, windowSurface);
    return 0;
}
