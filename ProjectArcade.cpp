/******************************************************************************

	Ограничение кадров, бесконечный цикл с условием выхода.

*******************************************************************************/
#include "Game.h"

int main(int argc, char* argv[])
{


	static const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Game game;
	game.init("GameWindow", 800, 640, false);

	while (game.running())
	{
		Uint32 frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		int frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game.clean();

	return 0;
}