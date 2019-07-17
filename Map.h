/******************************************************************************
							   ласс Map
 арта состоит из плиток, у каждой плитки есть свой код, 
на эти коды в матрице накладываютс€ текстуры. ќбрабатываетс€ это все циклом for
*******************************************************************************/


#pragma once
#include "Game.h"

class Map
{
public:
	
	Map();
	
	~Map();
	void LoadMap(int arr[64][64]);
	void DrawMap();

private:
	
	SDL_Rect src, dest;
	

	SDL_Texture* tex19;
	SDL_Texture* tex44;
	SDL_Texture* tex57;
	SDL_Texture* tex51;
	SDL_Texture* tex54;
	SDL_Texture* tex53;
	SDL_Texture* tex10;
	SDL_Texture* tex48;
	SDL_Texture* tex49;
	SDL_Texture* tex1;
	
	


	int map[64][64];
};