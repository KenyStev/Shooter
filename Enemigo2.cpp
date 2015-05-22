#include "Enemigo2.h"

Enemigo2::Enemigo2(SDL_Renderer *renderer)
{
    this->renderer=renderer;

    enemigo = IMG_LoadTexture(renderer, "Enemigo2.png");

    SDL_QueryTexture(enemigo,NULL,NULL,&rect_enemigo.w,&rect_enemigo.h);

    rect_enemigo.x = 400;
    rect_enemigo.y = 200;
}

Enemigo2::~Enemigo2()
{
    //dtor
}

void Enemigo2::logica()
{
    if(rect_enemigo.y>=400)
        yStar*=-1;
    else if(rect_enemigo.y<=50)
        yStar*=-1;
    rect_enemigo.y+=yStar;

}

void Enemigo2::dibujar()
{
    SDL_RenderCopy(renderer, enemigo, NULL, &rect_enemigo);
}
