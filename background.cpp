#include "background.h"
#include "FrameSDL.h"
<<<<<<< HEAD
=======
#include "MainObj.h"
>>>>>>> bac8c199b56aa05869f06c6717ae842c901709b5

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
