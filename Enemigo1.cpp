#include "Enemigo1.h"

Enemigo1::Enemigo1(SDL_Renderer *renderer)
{
    this->renderer=renderer;

    textura = IMG_LoadTexture(renderer, "Enemigo1.png");
    bala = IMG_LoadTexture(renderer, "bala1.png");

    SDL_QueryTexture(textura,NULL,NULL,&rectangulo.w,&rectangulo.h);

    rectangulo.x = 0;
    rectangulo.y = 480 - rectangulo.h;
}

Enemigo1::~Enemigo1()
{
    //dtor
}

void Enemigo1::logica()
{
    for(list<Bala*>::iterator i=balas.begin();
        i!=balas.end();
        i++)
        (*i)->logica();

    if(rectangulo.x>=(640 - rectangulo.w))
        xStar*=-1;
    else if(rectangulo.x<0)
        xStar*=-1;
    rectangulo.x+=xStar;

    if(frame%15==0)
        {
            disparar2();
        }
    if(frame!=0 && frame<10000)
        if(frame%1000==0)
            {
                xStar++;
                velocidad_bala+=0.2;
            }
    frame++;
}

void Enemigo1::dibujar()
{
    for(list<Bala*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
    {
        SDL_RenderCopy(renderer, bala, NULL, &(*i)->rect_bala);
    }
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
}

void Enemigo1::disparar2()
	{
        SDL_Rect temp;
        SDL_QueryTexture(bala,NULL,NULL,&temp.w,&temp.h);
        temp.x = rectangulo.x + rectangulo.w*0.5 - temp.w*0.5;
        temp.y = rectangulo.y + rectangulo.h*0.5 - temp.h;
        Bala *b = new Bala(renderer,bala,temp);
        b->velocidad_x=0;
        b->velocidad_y=-velocidad_bala;
        balas.push_back(b);
	}
