#include "Personaje.h"

Personaje::Personaje()
{
    //ctor
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::disparar()
	{
        SDL_Rect *temp = new SDL_Rect;
        SDL_QueryTexture(bala,NULL,NULL,&temp->w,&temp->h);
        temp->x = rectangulo.x + rectangulo.w - temp->w;
        temp->y = rectangulo.y + rectangulo.h*0.5 - temp->h;
        Balas.push_back(temp);
	}

void Personaje::disparar2()
	{
        SDL_Rect temp;
        SDL_QueryTexture(bala,NULL,NULL,&temp.w,&temp.h);
        temp.x = rectangulo.x + rectangulo.w - temp.w;
        temp.y = rectangulo.y + rectangulo.h*0.5 - temp.h;
        balas.push_back(new Bala(renderer,bala,temp));
	}
