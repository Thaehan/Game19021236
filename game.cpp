#include "game.h"
#include "snake.h"
#include "Fruit.h"
#include "Font.h"

snake Snake;
fruit Fruit;

game::game() {};
game::~game() {};

void game::moveUp() {
	if (stepy == boxSize) {
		stepy = boxSize;
	}
	else {
		stepx = 0;
		stepy = -boxSize;
	}
}

void game::moveDown() {
	if (stepy == -boxSize) {
		stepy = -boxSize;
	}
	else {
		stepx = 0;
		stepy = boxSize;
	}
}

void game::moveLeft() {
	if (stepx == boxSize) {
		stepx = boxSize;
	}
	else {
		stepx = -boxSize;
		stepy = 0;
	}
}

void game::moveRight() {
	if (stepx == -boxSize) {
		stepx = -boxSize;
	}
	else {
		stepx = boxSize;
		stepy = 0;
	}
}

void game::move() {
	Snake.prex = Snake.x;
	Snake.prey = Snake.y;

	Snake.x += stepx;
	Snake.y += stepy;
}

void game::control() {
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			exit(0);
		}

		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				moveUp();
				break;
			case SDLK_DOWN:
				moveDown();
				break;
			case SDLK_LEFT:
				moveLeft();
				break;
			case SDLK_RIGHT:
				moveRight();
				break;
			default:
				break;
			}
		}
	}
}

void game::reset() {
	stepx = 0;
	stepy = 0;
	Snake.x = 0;
	Snake.y = 0;

	Snake.tailX.clear();
	Snake.tailY.clear();

	Snake.tailLength = 0;

	Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);;

	Fruit.fruitBox.x = Fruit.x;
	Fruit.fruitBox.y = Fruit.y;

}

void game::renderGameOver(SDL_Renderer* renderer) {
	std::cout << "Oh! You lose! Press SPACE to try again!" << std::endl;
	while (true) {
		if (SDL_PollEvent(&e)) {

			if (e.type == SDL_QUIT) {
				exit(0);
			}

			if (e.key.keysym.sym == SDLK_SPACE) {
				redo = true;
				return;
			}

		}
	}
}

void game::renderGameWin(SDL_Renderer* renderer){
	std::cout << "Congratulation! You win snake game! Press Space to play again!";

	// Congratulation
	while (true) {
		if (SDL_PollEvent(&e)) {

			if (e.type == SDL_QUIT) {
				exit(0);
			}

			if (e.key.keysym.sym == SDLK_SPACE) {
				redo = true;
				return;
			}
		}

	}

}

void game::gameLoop(SDL_Renderer* renderer, SDL_Texture* bgImage) {
	Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);
		while (true) {
			//If win game
			if (Snake.tailLength == (SCREEN_WIDTH / boxSize) * (SCREEN_HEIGHT / boxSize)) {
				renderGameWin(renderer);
				reset();
				break;
			}

			control();
			move();

			//When snake eat fruit
			if (Fruit.x == Snake.x && Fruit.y == Snake.y) {
				Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);;
				Snake.tailLength++;
			}

			//Update tail
			if (Snake.tailX.size() != Snake.tailLength) {
				Snake.tailX.push_back(Snake.prex);
				Snake.tailY.push_back(Snake.prey);
			}

			//Move box
			for (int i = 0; i < Snake.tailLength; i++) {

				if (i > 0) {
					Snake.tailX[i - 1] = Snake.tailX[i];
					Snake.tailY[i - 1] = Snake.tailY[i];
				}

			}

			if (Snake.tailLength > 0) {
				Snake.tailX[Snake.tailLength - 1] = Snake.prex;
				Snake.tailY[Snake.tailLength - 1] = Snake.prey;
			}

			//If snake collises edge or tail
			for (int i = 0; i < Snake.tailLength; i++) {
				if (Snake.x == Snake.tailX[i] && Snake.y == Snake.tailY[i]) {
					renderGameOver(renderer);
					reset();
					break;
				}
			}

			if (Snake.x < 0 || Snake.y < 0 || Snake.x > SCREEN_WIDTH - boxSize || Snake.y > SCREEN_HEIGHT - boxSize) {
				renderGameOver(renderer);
				reset();
				break;
			}


			//Render Background
			SDL_RenderCopy(renderer, bgImage, NULL, NULL);

			//Render Fruit
			Fruit.renderFruit(renderer);

			//Render Snake
			Snake.renderSnake(renderer);

			SDL_RenderPresent(renderer);

			SDL_Delay(STEP_DELAY);

			SDL_RenderClear(renderer);
		
	}
}
