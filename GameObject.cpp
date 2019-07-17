/******************************************************************************
	Почему-то SDL  умеет работать тольлько с изображениями размером 32х32
	Изображения размером больше 32х32 не выводятся на экран. Например, если мы
	хотим вывести изображение 800х640, предворительно его сжав с использованием SDL
	до размера 32х32, оно не выведется. Поэтому здесь 2 варианта, либо сжимать изображение
	в другой программе, либо загружать сразу 32х32.
*******************************************************************************/

#include "GameObject.h"
#include "Texture.h"


GameObject::GameObject(const char* texturesheet, int x, int y, bool ai, int frame, int w, int h, bool anim, int s)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	frames = frame;
	artifInt = ai;
	width = w;
	height = h;
	animated = anim;
	speed = s;
	
}

	
	
	

void GameObject::Update()
{

	

	
	if (animated == true)
	{
		srcRect.h = height;// высота исходного изображения
		srcRect.w = width; //ширина исходного изображения
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x =  xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 2; //ширина изображения, которое вы хотите отобразить на экране
		destRect.h = srcRect.w * 2;
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (srcRect.y == 64 & srcRect.x == 32)
				{
					srcRect.y = 64;
					srcRect.x = 128;
				}
				else

				srcRect.y = 64;
				srcRect.x = 32;
				destRect.x -= speed;
				xpos = destRect.x;
				break;
			case SDLK_RIGHT:
				if (srcRect.y == 96 & srcRect.x == 32)
				{
					srcRect.y = 96;
					srcRect.x = 128;
				}
				else
				{
					srcRect.y = 96;
					srcRect.x = 32;
					destRect.x += speed;
					xpos = destRect.x;
				}

				break;
			case SDLK_UP:
				if (srcRect.y == 32 & srcRect.x == 32)
				{
					srcRect.y = 32;//спускаемся на 1 этаж
					srcRect.x = 128;// 4 квартира
				}
				else
				{
					srcRect.y = 32;// ищем со 2 этажа 
					srcRect.x = 32;//с 1 квартиры
					destRect.y -= speed;
					ypos = destRect.y;
				}
				break;
			case SDLK_DOWN:
				if (srcRect.x == 32)
				{
					srcRect.x = 128;
				}
				else
				{
					srcRect.x = 32;
					destRect.y += speed;
					ypos = destRect.y;
				}

				break;
			}
		}
	}
	if(animated != true)
	{
		srcRect.h = height;// высота исходного изображения
		srcRect.w = width; //ширина исходного изображения
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 2; //ширина изображения, которое вы хотите отобразить на экране
		destRect.h = srcRect.w * 2;
	}
	
	
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}