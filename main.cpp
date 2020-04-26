#include "FrameSDL.h"
#include "snake.h"
#include "background.h"
#include "game.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bgImage = NULL;
    
    //SDL INIT 
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Game class
    background backgroundgame;
    game Game;

    //Load image background
    bgImage = backgroundgame.loadTexture(bgFile.c_str(), renderer);

    //Start game
    do{
        Game.gameLoop(renderer, bgImage);
    } while (Game.redo == true);

    //Close game
    backgroundgame.~background();
    Game.~game();
    quitSDL(window, renderer, bgImage);
    SDL_Quit();

    return 0;
}
