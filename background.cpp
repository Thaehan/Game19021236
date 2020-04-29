#include "background.h"
#include "FrameSDL.h"

background::background() {};
background::~background() {};

SDL_Texture* background::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* nTexture = NULL;
	SDL_Surface* nSurface = IMG_Load(path.c_str());

	if (nSurface == NULL) {
		std::cout << "Can't open background image file!" << std::endl;
	}
	else {
		nTexture = SDL_CreateTextureFromSurface(renderer, nSurface);
		if (nTexture == NULL) {
			std::cout << "Can't create texture!" << std::endl;
		}
		SDL_FreeSurface(nSurface);
	}
	return nTexture;
}

void background::renderEdge(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 80, 120, 140, 200);
	SDL_RenderFillRect(renderer, &bar);
	SDL_RenderFillRect(renderer, &edgeLeft);
	SDL_RenderFillRect(renderer, &edgeRight);
	SDL_RenderFillRect(renderer, &edgeBot);
}
