#include "game.h"
#include "snake.h"
#include "Fruit.h"
#include "Font.h"
#include "background.h"
#include <string>

snake Snake;
fruit Fruit;
background Background;
font Font;

game::game() {};
game::~game() {
	SDL_DestroyTexture(bgImage);
	bgImage = NULL;
	Background.~background();
	Font.~font();
	Snake.~snake();
	Fruit.~fruit();
};

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
	Snake.x = edge;
	Snake.y = topbar;

	Snake.tailX.clear();
	Snake.tailY.clear();

	Snake.tailLength = 0;
	score = 0;

	Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);;

	Fruit.fruitBox.x = Fruit.x;
	Fruit.fruitBox.y = Fruit.y;

}

void game::renderGameOver(SDL_Renderer* renderer) {
	Font.renderOver("GAME OVER!", "Press SPACE to try again!", fontFile, Font.gColor, SCREEN_WIDTH / 4, renderer, bgImage);
	SDL_RenderPresent(renderer);

	while (true) {
		if (SDL_PollEvent(&e)) {

			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
				game::~game();
				exit(0);
			}

			if (e.key.keysym.sym == SDLK_SPACE) {
				SDL_DestroyTexture(Font.printGameOver1);
				SDL_DestroyTexture(Font.printGameOver2);
				Font.printGameOver1 = NULL;
				Font.printGameOver1 = NULL;
				return;
			}

		}
	}
}

void game::renderGameWin(SDL_Renderer* renderer){
	std::cout << "Congratulation! You win snake game! Press Space to play again!" << std::endl;

	// Congratulation
	while (true) {
		if (SDL_PollEvent(&e)) {

			if (e.type == SDL_QUIT) {
				game::~game();
				exit(0);
			}

			if (e.key.keysym.sym == SDLK_SPACE) {
				return;
			}
		}

	}

}

void game::gameLoop(SDL_Renderer* renderer) {
	//Setup menu game
	if (firstCheck == false) {
		Font.renderMenu("Simple Snake", "Press SPACE to play!", fontFile, Font.mColor, SCREEN_HEIGHT / 4, renderer, bgImage);
	}
	while (firstCheck == false) {
		if (SDL_WaitEvent(&e) == 0) {
			continue;
		}
		if (e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) {
			game::~game();
			exit(0);
		}
		if (e.key.keysym.sym == SDLK_SPACE) {
			firstCheck = true;
			SDL_DestroyTexture(Font.printMenu1);
			SDL_DestroyTexture(Font.printMenu2);
			Font.printMenu1 = NULL;
			Font.printMenu2 = NULL;
			SDL_RenderClear(renderer);
			break;
		}
	}

	//Setup for first.
	Font.printScore = Font.renderText("Your score: " + std::to_string(score), fontFile, Font.sColor, topbar - 5, renderer);
	Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);
	
	while (true) {
		
		//If win game
		if (Snake.tailLength == (SCREEN_WIDTH - edge - edge / boxSize) * (SCREEN_HEIGHT - topbar - edge / boxSize)) {
			renderGameWin(renderer);
			reset();
			break;
		}

		control();
		move();

		//When snake eat fruit
		if (Fruit.x == Snake.x && Fruit.y == Snake.y) {
			Fruit.getFruit(Snake.tailLength, Snake.tailX, Snake.tailY, Snake.x, Snake.y);
			
			//Update details
			Snake.tailLength++;
			score += 10;

			//Get Score Texture
			SDL_DestroyTexture(Font.printScore);
			Font.printScore = NULL;
			Font.printScore = Font.renderText("Your score: " + std::to_string(score), fontFile, Font.sColor, topbar - 5, renderer);
		}

		//Update tail
		if (Snake.tailX.size() != Snake.tailLength) {
			Snake.tailX.push_back(Snake.prex);
			Snake.tailY.push_back(Snake.prey);
		}

		//Move box
		for (int i = 0;i < Snake.tailLength; i++) {

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

		if (Snake.x < edge || Snake.y < topbar || Snake.x > SCREEN_WIDTH - edge - boxSize || Snake.y > SCREEN_HEIGHT - edge - boxSize) {
			renderGameOver(renderer);
			reset();
			break;
		}


		//Render Background
		SDL_RenderCopy(renderer, bgImage, NULL, NULL);

		//Render Edge
		Background.renderEdge(renderer);

		//Render Score
		Font.renderScore(renderer);

		//Render Fruit
		Fruit.renderFruit(renderer);

		//Render Snake
		Snake.renderSnake(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(STEP_DELAY);

		SDL_RenderClear(renderer);
	
	}
}
