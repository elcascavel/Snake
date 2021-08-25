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
		window = SDL_CreateWindow("Snake++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			is_running = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
	}
	player = new Player();
	player->init(30, 30);

	is_running = true;
}

void Snake::Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 150, 255);
	SDL_RenderClear(renderer);
	player->render(renderer);
	SDL_RenderPresent(renderer);
}

void Snake::Game::update()
{
    player->update();
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
        case SDL_WINDOWEVENT:
            switch (event.window.event) {
            case SDL_WINDOWEVENT_SHOWN:
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_GetWindowSize(window, &screen_w, &screen_h);
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