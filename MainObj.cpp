#include "FrameSDL.h"
#include "MainObj.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

SDL_Surface* image(std::string file) {

    SDL_Surface* load_image = NULL;

    load_image = IMG_Load(file.c_str());

    if (load_image != NULL) {
        return load_image;
    }

    else {
        return NULL;
    }
}

void backgroundgame(SDL_Surface* background, SDL_Surface* windowSurface, SDL_Window* window) {
    background = image("background.jpg");

    if (background == NULL) {
        logSDLError(std::cout, "Can't open background image!" , true);
    }

    else {
        windowSurface = SDL_GetWindowSurface(window);

        SDL_BlitSurface(background, NULL, windowSurface, NULL);

        SDL_UpdateWindowSurface(window);
    }
}


