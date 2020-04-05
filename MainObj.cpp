#include "FrameSDL.h"
#include "MainObj.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

void snake::render(SDL_Renderer* renderer) {
    
    SDL_Rect filled_rect;
    filled_rect.x = x;
    filled_rect.y = y;
    filled_rect.w = size;
    filled_rect.h = size;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderFillRect(renderer, &filled_rect);
  
}

void snake::renderSnake(SDL_Renderer* renderer) {
    while (inside(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)) {

        SDL_Event e;
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        
        SDL_RenderClear(renderer);

        render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(stepDelay);

        if (SDL_PollEvent(&e)) {
            continue;
        }

        if (e.type == SDL_QUIT) {
            break;
        }

        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_UP:
                turnUp();
                break;
            case SDLK_DOWN:
                turnDown();
                break;
            case SDLK_RIGHT:
                turnRight();
                break;
            case SDLK_LEFT:
                turnLeft();
                break;
            default:
                break;
            }
        }

        move();
    }
}

bool snake::inside(int minx, int miny, int maxx, int maxy) {
    return (minx <= x && miny <= y && x + size < maxx&& y + size < maxy);
}

void snake::move() {
    x += stepx;
    y += stepy;
    std::cout << stepx << "," << stepy << std::endl;
}

void snake::turnLeft() {
    stepx = -size;
    stepy = 0;
}

void snake::turnRight() {
    stepx = size;
    stepy = 0;
}

void snake::turnUp() {
    stepy = -size;
    stepx = 0;
}

void snake::turnDown() {
    stepy = size;
    stepx = 0;
}

void printBackground(SDL_Surface* background, SDL_Surface* windowSurface, SDL_Window* window) {
    background = IMG_Load(filebackground.c_str());
    if (background == NULL) {
        std::cout << "Can't open background file!" << std::endl;
    }

    windowSurface = SDL_GetWindowSurface(window);

    SDL_BlitSurface(background, NULL, windowSurface, NULL);

    SDL_UpdateWindowSurface(window);
}


