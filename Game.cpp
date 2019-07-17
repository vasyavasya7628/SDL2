/******************************************************************************

			 Инициализация вывода окна, проверка на корректную инициализацию 
			SDL, задержка закрытия приложения, обновление, рендер,  очистка.

*******************************************************************************/
#include "Game.h"
#include <sstream>
#include "Texture.h"
#include "GameObject.h"
#include "Map.h"



SDL_Renderer* Game::renderer = nullptr;//обнуление рендера
GameObject* player;
GameObject* tree;
SDL_Event Game::event;
SDL_Rect Game::camera = { 0,0,4000,2000 };
bool Game::isRunning = false;
Map* map;



Game::Game()
{}

Game::~Game()
{
	
}

void Game::init(const char* title, int width, int height, bool fullscreen)//инициализация SDL
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		
		}

		isRunning = true;
	}

	player = new GameObject("assets/skeleton/cheese.png", 100, 100, false, 10, 31, 32, true, 3);
	tree = new GameObject("assets/trees/baum.png", 50, 50, false , 1, 32, 32, false, 0);
	map = new Map();
}


void Game::handleEvents()//принятие решений в разные моменты игры, например упровление с помощью ввода, или когда наш игровой персонаж погибает
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()//где будет постоянно обновлятся другая логика игры
{
	player->Update();

}

void Game::render()//отрисовывает нашу графику при помощи функции
{
	SDL_RenderClear(renderer); // Очищает рендер в цвет
	map->DrawMap();
	player->Render();
	SDL_RenderPresent(renderer);// Рисует рендер в окне
}

void Game::clean()//которая удаляет из памяти все используемые нами ресурсы игры, спрайты,звуки, и другие ресурсы которые могут быть использованы в игре.
{
	SDL_DestroyWindow(window);//Удаляем окно
	SDL_DestroyRenderer(renderer);//Удаляем рендер
	SDL_Quit();
}

