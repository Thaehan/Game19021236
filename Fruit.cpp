#include "Fruit.h"

fruit::fruit() {};
fruit::~fruit() {
	x = 0;
	y = 0;
};

void fruit::ranFruit() {
	x = edge + boxSize * (rand() % ((SCREEN_WIDTH - edge) / boxSize));
	y = topbar + boxSize * (rand() % ((SCREEN_HEIGHT - topbar) / boxSize));
}

void fruit::getFruit(int tailLength, std::vector <int> tailX, std::vector <int> tailY, int a, int b) {
	srand(time(0));
	bool check = false;

	//Check Snake tail and head to spawn fruit
	for (int i = 0; i < tailLength; i++) {
		if (tailX[i] != x && tailY[i] != y && x != a && x != b) {
			check = true;
		}
		else {
			check = false;
		}
	}
	if (check == false) {
		ranFruit();
	}

}

void fruit::renderFruit(SDL_Renderer* renderer) {
	fruitBox.x = x;
	fruitBox.y = y;
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &fruitBox);
}

