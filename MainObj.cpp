#include "MainObj.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <string>
#include <Windows.h>


Game::Game() 
{

}

Game::~Game() 
{

}

//Render snake 
void Game::renderSnake(SDL_Renderer* renderer, int hscale, std::vector <int> &tailX, std::vector <int> &tailY)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	snakeBox.w = hscale;
	snakeBox.h = hscale;

	// Gets x and y of all tail blocks and renders them
	for (int i = 0; i < tailLength; i++) {
		snakeBox.x = tailX[i];
		snakeBox.y = tailY[i];
		SDL_RenderFillRect(renderer, &snakeBox);
	}

	snakeBox.x = snakeLoc.x;
	snakeBox.y = snakeLoc.y;

	SDL_RenderFillRect(renderer, &snakeBox);
}


//Render fruit
void Game::renderFruit(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &fruitBox);
}


//Get spawn location of food
void Game::getFruitLoc(int hscale, int wscale, std::vector <int> &tailX, std::vector <int> &tailY)
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
		fruitLoc.x = -100;
		fruitLoc.y = -100;
	}

	fruitLoc.x = x;
	fruitLoc.y = y;
}

//Check the snake if collisy
bool Game::checkCollision()
{

	if (snakeLoc.x == fruitLoc.x && snakeLoc.y == fruitLoc.y) {
		return true;
	}

	return false;
}

//Print Score on screen
void Game::printScore(SDL_Renderer* renderer, int hscale, int wscale)
{
	std::cout << "Your score:" << std::to_string(tailLength * 10).c_str() << std::endl;
}

//Screen when you lose!
void Game::gameOver(SDL_Renderer* renderer, int hscale, int wscale)
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

//Screen when you win!
void Game::gameWin(SDL_Renderer* renderer, int hscale, int wscale)
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

//Control direction
void Game::moveDirection() 
{
	if (SDL_PollEvent(&event)) {

		// Simply exit the program when told to
		if (event.type == SDL_QUIT) {
			exit(0);
		}

		// If a key is pressed
		if (event.type == SDL_KEYDOWN && checkMove == false) {

			// Then check for the key being pressed and change direction accordingly
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

//Game loop
void Game::gameLoop(SDL_Renderer* renderer, std::vector <int> &tailX, std::vector <int> &tailY)
{
	while (true) {

		float newTime = SDL_GetTicks() / (speed - 10); //
		float delta = newTime - Stime;
		Stime = newTime;

		checkMove = false;



		//If you win game
		if (tailLength >= hscale * wscale - 1) {
			gameWin(renderer, hscale, wscale);
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
			getFruitLoc(hscale, wscale, tailX, tailY);

			if (fruitLoc.x == -100 && fruitLoc.y == -100) {
				redo = true;
			}

			fruitBox.x = fruitLoc.x;
			fruitBox.y = fruitLoc.y;
		}

		// Controls
		moveDirection();

		// The previous position of the player block
		snakeLoc.prex = snakeLoc.x;
		snakeLoc.prey = snakeLoc.y;

		if (up) {
			snakeLoc.y -= delta * hscale;
		}
		else if (left) {
			snakeLoc.x -= delta * hscale;
		}
		else if (right) {
			snakeLoc.x += delta * hscale;
		}
		else if (down) {
			snakeLoc.y += delta * hscale;
		}

		if (redo == true) {

			redo = false;
			getFruitLoc(hscale, wscale, tailX, tailY);

			if (fruitLoc.x == -100 && fruitLoc.y == -100) {
				redo = true;
			}

		}

		//Check the Collision
		if (checkCollision()) {

			// Spawn new food after it has been eaten
			getFruitLoc(hscale, wscale, tailX, tailY);
			fruitBox.x = fruitLoc.x;
			fruitBox.y = fruitLoc.y;

			if (fruitLoc.x == -100 && fruitLoc.y == -100) {
				redo = true;
			}

			tailLength++;
		}

		// Only runs in the frames where the player block has moved
		if (delta * hscale == 24) {

			// Update tail size and position
			if (tailX.size() != tailLength) {
				tailX.push_back(snakeLoc.prex);
				tailY.push_back(snakeLoc.prey);
			}

			//Loop through every tail block, move all blocks to the nearest block in front
			//This updates the blocks from end (farthest from player block) to the start (nearest to player block)
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

		// Game over if player has collided with a tail block, also reset everything
		for (int i = 0; i < tailLength; i++) {
			if (snakeLoc.x == tailX[i] && snakeLoc.y == tailY[i]) {
				gameOver(renderer, hscale, wscale);
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

				getFruitLoc(hscale, wscale, tailX, tailY);
				if (fruitLoc.x == -100 && fruitLoc.y == -100) {
					redo = true;
				}

				fruitBox.x = fruitLoc.x;
				fruitBox.y = fruitLoc.y;
			}
		}

		// Game over if player out of bounds, also resets the game state
		if (snakeLoc.x < 0 || snakeLoc.y < 0 || snakeLoc.x > hscale * wscale - hscale || snakeLoc.y > hscale * wscale - hscale) {
			gameOver(renderer, hscale, wscale);
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
			getFruitLoc(hscale, wscale, tailX, tailY);
			fruitBox.x = fruitLoc.x;
			fruitBox.y = fruitLoc.y;

			if (fruitLoc.x == -100 && fruitLoc.y == -100) {
				redo = true;
			}

		}

		// Render everything
		renderFruit(renderer);
		renderSnake(renderer, hscale, tailX, tailY);
		printScore(renderer, hscale, wscale);

		SDL_RenderDrawLine(renderer, 0, 0, 0, hscale * wscale);
		SDL_RenderDrawLine(renderer, 0, hscale * wscale, hscale * wscale, hscale * wscale);
		SDL_RenderDrawLine(renderer, hscale * wscale, hscale * wscale, hscale * wscale, 0);
		SDL_RenderDrawLine(renderer, hscale * wscale, 0, 0, 0);

		// Put everything on screen
		// Nothing is actually put on screen until this is called
		SDL_RenderPresent(renderer);

		// Choose a color and fill the entire window with it, this resets everything before the next frame
		// This also give us the background color
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}

}

