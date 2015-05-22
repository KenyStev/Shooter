#include "Nave.h"

Nave::Nave(SDL_Renderer *renderer)
{
    this->renderer = renderer;

    nave = IMG_LoadTexture(renderer,"Nave.png");
    bala = IMG_LoadTexture(renderer,"bala.png");

    SDL_QueryTexture(nave,NULL,NULL,&rect_nave.w,&rect_nave.h);

    rect_nave.x=0;
    rect_nave.y=100;

    nave_x = rect_nave.x;
    nave_y = rect_nave.y;

}

Nave::~Nave()
{
    //dtor
}

void Nave::logica()
{
    const Uint8 *estaPresionada = SDL_GetKeyboardState(NULL);

    float velocidad=1.5;
    if(estaPresionada[SDL_SCANCODE_LSHIFT])
    {
        velocidad=0.5;
    }

    if(estaPresionada[SDL_SCANCODE_A])
    {
        nave_x-=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_D])
    {
        nave_x+=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_W])
    {
        nave_y-=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_S])
    {
        nave_y+=velocidad;
    }

    rect_nave.x = nave_x;
    rect_nave.y = nave_y;

    if(estaPresionada[SDL_SCANCODE_Q])
    {
        SDL_Rect *temp = new SDL_Rect;
            SDL_QueryTexture(bala,NULL,NULL,&temp->w,&temp->h);
            temp->x =rect_nave.x;
            temp->y =rect_nave.y;
        balas.push_back(temp);
    }

    for(list<SDL_Rect*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
        {
            SDL_RenderCopy(renderer, bala, NULL, *i);
            (*i)->x+=5;
        }
}

void Nave::dibujar()
{
    SDL_RenderCopy(renderer, nave, NULL, &rect_nave);


        for(list<SDL_Rect*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
        {
            SDL_RenderCopy(renderer, bala, NULL, *i);
            if((*i)->x>=500)
            {
                balas.erase(i);
                break;
            }
        }


//    SDL_RenderPresent(renderer);
}
