/******************************************************************************
	������-�� SDL  ����� �������� �������� � ������������� �������� 32�32
	����������� �������� ������ 32�32 �� ��������� �� �����. ��������, ���� ��
	����� ������� ����������� 800�640, �������������� ��� ���� � �������������� SDL
	�� ������� 32�32, ��� �� ���������. ������� ����� 2 ��������, ���� ������� �����������
	� ������ ���������, ���� ��������� ����� 32�32.
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
		srcRect.h = height;// ������ ��������� �����������
		srcRect.w = width; //������ ��������� �����������
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x =  xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 2; //������ �����������, ������� �� ������ ���������� �� ������
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
					srcRect.y = 32;//���������� �� 1 ����
					srcRect.x = 128;// 4 ��������
				}
				else
				{
					srcRect.y = 32;// ���� �� 2 ����� 
					srcRect.x = 32;//� 1 ��������
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
		srcRect.h = height;// ������ ��������� �����������
		srcRect.w = width; //������ ��������� �����������
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 2; //������ �����������, ������� �� ������ ���������� �� ������
		destRect.h = srcRect.w * 2;
	}
	
	
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}