#include "Fruit.h"

fruit::fruit() {};
fruit::~fruit() {};

void fruit::getFruit(int tailLength, std::vector <int> tailX, std::vector <int> tailY, int a, int b) {
	bool check = false;

	srand(time(0));
	x = boxSize * (rand() % (SCREEN_WIDTH / boxSize));
	y = boxSize * (rand() % (SCREEN_HEIGHT / boxSize));
	check = true;

	//Check Snake tail to spawn fruit
	for (int i = 0; i < tailLength; i++) {
		if ((x == tailX[i] && y == tailY[i]) || (x == a && y == b)) {
			check = false;
		}
	}

	if (!check) {
		x = 0;
		y = 0;
	}

	fruitBox.x = x;
	fruitBox.y = y;

}

void fruit::renderFruit(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &fruitBox);
}

