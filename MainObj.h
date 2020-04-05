#ifndef OBJ
#define OBJ

#include "FrameSDL.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class snake {
	public:
		int x = 0, y = 0, stepx = 0, stepy = 0;
		int size = 10;
		void renderSnake(SDL_Renderer* renderer);

	private:
		void render(SDL_Renderer* renderer);
		bool inside(int minx, int miny, int maxx, int maxy);

		void move();
		void turnLeft();
		void turnRight();
		void turnUp();
		void turnDown();

};

void printBackground(SDL_Surface* background, SDL_Surface* windowSurface, SDL_Window* window);

#endif
