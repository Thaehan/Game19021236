#include "FrameSDL.h"
#include "MainObj.h"
#include "background.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bgImage = NULL;
    
    //SDL INIT 
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Game class
    Game gamesnake;
    background backgroundgame;

    //Load image background
    bgImage = backgroundgame.loadTexture(bgFile.c_str(), renderer);

    //Start game
    gamesnake.firstFruit(renderer);
    gamesnake.gameLoop(renderer, bgImage);

    //Close game
    gamesnake.~Game();
    backgroundgame.~background();
    quitSDL(window, renderer);
    SDL_Quit();

    return 0;
}
