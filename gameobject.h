#pragma once
#include "game.h"

int ggov();
int finn();
class Ddigi
{
public:
	Ddigi(const char* texturesheet,int x,int y);
	~Ddigi();
	void Update();
private:
	int xpos;
	int ypos;
	int i;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
class GameObject
{
public:
	GameObject(const char* texturesheet,int x,int y);
	~GameObject();
	void Update();
	void Render();
	void dead();
	void gameover();
	void dis();
private:
	int xpos;
	int ypos;
	int i;
	int sto;
	int stoo;
	int det;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
class Ghost
{
public:
	Ghost(const char* texturesheet,int x,int y);
	~Ghost();
	void Update();
	void Render();
	void dead();
	void gameover();
	void dis();
private:
	int xpos;
	int ypos;
	int i;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
class Player
{
public:
	Player(const char* texturesheet,int x,int y);
	~Player();
	void Update();
	void Render();
	void handleEvent( SDL_Event& e );
private:
	int xpo;
	int ypo;
	int j;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
class Chi
{
public:
	Chi(const char* texturesheet,int x,int y);
	~Chi();
	void Update();
	void Render();
	void ced();
	void finish();
private:
	int xpo;
	int ypo;
	int j;
	int sto;
	int stoo;
	int det;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
