#ifndef background_h
#define background_h

#include "FrameSDL.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class background {
public:
	background();
	~background();
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	void renderEdge(SDL_Renderer* renderer);

private:
	SDL_Rect bar = { 0, 0, SCREEN_WIDTH, topbar };
	SDL_Rect edgeLeft = { 0, topbar, edge, SCREEN_HEIGHT - topbar - edge };
	SDL_Rect edgeRight = { SCREEN_WIDTH - edge, topbar, edge, SCREEN_HEIGHT - topbar - edge };
	SDL_Rect edgeBot = { 0, SCREEN_HEIGHT - edge, SCREEN_WIDTH, edge };

};



#endif