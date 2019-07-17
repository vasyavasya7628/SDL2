#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <map>





class Game
{
public:
	Game();
	~Game();
	//ќбъ€вление функции
	void init(const char* title, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	//ѕеременные
	static SDL_Renderer* renderer;//рендер
	static SDL_Event event;//событие
	static bool isRunning;//запущена ли игра
	static SDL_Rect camera;//камера

private:

	int cnt = 0;
	SDL_Window* window;//окно
	
};