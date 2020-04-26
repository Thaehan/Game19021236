#include "MainObj.h"


//Two necessary functions
Game::Game()
{
	SDL_Event e;
}

Game::~Game() 
{

}

//Render snake and fruit
void Game::renderSnake(SDL_Renderer* renderer, int hscale)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	snakeBox.w = hscale;
	snakeBox.h = hscale;

	// Gets x and y of all tail blocks and renders
	for (int i = 0; i < tailLength; i++) {
		snakeBox.x = tailX[i];
		snakeBox.y = tailY[i];
		SDL_RenderFillRect(renderer, &snakeBox);
	}

	snakeBox.x = snakeLoc.x;
	snakeBox.y = snakeLoc.y;

	SDL_RenderFillRect(renderer, &snakeBox);
}

void Game::renderFruit(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
	SDL_RenderFillRect(renderer, &fruitBox);
}

//Get fruit location and check collision
void Game::getFruitLoc(int hscale, int wscale)
{
	int x = 0;
	int y = 0;
	bool check = false;

	srand(time(0));
	x = hscale * (rand() % wscale);
	y = hscale * (rand() % wscale);
	check = true;

	// Check all tail blocks and snake block
	for (int i = 0; i < tailLength; i ++) {
		if ((x == tailX[i] && y == tailY[i]) || (x == snakeLoc.x && y == snakeLoc.y)) {
			check = false;
		}
	}

	if (!check) {
		fruitLoc.x = 0;
		fruitLoc.y = 0;
	}

	fruitLoc.x = x;
	fruitLoc.y = y;
}

bool Game::checkCollision()
{

	if (snakeLoc.x == fruitLoc.x && snakeLoc.y == fruitLoc.y) {
		return true;
	}

	return false;
}

//Render score and game screen
void Game::renderScore(SDL_Renderer* renderer, int hscale, int wscale)
{
	std::cout << "Your score: " << std::to_string(tailLength * 10).c_str() << std::endl;
}

void Game::renderGameOver(SDL_Renderer* renderer, int hscale, int wscale)
{
	std::cout << "This is not fruit! Try again by press Space!";
	while (true) {

		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.sym == SDLK_SPACE) {
				return;
			}

		}

	}

}

void Game::renderGameWin(SDL_Renderer* renderer, int hscale, int wscale)
{
	std::cout << "Congratulation! You win snake game! Press Space to play again!";

	// Congratulation
	while (true) {
		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.sym == SDLK_SPACE) {
				return;
			}

		}

	}

}

//Movements
void Game::moveDirection() 
{
	if (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) {
			exit(0);
		}

		if (event.type == SDL_KEYDOWN && checkMove == false) {
			if (down == false && event.key.keysym.sym == SDLK_UP) {
				up = true;
				left = false;
				right = false;
				down = false;
				checkMove = true;
			}
			else if (up == false && event.key.keysym.sym == SDLK_DOWN) {
				up = false;
				left = false;
				right = false;
				down = true;
				checkMove = true;
			}
			else if (right == false && event.key.keysym.sym == SDLK_LEFT) {
				up = false;
				left = true;
				right = false;
				down = false;
				checkMove = true;
			}
			else if (left == false && event.key.keysym.sym == SDLK_RIGHT) {
				up = false;
				left = false;
				right = true;
				down = false;
				checkMove = true;
			}

		}
	}
}

void Game::moveUp(float delta) {
	snakeLoc.y -= delta * hscale;
}

void Game::moveDown(float delta) {
	snakeLoc.y += delta * hscale;
}

void Game::moveLeft(float delta) {
	snakeLoc.x -= delta * wscale;
}

void Game::moveRight(float delta) {
	snakeLoc.x += delta * wscale;
}

void Game::updateMove(float delta) {
	snakeLoc.prex = snakeLoc.x;
	snakeLoc.prey = snakeLoc.y;

	//Move
	if (up) {
		moveUp(delta);
	}
	else if (down) {
		moveDown(delta);
	}
	else if (left) {
		moveLeft(delta);
	}
	else if (right) {
		moveRight(delta);
	}
}

