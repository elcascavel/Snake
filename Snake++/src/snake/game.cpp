#include <SDL.h>
#include "game.h"

void Snake::Game::init()
{
    const int SCREEN_FPS = 60;
    const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	else {
		// Create window
		window = SDL_CreateWindow("Snake++ || Score: ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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

    srand(time(0));
    int foodX = rand() % screen_w;
    int foodY = rand() % screen_h;

	player->init(screen_w / 2 - 15, screen_h / 2 - 15);
    food->init(foodX, foodY);

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
    player->update(screen_w, screen_h);
    food->update(player->m_playerRect[0], screen_w, screen_h);
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