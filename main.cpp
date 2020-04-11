#include "FrameSDL.h"
#include "MainObj.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    Game gamesnake;

    gamesnake.getFruitLoc(wscale, hscale);
    gamesnake.renderFruit(renderer);
    SDL_RenderPresent(renderer);

    gamesnake.gameLoop(renderer);

    gamesnake.~Game();
    quitSDL(window, renderer);
    SDL_Quit();

    return 0;
}
