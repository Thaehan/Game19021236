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

	int x = edge;
	int y = topbar;
	int prex = edge;
	int prey = topbar;

	int tailLength = 0;

	std::vector <int> tailX;
	std::vector <int> tailY;

	SDL_Rect snakeBox{ edge, topbar, boxSize, boxSize };

	void renderSnake(SDL_Renderer* renderer);
};




#endif