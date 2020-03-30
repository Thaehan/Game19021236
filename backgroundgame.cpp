#include "Header.h"
#include <SDL.h>
#include <SDL_image.h>

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

void backgroundgame(SDL_Surface* background, SDL_Surface* windowSurface, SDL_Window* window) {
    background = image("background.jpg");

    windowSurface = SDL_GetWindowSurface(window);

    SDL_BlitSurface(background, NULL, windowSurface, NULL);

    SDL_UpdateWindowSurface(window);
}