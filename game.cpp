#include "game.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "map.h"
using namespace std;

GameObject* ghost1;
GameObject* ghost2;
GameObject* ghost3;
GameObject* ghost4;
Ghost* ghost5;
Ghost* ghost6;
Chi* chi1;
Chi* chi2;
Chi* chi3;
Chi* chi4;
Player* p1;
Map* map;
SDL_Renderer* Game::renderer;
static int ruu=0;

Game::Game()
{
	
}
Game::~Game()
{
	
}

void Game::init(const char *title,int xpos,int ypos,
int width,int height,bool fullscreen)
{
	int flags=0;
	//initialize the game
	if(fullscreen==-1)
	{
		flags=SDL_WINDOW_FULLSCREEN;
	}
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
    }
    else
    {
        window = SDL_CreateWindow( title, xpos, ypos, width, height, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
        }
        else
        {
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
            }
            else
            {
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                ruu = 1;
            }
        }
    }
    // 
    //creat object and map
	ghost1=new GameObject("clouddd.bmp",96,96);
	ghost2=new GameObject("clouddd.bmp",672,512);
	ghost3=new GameObject("clouddd.bmp",672,96);
	ghost4=new GameObject("clouddd.bmp",96,512);
	ghost5=new Ghost("crabb.bmp",384,96);
	ghost6=new Ghost("crabb.bmp",384,512);
	chi1=new Chi("chickenn.bmp",96,288);
	chi2=new Chi("chickenn.bmp",672,320);
	chi3=new Chi("chickenn.bmp",384,32);
	chi4=new Chi("chickenn.bmp",384,576);
	p1=new Player("baby.png",384,304);
	map=new Map();
	//
}

void Game::handleEvents()
{
	//update the player's position
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 )
    {
    SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			ruu=0;
			break;
		default:
			break;
	}	
        p1->handleEvent( e );
        if(ggov())
		{
			map->DrawMap();
			break;
		}
    }	
    //
}
//update map and object
void Game::update()
{
	map->upd();
	p1->Update();
	ghost1->Update();
	ghost2->Update();
	ghost3->Update();
	ghost4->Update();
	ghost5->Update();
	ghost6->Update();
	chi1->Update();
	chi2->Update();
	chi3->Update();
	chi4->Update();	
}
//
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	chi1->Render();
	chi2->Render();
	chi3->Render();
	chi4->Render();
	ghost1->Render();
	ghost2->Render();
	ghost3->Render();
	ghost4->Render();
	ghost5->Render();
	ghost6->Render();
	p1->Render();
	SDL_RenderPresent(renderer);
}
//end the game 
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
    IMG_Quit();
}
// 
bool Game::running()
{
	return ruu;
}
