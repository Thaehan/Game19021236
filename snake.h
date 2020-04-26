#ifndef SNAKE_H
#define SNAKE_H

#include "FrameSDL.h"
#include "game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class snake {
public:
	snake();
	~snake();

	int x = 0;
	int y = 0;
	int prex = 0;
	int prey = 0;

	int tailLength = 0;

	std::vector <int> tailX;
	std::vector <int> tailY;

	SDL_Rect snakeBox{ 0, 0, boxSize, boxSize };

	void renderSnake(SDL_Renderer* renderer);
};




#endif