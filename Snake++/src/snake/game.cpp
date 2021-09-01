#pragma once
#include <SDL.h>
#include "game.h"

void Snake::Game::init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	else {
		// Create window
		window = SDL_CreateWindow("Snake++ || Score: ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			is_running = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}
	}
    
    player = new Player();
    food = new Food();
    food->respawn();
	is_running = true;
}

void Snake::Game::render()
{
	SDL_SetRenderDrawColor(renderer, 76, 71, 79, 255);
	SDL_RenderClear(renderer);
    player->render(renderer);
    food->render(renderer);
	SDL_RenderPresent(renderer);
}

void Snake::Game::update()
{
    player->update();
    if (player->getHeadXPosition() == food->getFoodXPosition() && player->getHeadYPosition() == food->getFoodYPosition())
    {
        food->respawn();
        SnakeSegment nextSegment(player->x, player->y);
        player->segments.push_front(nextSegment);
    }
}

void Snake::Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                player->setDirection(SDLK_UP);
                break;
            case SDLK_DOWN:
                player->setDirection(SDLK_DOWN);
                break;
            case SDLK_LEFT:
                player->setDirection(SDLK_LEFT);
                break;
            case SDLK_RIGHT:
                player->setDirection(SDLK_RIGHT);
                break;
            case SDLK_ESCAPE:
                is_running = false;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Snake::Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
