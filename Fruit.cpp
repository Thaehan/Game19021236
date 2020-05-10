#include "Fruit.h"

fruit::fruit() {};
fruit::~fruit() {
	x = 0;
	y = 0;
};

//Check random of the fruit
bool fruit::fruitCheck(int fx, int fy, int tailLength, std::vector <int> tailX, std::vector <int> tailY, int a, int b) {
	for (int i = 0; i < tailLength; i++) {
		if (fx == a && fy == b || fx == tailX[i] && fy == tailY[i]) {
			return 1;
		}
	}
	return 0;
}

void fruit::getFruit(int tailLength, std::vector <int> tailX, std::vector <int> tailY, int a, int b) {
	srand(time(0));
	
	do {
		x = edge + boxSize * (rand() % ((SCREEN_WIDTH - edge) / boxSize));
		y = topbar + boxSize * (rand() % ((SCREEN_HEIGHT - topbar) / boxSize));
	} while (fruitCheck(x, y, tailLength, tailX, tailY, a, b));

}

void fruit::renderFruit(SDL_Renderer* renderer) {
	fruitBox.x = x;
	fruitBox.y = y;
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &fruitBox);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &fruitBox);
}

