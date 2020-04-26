#ifndef background_h
#define background_h

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class background {
public:
	background();
	~background();
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
};



#endif