#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"
#include "map.h"
#include <cstdlib>
#include <cmath>
using namespace std;
int gx;
int gy;
int px;
int py;
int cx;
int cy;
int gover=0;
int fin=0;
int cch=0;
int tes=0;
int ugl=1;
int star=300;
static int cntt=0;
static int s=1;
static int v=2;
static int u=4;
static int uup=0;
static int ddo=0;
static int lle=0;
static int rri=0;
static int cup;
static int cdo;
static int cle;
static int cri;
static int nup;
static int ndo;
static int nle;
static int nri;
static int kee=0;
static int acc=1;
extern int frame;
extern int lvl1[20][25];
// judge whether the game is finished(successed or failed)
int ggov()
{
	if(gover!=1)
	{
		return 0;	
	}
	uup=0;
	ddo=0;
	lle=0;
	rri=0;
	return 1;
}
//
// judge whether the game is successed 
int finn()
{
	if(fin!=1)
	{
		return 0;	
	}
	return 1;
}
//
GameObject::GameObject(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}

void GameObject::Update()
{
	//when gameover,put the clouds out of the window
	if(gover==1)
	{
		xpos=800;
		ypos=800;
	}
	//
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpos;
	int r=ypos;
	star=star+1;
	//every object is stationary when the game starts(let player knows the NPCs' position when the game starts)
	if(star>400)
	{
	//
	//let clouds can chase player
	if(cntt>=1000)
	{
		if(xpos==px&&ypos-py<=96&&ypos>py)
		{
			if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(ypos==py&&xpos-px<=96&&xpos>px)
		{
			if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
			else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
		}
		else if(xpos==px&&py-ypos<=96&&ypos<py)
		{
			if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(ypos==py&&px-xpos<=96&&xpos<px)
		{
			if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
		}
		else if(xpos-px<=48&&xpos>px&&ypos-py<=48&&ypos>py)
		{
			if(xpos-px>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			if(xpos-px<ypos-py&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(px-xpos<=48&&xpos<px&&ypos-py<=48&&ypos>py)
		{
			if(px-xpos>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			if(px-xpos<ypos-py&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
		}
		else if(px-xpos<=48&&xpos<px&&py-ypos<=48&&ypos<py)
		{
			if(px-xpos>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			if(px-xpos<py-ypos&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
		}
		else if(xpos-px<=48&&xpos>px&&py-ypos<=48&&ypos<py)
		{
			if(xpos-px>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			if(xpos-px>=py-ypos&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
	}
	//
	//if clouds didn't chase the player,let it move randomly
	//we judge if the move is efficient(ie didn't bump into wall),ex.lvl1[ypos/32][xpos/32+1]!=0,lvl1[(ypos+31)/32][xpos/32+1]!=0
	//to avoid the cloud moving forward and backward repeatly,we let the clouds will not move the opposite side to it's bofore move,ex.i!=2(i=0:right,i=1:down'i=2:left,i=3:up)   
	if(t==xpos&&r==ypos)
	{
		while(gover==0&&t==xpos&&r==ypos)
		{
			int tt=rand()%10+3;
			int dn=tt%4;
			switch(dn)
			{
			case 0:
				if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
				{
					xpos=xpos+s*acc;
					i=0;
					break;
				}
			case 1:
				if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
				{
					ypos=ypos+s*acc;
					i=1;
					break;
				}
			case 2:
				if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
				{
					xpos=xpos-s*acc;
					i=2;
					break;
				}
			case 3:
				if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
				{
					ypos=ypos-s*acc;
					i=3;
					break;
				}
			default:
				{
					break;	
				}		
			}
		}
	}
	//
	//
	//
	//because the coulds will accelerate,we need to ajdust their posotion to avoid them can't turn
	if(acc==4&&xpos%4==2)
	{
		if(xpos%32==2)
		{
			xpos=xpos-2;
		}
		if(xpos%32==30)
		{
			xpos=xpos+2;
		}
	}
	if(acc==4&&ypos%4==2)
	{
		if(ypos%32==2)
		{
			ypos=ypos-2;
		}
		if(ypos%32==30)
		{
			ypos=ypos+2;
		}
	}
	if(acc==2&&xpos%2==1)
	{
		if(xpos%32==1)
		{
			xpos=xpos-1;
		}
		if(xpos%32==31)
		{
			xpos=xpos+1;
		}
	}
	if(acc==2&&ypos%2==1)
	{
		if(ypos%32==1)
		{
			ypos=ypos-1;
		}
		if(ypos%32==31)
		{
			ypos=ypos+1;
		}
	}
	//
	}
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	//judge whether player is catched by the cloud
	if(t<800)
	{
		dead();
	}
	//
}
//judge whether player is catched by the cloud
void GameObject::dead()
{
	if((gx-px<24&&px-gx<24&&gy==py)||(gy-py<24&&py-gy<24&&px==gx)||(gx-px<12&&px-gx<12&&gy-py<12&&py-gy<12))
	{
		gameover();
	}
}
//
//judge gameover
void GameObject::gameover()
{
	gover=1;
}
//
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Ghost::Ghost(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
void Ghost::Update()
{
	//when gameover,put the crabs out of the window
	if(gover==1)
	{
		xpos=800;
		ypos=800;
	}
	//
	cntt=cntt+1;
	if(cntt>=1000&&gover==0)
	{
		
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpos;
	int r=ypos;
	star=star+1;
	//every object is stationary when the gane starts(let player knows the NPCs' position when the game starts)
	if(star>400)
	{
	//
		//let crabs move after the walls are break 
		while(cntt>=1000&&gover==0&&t==xpos&&r==ypos)
		{
		//
			//when the crab is too close to player,let it decelerate
			if(xpos-px>=-128&&ypos-py>=-128&&xpos-px<=128&&ypos-py<=128)
			{
				int tt=rand()%10+3;
				int dn=tt%4;
				switch(dn)
				{
				case 0:
					if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
					{
						xpos=xpos+4;
						i=0;
						break;
					}
				case 1:
					if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
					{
						ypos=ypos+4;
						i=1;
						break;
					}
				case 2:
					if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
					{
						xpos=xpos-4;
						i=2;
						break;
					}
				case 3:
					if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
					{
						ypos=ypos-4;
						i=3;
						break;
					}
				default:
					{
						break;	
					}		
				}	
			}
			//
			//when the crab isn't too close to player,let it move randomly
			else
			{
				//because the coulds will accelerate,we need to ajdust their posotion to avoid them can't turn
				if(xpos%32==4)
				{
					xpos=xpos-4;
				}
				if(xpos%32==28)
				{
					xpos=xpos+4;
				}
				if(ypos%32==4)
				{
					ypos=ypos-4;
				}
				if(ypos%32==28)
				{
					ypos=ypos+4;
				}
				if(xpos%32==24)
				{
					xpos=xpos+8;
				}
				if(xpos%32==8)
				{
					xpos=xpos-8;
				}
				if(ypos%32==24)
				{
					ypos=ypos+8;
				}
				if(ypos%32==8)
				{
					ypos=ypos-8;
				}
				if(xpos%32==12)
				{
					xpos=xpos-12;
				}
				if(xpos%32==20)
				{
					xpos=xpos+12;
				}
				if(ypos%32==12)
				{
					ypos=ypos-12;
				}
				if(ypos%32==20)
				{
					ypos=ypos+12;
				}
				//
				int tt=rand()%10+3;
				int dn=tt%4;
				switch(dn)
				{
				case 0:
					if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
					{
						xpos=xpos+16;
						i=0;
						break;
					}
				case 1:
					if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
					{
						ypos=ypos+16;
						i=1;
						break;
					}
				case 2:
					if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
					{
						xpos=xpos-16;
						i=2;
						break;
					}
				case 3:
					if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
					{
						ypos=ypos-16;
						i=3;
						break;
					}
				default:
					{
						break;	
					}		
				}	
			}
			//	
		}
	}
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	//judge whether player is too close to the crabs
	if(t<800)
	{
		dead();
	}
	//
}
//judge whether player is too close to the crabs
void Ghost::dead()
{
	if((gx-px<24&&px-gx<24&&gy==py)||(gy-py<24&&py-gy<24&&px==gx)||(gy-py<12&&py-gy<12&&gx-px<12&&px-gx<12)) 
	{
		gameover();
	}
}
//
//jugde gameover
void Ghost::gameover()
{
	gover=1;
}
//
void Ghost::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Player::Player(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}

static int dir=-1;
void Player::handleEvent( SDL_Event& e )
{
	//let player can move 
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 1;
			nup = 1;
			break;
        case SDLK_DOWN: 
			ddo = 1;
			ndo = 1;  
			break;
        case SDLK_LEFT: 
			lle = 1;
			nle = 1;
			break;
        case SDLK_RIGHT: 
			rri = 1;
			nri = 1;
			break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 0;
			nup = 0;
			cup=0; 
			break;
    	case SDLK_DOWN: 
			ddo = 0;
			ndo = 0;
			cdo=0; 
			break;
        case SDLK_LEFT: 
			lle = 0;
			nle = 0;
			cle=0; 
			break;
        case SDLK_RIGHT: 
			rri = 0;
			nri = 0;
			cri=0; 
			break;
        }
    }
    //
}
void Player::Update()
{
	//when gameover,put the player out of the window
	if(gover==1)
	{
		xpo=800;
		ypo=800;
	}
	//
	//compute how long the butter is pressed(right:cri,down:cdo,left:cle,up:cup)
	if(uup == 1) 
	cup=cup+1; 
	if(ddo == 1)
	cdo=cdo+1; 
	if(lle == 1)
	cle=cle+1;
	if(rri == 1)
	cri=cri+1;
	//
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int xyx=xpo;
	int yxy=ypo;
	star=star+1;
	//let player can move earlier than NPC
	if(star>300)
	{
	//
		//if player press more than three bottom,let the bottom pressed earliest null 
		if(cup!=0&&cdo!=0&&cri!=0)
		{
			if(cup>=cdo&&cup>cri)
			{
				cup=0;
			}
			if(cdo>=cri&&cdo>cup)
			{
				cdo=0;
			}
			if(cri>=cup&&cri>cdo)
			{
				cri=0;
			}
		}
		if(cup!=0&&cdo!=0&&cle!=0)
		{
			if(cup>=cdo&&cup>cle)
			{
				cup=0;
			}
			if(cdo>=cle&&cdo>cup)
			{
				cdo=0;
			}
			if(cle>=cup&&cle>cdo)
			{
				cle=0;
			}
		}
		if(cle!=0&&cdo!=0&&cri!=0)
		{
			if(cle>=cdo&&cle>cri)
			{
				cle=0;
			}
			if(cdo>=cri&&cdo>cle)
			{
				cdo=0;
			}
			if(cri>=cle&&cri>cdo)
			{
				cri=0;
			}
		}
		if(cup!=0&&cri!=0&&cle!=0)
		{
			if(cup>=cri&&cup>cle)
			{
				cup=0;
			}
			if(cri>=cle&&cri>cup)
			{
				cri=0;
			}
			if(cle>=cup&&cle>cri)
			{
				cle=0;
			}
		}
		//
		//if player press up and down or right and left bottom at the same time,let the bottom pressed earlier null
		if((cup!=0&&cdo!=0)||(cri!=0&&cle!=0))
		{
			if(cup>cdo)
			{
				cup=0;
			}
			else if(cup<=cdo)
			{
				cdo=0;
			}
			if(cle>=cri)
			{
				cle=0;
			}
			else if(cle<cri)
			{
				cri=0;
			}
		}
		//
		//if player press two bottom,execute the bottom pressed later in advance.if the bottom pressed later is null(the player will bump into wall),execute the bottom pressed earlier.
		//player can turn before and after the intersection if he is colse to the intersection
		else if(cri!=0&&cdo!=0)
		{
			if(cri>cdo)
			{
				if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
				(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo+u;
					dir=1;
				}
				else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
				(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo+u;
					dir=0;
				}
			}
			else if(cri<=cdo)
			{
				if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
				(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo+u;
					dir=0;
				}
				else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
				(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo+u;
					dir=1;
				}
			}	
		}
		else if(cri!=0&&cup!=0)
		{
			if(cri>cup)
			{
				if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
				(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo-u;
					dir=3;
				}
				else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
				(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo+u;
					dir=0;
				}
			}
			else if(cri<=cup)
			{
				if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
				(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo+u;
					dir=0;
				}
				else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
				(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo-u;
					dir=3;
				}
			}	
		}
		else if(cle!=0&&cup!=0)
		{
			if(cle<=cup)
			{
				if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
				||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo-u;
					dir=2;
				}
				else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
				(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo-u;
					dir=3;
				}	
			}
			else if(cle>cup)
			{
				if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
				(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo-u;
					dir=3;
				}
				else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
				||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo-u;
					dir=2;
				}
			}	
		}
		else if(cle!=0&&cdo!=0)
		{
			if(cle<=cdo)
			{
				if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
				||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo-u;
					dir=2;
				}
				else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
				(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo+u;
					dir=1;
				}
			}	
			else if(cle>cdo)
			{
				if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
				(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					if(xpo%32==4)
					{
						xpo=xpo-4;
					}
					if(xpo%32==28)
					{
						xpo=xpo+4;
					}
					ypo=ypo+u;
					dir=1;
				}
				else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
				||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					if(ypo%32==4)
					{
						ypo=ypo-4;
					}
					if(ypo%32==28)
					{
						ypo=ypo+4;
					}
					xpo=xpo-u;
					dir=2;
				}	
			}	
		}
		//
		//
		else if(ggov()!=1)
		{
			//if player press one bottom,judge if the direction is efficient(the player will not bump into wall)
			//player can turn before and after the intersection if he is colse to the intersection
			if(((nri==1&&nle!=1)||cri!=0)&&(lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
			else if(((ndo==1&&nup!=1)||cdo!=0)&&(lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
			else if(((nle==1&&nri!=1)||cle!=0)&&(lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}
			else if(((nup==1&&ndo!=1)||cup!=0)&&(lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}
			//
			//
		}
		//if player didn,t press any bottom or all bottom pressed is null(will bump into wall},people will move along his original direction for some distance 
		if(xyx==xpo&&yxy==ypo)
		{
			if(ggov()!=1)
			{
				if(kee==0)
				{
					kee=5;
				}
				else if(xpo%32==0&&ypo%32==0&&kee>2)
				{
					kee=kee-1;
				}
				if(kee>3)
				{
					if(dir==0&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						dir=0;
					}
					else if(dir==1&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						dir=1;
					}
					else if(dir==2&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						dir=2;
					}
					else if(dir==3&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						dir=3;
					}	
				}
			}
		}	
		if(uup==1||ddo==1||rri==1||lle==1)
		{
			kee=0;
		}
		//		
	}
	px=xpo;
	py=ypo;
    //change the picture
    if (frame/4 == 0)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 0;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 0;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 0;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 0;
                srcRect.y = 64;
                break;
	    }
    }
    if (frame/4 == 1)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 32;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 32;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 32;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 32;
                srcRect.y = 64;
                break;
        }
    }
    if (frame/4 == 2)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 64;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 64;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 64;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 64;
                srcRect.y = 64;
                break;
        }
    }
    //
    srcRect.w = 32;
    srcRect.h = 32;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Chi::Chi(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}
void Chi::Update()
{
	//when gameover,put the chickens out of the window
	if(gover==1&&ypo<640)
	{
		xpo=800;
		ypo=800;
	}
	//
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpo;
	int r=ypo;
	star=star+1;
	//every object is stationary when the gane starts(let player knows the NPCs' position when the game starts)
	if(star>400)
	{
	//
		// jugde if the chicken is catched
		if(r<640)
		{
		//
			//let the chicken move faster at the beginning when player is too close to it
			//let the chicken escape when player is too close to it
			if(det<16)
			{
				if(xpo==px&&ypo-py<=96&&ypo>py)
				{
					if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						j=1;
						det=det+1;
					}
					else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						j=0;
						det=det+1;
					}
					else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						j=2;
						det=det+1;
					}
				}
				else if(ypo==py&&xpo-px<=96&&xpo>px)
				{
					if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						j=0;
						det=det+1;
					}
					else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						j=3;
						det=det+1;
					}
					else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						j=1;
						det=det+1;
					}
				}
				else if(xpo==px&&py-ypo<=96&&ypo<py)
				{
					if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						j=3;
						det=det+1;
					}
					else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						j=0;
						det=det+1;
					}
					else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						j=2;
						det=det+1;
					}
				}
				else if(ypo==py&&px-xpo<=96&&xpo<px)
				{
					if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						j=2;
						det=det+1;
					}
					else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						j=3;
						det=det+1;
					}
					else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						j=1;
						det=det+1;
					}
				}
				else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
				{
					if(xpo-px<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						j=1;
						det=det+1;
					}
					if(xpo-px>ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						j=0;
						det=det+1;
					}
				}
				else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
				{
					if(px-xpo<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+u;
						j=1;
						det=det+1;
					}
					if(px-xpo>ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						j=2;
						det=det+1;
					}
				}
				else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
				{
					if(px-xpo<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						j=3;
						det=det+1;
					}
					if(px-xpo>py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-u;
						j=2;
						det=det+1;
					}
				}
				else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
				{
					if(xpo-px<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-u;
						j=3;
						det=det+1;
					}
					if(xpo-px>py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+u;
						j=0;
						det=det+1;
					}
				}
				//because the chickens will accelerate,we need to ajdust their posotion to avoid them can't turn
				if(det>0)
				{
					if(xpo%32==2)
					{
						xpo=xpo-2;
					}
					if(xpo%32==30)
					{
						xpo=xpo+2;
					}
					if(ypo%32==2)
					{
						ypo=ypo-2;
					}
					if(ypo%32==30)
					{
						ypo=ypo+2;
					}
				}
				//
			}
			//
			//
			//if the player is continuous too close to it,retuen to it's original speed
			//let the chicken escape when player is too close to it 
			if(det>=16)
			{
				if(xpo==px&&ypo-py<=96&&ypo>py)
				{
					if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+v;
						j=1;
						det=det+1;
					}
				}
				else if(ypo==py&&xpo-px<=96&&xpo>px)
				{
					if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+v;
						j=0;
						det=det+1;
					}
				}
				else if(xpo==px&&py-ypo<=96&&ypo<py)
				{
					if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-v;
						j=3;
						det=det+1;
					}
				}
				else if(ypo==py&&px-xpo<=96&&xpo<px)
				{
					if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-v;
						j=2;
						det=det+1;
					}
				}
				else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
				{
					if(px-xpo>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+v;
						j=1;
						det=det+1;
					}
					if(px-xpo<py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+v;
						j=0;
						det=det+1;
					}
				}
				else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
				{
					if(xpo-px>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+v;
						j=1;
						det=det+1;
					}
					if(xpo-px>=py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-v;
						j=2;
						det=det+1;
					}
				}
				else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
				{
					if(xpo-px>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-v;
						j=3;
						det=det+1;
					}
					if(xpo-px<ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-v;
						j=2;
						det=det+1;
					}
				}
				else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
				{
					if(px-xpo>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-v;
						j=3;
						det=det+1;
					}
					if(px-xpo<ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{
						xpo=xpo+v;
						j=0;
						det=det+1;
					}
				}
			}
			//
			//
			//when player isn't too close to it,let it move randomly
			//if player is too close to it but it can't escape
			while(gover==0&&r<640&&t==xpo&&r==ypo)
			{
				det=0;
				int tt=rand()%10+3;
				int dn=tt%4;
				switch(dn)
				{
				case 0:
					if(j!=2&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{	
						xpo=xpo+v;
						j=0;
						break;
					}
				case 1:
					if(j!=3&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+v;
						j=1;
						break;
					}
				case 2:
					if(j!=0&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-v;
						j=2;
						break;
					}	
				case 3:
					if(j!=1&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-v;
						j=3;
						break;
					}
				default:
					{
						break;	
					}		
				}		
			}
			//
			//	
		}
	}
	cx=xpo;
	cy=ypo;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	//judge whether chichen is catched
	if(r<640)
	{
		ced();
	}
	//
}
//judge whether chichen is catched
void Chi::ced()
{
	if((cx-px<16&&px-cx<16&&cy==py)||(cy-py<16&&py-cy<16&&cx==px)||(cy-py<8&&py-cy<8&&cx-px<8&&px-cx<8))
	{
		xpo=0+32*cch;
		ypo=640;
		cch=cch+1;
		//judge whether all chichen is catched
		if(cch==4)
		{
			finish();
		}
		//
	}
}
//
//judge success
void Chi::finish()
{
	gover=1;
	fin=1;
}
//
void Chi::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}
