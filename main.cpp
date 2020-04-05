#include "FrameSDL.h"
#include "MainObj.h"


int main(int argc, char* argv[])
{
    SDL_Surface* background = NULL;
    SDL_Surface* windowSurface = NULL;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;

    snake player;

    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //Background game
    

    //ve game o day - SDL_RenderPresent(renderer)
	
    player.renderSnake(renderer);

    waitKeyPressed();
    quitSDL(window, renderer, background, windowSurface);
    return 0;
}
