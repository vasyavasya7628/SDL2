/******************************************************************************

			 ������������� ������ ����, �������� �� ���������� ������������� 
			SDL, �������� �������� ����������, ����������, ������,  �������.

*******************************************************************************/
#include "Game.h"
#include <sstream>
#include "Texture.h"
#include "GameObject.h"
#include "Map.h"



SDL_Renderer* Game::renderer = nullptr;//��������� �������
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

void Game::init(const char* title, int width, int height, bool fullscreen)//������������� SDL
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


void Game::handleEvents()//�������� ������� � ������ ������� ����, �������� ���������� � ������� �����, ��� ����� ��� ������� �������� ��������
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

void Game::update()//��� ����� ��������� ���������� ������ ������ ����
{
	player->Update();

}

void Game::render()//������������ ���� ������� ��� ������ �������
{
	SDL_RenderClear(renderer); // ������� ������ � ����
	map->DrawMap();
	player->Render();
	SDL_RenderPresent(renderer);// ������ ������ � ����
}

void Game::clean()//������� ������� �� ������ ��� ������������ ���� ������� ����, �������,�����, � ������ ������� ������� ����� ���� ������������ � ����.
{
	SDL_DestroyWindow(window);//������� ����
	SDL_DestroyRenderer(renderer);//������� ������
	SDL_Quit();
}

