#include "FrameSDL.h"
#include "MainObj.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    std::vector<int> tailX;
    std::vector<int> tailY;

    SDL_Init(SDL_INIT_EVERYTHING);
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    Game gamesnake;

    gamesnake.gameLoop(renderer, tailX, tailY);

    gamesnake.~Game();
    quitSDL(window, renderer);
    SDL_Quit();

    return 0;
}
