#ifndef FRUIT_H
#define FRUIT_H

#include "game.h"
#include "snake.h"
#include "FrameSDL.h"
#include <iostream>
#include <vector>

class fruit {
public:
	fruit();
	~fruit();

	int x;
	int y;

	SDL_Rect fruitBox = { 0, 0, boxSize, boxSize };
	void getFruit(int tailLength, std::vector <int> tailX, std::vector <int> tailY, int a, int b);
	void renderFruit(SDL_Renderer* renderer);
};




#endif
