/******************************************************************************

			Различные  игровые объекты. Например player, enemy, ally.

*******************************************************************************/
#pragma once
#include "Game.h"

class GameObject {
public:
	 GameObject(const char* texturesheet, int x, int y, bool ai, int frame, int w, int h, bool anim, int s);
	~GameObject();

	void Update();
	void Render();

private:
	int width;
	int height;
	int frames;
	int xpos;
	int ypos;
	int speed;
	bool animated;
	bool artifInt;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;// исходный приямоугольник нашей текстуры положение в пространстве
	SDL_Renderer* renderer;
	

};