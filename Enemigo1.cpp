#include "Enemigo1.h"

Enemigo1::Enemigo1(SDL_Renderer *renderer)
{
    this->renderer=renderer;

    enemigo = IMG_LoadTexture(renderer, "Enemigo1.png");

    SDL_QueryTexture(enemigo,NULL,NULL,&rect_enemigo.w,&rect_enemigo.h);

    rect_enemigo.x = 400;
    rect_enemigo.y = 200;
}

Enemigo1::~Enemigo1()
{
    //dtor
}

void Enemigo1::logica()
{
    if(rect_enemigo.x>=400)
        xStar*=-1;
    else if(rect_enemigo.x<=50)
        xStar*=-1;
    rect_enemigo.x+=xStar;

}

void Enemigo1::dibujar()
{
    SDL_RenderCopy(renderer, enemigo, NULL, &rect_enemigo);
}
