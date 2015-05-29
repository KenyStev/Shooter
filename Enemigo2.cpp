#include "Enemigo2.h"

Enemigo2::Enemigo2(SDL_Renderer *renderer)
{
    this->renderer=renderer;

    textura = IMG_LoadTexture(renderer, "Enemigo2.png");
    bala = IMG_LoadTexture(renderer, "bala1.png");

    SDL_QueryTexture(textura,NULL,NULL,&rectangulo.w,&rectangulo.h);

    rectangulo.x = 640 - rectangulo.w;
    rectangulo.y = 200;
}

Enemigo2::~Enemigo2()
{
    //dtor
}

void Enemigo2::logica()
{
    for(list<Bala*>::iterator i=balas.begin();
        i!=balas.end();
        i++)
        (*i)->logica();

    if(rectangulo.y>=(480 - rectangulo.h))
        yStar*=-1;
    else if(rectangulo.y<0)
        yStar*=-1;
    rectangulo.y+=yStar;

    if(frame%15==0)
        {
            disparar2();
        }
    if(frame!=0 && frame<10000)
        if(frame%1000==0)
            {
                velocidad_bala+=0.3;
            }

    for(list<Bala*>::iterator i=balas.begin();
        i!=balas.end();
        i++)
        {
            if((*i)->rect_bala.x<0)
            {
                balas.erase(i);
                break;
            }
        }
    frame++;
}

void Enemigo2::dibujar()
{
    for(list<Bala*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
    {
        SDL_RenderCopy(renderer, bala, NULL, &(*i)->rect_bala);
    }
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
}

void Enemigo2::disparar2()
	{
        SDL_Rect temp;
        SDL_QueryTexture(bala,NULL,NULL,&temp.w,&temp.h);
        temp.x = rectangulo.x + rectangulo.w*0.5 - temp.w*0.5;
        temp.y = rectangulo.y + rectangulo.h*0.5 - temp.h;
        Bala *b = new Bala(renderer,bala,temp);
        b->velocidad_x=-velocidad_bala;
        b->velocidad_y=0;
        balas.push_back(b);
	}
