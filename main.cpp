#include "FrameSDL.h"
<<<<<<< HEAD
#include "snake.h"
#include "background.h"
#include "game.h"
=======
#include "MainObj.h"
#include "background.h"
>>>>>>> bac8c199b56aa05869f06c6717ae842c901709b5


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bgImage = NULL;
    
    //SDL INIT 
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Game class
<<<<<<< HEAD
    background backgroundgame;
    game Game;
=======
    Game gamesnake;
    background backgroundgame;
>>>>>>> bac8c199b56aa05869f06c6717ae842c901709b5

    //Load image background
    bgImage = backgroundgame.loadTexture(bgFile.c_str(), renderer);

    //Start game
<<<<<<< HEAD
    do{
        Game.gameLoop(renderer, bgImage);
    } while (Game.redo == true);

    //Close game
    backgroundgame.~background();
    Game.~game();
    quitSDL(window, renderer, bgImage);
=======
    gamesnake.firstFruit(renderer);
    gamesnake.gameLoop(renderer, bgImage);

    //Close game
    gamesnake.~Game();
    backgroundgame.~background();
    quitSDL(window, renderer);
>>>>>>> bac8c199b56aa05869f06c6717ae842c901709b5
    SDL_Quit();

    return 0;
}
