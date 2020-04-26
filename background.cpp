#include "background.h"
#include "FrameSDL.h"
#include "MainObj.h"

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
