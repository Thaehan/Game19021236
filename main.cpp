#include "FrameSDL.h"
#include "snake.h"
#include "background.h"
#include "game.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    //SDL INIT 
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Game class
    background Background;
    game Game;

    //Load image background
    Game.bgImage = Background.loadTexture(bgFile, renderer);

    //Start game
    do{
        Game.gameLoop(renderer);
    } while (true);

    //Close game
    Game.~game();
    quitSDL(window, renderer);
    SDL_Quit();

    return 0;
}