//Game logic and loop
void Game::gameOver(SDL_Renderer* renderer) {
	renderGameOver(renderer, hscale, wscale);
	snakeLoc.x = 0;
	snakeLoc.y = 0;

	up = false;
	left = false;
	right = false;
	down = false;

	tailX.clear();
	tailY.clear();

	tailLength = 0;
	redo = false;

	getFruitLoc(hscale, wscale);
	fruitBox.x = fruitLoc.x;
	fruitBox.y = fruitLoc.y;

	if (fruitLoc.x == 0 && fruitLoc.y == 0) {
		redo = true;
	}
}

void Game::gameLoop(SDL_Renderer* renderer, SDL_Texture* bgImage)
{
	while (true) {

		float newTime = SDL_GetTicks() / (speed - 10); //
		float delta = newTime - Stime;
		Stime = newTime;

		checkMove = false;

		//If you win game
		if (tailLength >= hscale * wscale - 1) {
			renderGameWin(renderer, hscale, wscale);
			snakeLoc.x = 0;
			snakeLoc.y = 0;
			
			up = false;
			left = false;
			right = false;
			down = false;
			
			tailX.clear();
			tailY.clear();
			
			tailLength = 0;
			redo = false;
			
			getFruitLoc(hscale, wscale);

			if (fruitLoc.x == 0 && fruitLoc.y == 0) {
				redo = true;
			}

			fruitBox.x = fruitLoc.x;
			fruitBox.y = fruitLoc.y;
		}

		//Control direction
		moveDirection();

		// The previous position of the player block
		updateMove(delta);


		if (redo == true) {

			redo = false;
			getFruitLoc(hscale, wscale);

			if (fruitLoc.x == 0 && fruitLoc.y == 0) {
				redo = true;
			}

		}

		//Check the Collision
		if (checkCollision()) {

			// Spawn new food after it has been eaten
			getFruitLoc(hscale, wscale);
			fruitBox.x = fruitLoc.x;
			fruitBox.y = fruitLoc.y;

			if (fruitLoc.x == 0 && fruitLoc.y == 0) {
				redo = true;
			}

			tailLength++;
		}

		// Only runs in the frames where the player block has moved
		if (delta * hscale == hscale) {

			//Update tail
			if (tailX.size() != tailLength) {
				tailX.push_back(snakeLoc.prex);
				tailY.push_back(snakeLoc.prey);
			}

			//Move box
			for (int i = 0; i < tailLength; i++) {

				if (i > 0) {
					tailX[i - 1] = tailX[i];
					tailY[i - 1] = tailY[i];
				}

			}

			if (tailLength > 0) {
				tailX[tailLength - 1] = snakeLoc.prex;
				tailY[tailLength - 1] = snakeLoc.prey;
			}

		}

		//If snake collises the window or tail
		for (int i = 0; i < tailLength; i++) {
			if (snakeLoc.x == tailX[i] && snakeLoc.y == tailY[i]) {
				renderGameOver(renderer, hscale, wscale);
				snakeLoc.x = 0;
				snakeLoc.y = 0;
				
				up = false;
				left = false;
				right = false;
				down = false;
				
				tailX.clear();
				tailY.clear();
				
				tailLength = 0;
				redo = false;

				getFruitLoc(hscale, wscale);
				if (fruitLoc.x == 0 && fruitLoc.y == 0) {
					redo = true;
				}

				fruitBox.x = fruitLoc.x;
				fruitBox.y = fruitLoc.y;
			}
		}

		//Game over and reset
		if (snakeLoc.x < 0 || snakeLoc.y < 0 || snakeLoc.x > hscale * wscale - hscale || snakeLoc.y > hscale * wscale - hscale) {
			gameOver(renderer);
		}

		// Render everything

		SDL_RenderCopy(renderer, bgImage, NULL, NULL);

		renderFruit(renderer);
		renderSnake(renderer, hscale);
		renderScore(renderer, hscale, wscale);

		
		SDL_RenderPresent(renderer);
		
		SDL_RenderClear(renderer);
	}

}

void Game::firstFruit(SDL_Renderer* renderer){
	getFruitLoc(hscale, wscale);
	fruitBox.x = fruitLoc.x;
	fruitBox.y = fruitLoc.y;
	renderFruit(renderer);
	SDL_RenderPresent(renderer);
}
