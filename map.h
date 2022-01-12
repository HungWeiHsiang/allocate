#pragma once
#include "game.h"

class Map
{
public:
	Map();
	~Map();
	int map[20][25];
	void LoadMap(int arr[20][25]);
	void DrawMap();
	void upd();
private:
	SDL_Rect src,dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
};
