#include "Enemigo3.h"

Enemigo3::Enemigo3(SDL_Renderer *renderer)
	{
	this->renderer=renderer;

	enemigo = IMG_LoadTexture(renderer, "Enemigo3.png");

	SDL_QueryTexture(enemigo,NULL,NULL,&rect_enemigo.w,&rect_enemigo.h);

	rect_enemigo.x = 400;
	rect_enemigo.y = 100;
	}

Enemigo3::~Enemigo3()
	{
	//dtor
	}


void Enemigo3::logica()
	{
        if(rect_enemigo.y<50)
            yTemp*=-1;
        else if(rect_enemigo.y>150)
            yTemp*=-1;

        if(rect_enemigo.x<50)
            xTemp*=-1;
        else if(rect_enemigo.x>400)
            xTemp*=-1;

        rect_enemigo.x+=xTemp;
        rect_enemigo.y+=yTemp;
	}

void Enemigo3::dibujar()
	{
        SDL_RenderCopy(renderer, enemigo, NULL, &rect_enemigo);
	}
