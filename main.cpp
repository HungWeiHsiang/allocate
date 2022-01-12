#include "game.h"
#include "gameobject.h"

Game *game;
int frame = 0;
//initialize,upload and end the game
int main(int argc,char *argv[])
{
	const int fps=8;
	const int fdelay=320/fps;
	Uint32 fstart;
	int ftime;
	game=new Game();
	game->init("Running Chick",
	SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
	800,672,false);
	//let the game update
	while(game->running())
	{
		
		fstart=SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		ftime=SDL_GetTicks()-fstart;
		if(fdelay>ftime)
		{
			SDL_Delay(fdelay-ftime);
		}
        ++frame;
        if (frame/4 > 2)
            frame = 0;
	}
	//
	game->clean();
	
	return 0;
}
//
