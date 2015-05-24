#include "Enemigo3.h"

Enemigo3::Enemigo3(SDL_Renderer *renderer)
	{
	this->renderer=renderer;

	textura = IMG_LoadTexture(renderer, "Enemigo3.png");
	bala = IMG_LoadTexture(renderer, "bala1.png");

	SDL_QueryTexture(textura,NULL,NULL,&rectangulo.w,&rectangulo.h);

	rectangulo.x = 400;
	rectangulo.y = 100;
	}

Enemigo3::~Enemigo3()
	{
	//dtor
	}


void Enemigo3::logica()
	{
        for(list<Bala*>::iterator i=balas.begin();
        i!=balas.end();
        i++)
        (*i)->logica();

        if(rectangulo.y<50)
            yTemp*=-1;
        else if(rectangulo.y>150)
            yTemp*=-1;

        if(rectangulo.x<50)
            xTemp*=-1;
        else if(rectangulo.x>400)
            xTemp*=-1;

        rectangulo.x+=xTemp;
        rectangulo.y+=yTemp;

        if(frame%15==0)
        {
            disparar2();
        }
        if(frame!=0 && frame<10000)
            if(frame%1000==0)
                {
                    velocidad_bala+=0.3;
                }
        frame++;
	}

void Enemigo3::dibujar()
	{
        for(list<Bala*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
        {
            SDL_RenderCopy(renderer, bala, NULL, &(*i)->rect_bala);
        }
        SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
	}

void Enemigo3::disparar2()
	{
        SDL_Rect temp;
        SDL_QueryTexture(bala,NULL,NULL,&temp.w,&temp.h);
        temp.x = rectangulo.x + rectangulo.w*0.5 - temp.w*0.5;
        temp.y = rectangulo.y + rectangulo.h*0.5 - temp.h;
        Bala *b = new Bala(renderer,bala,temp);
        b->velocidad_x=0;
        if(yTemp<0)
            b->velocidad_y=-velocidad_bala;
        else if(yTemp>0)
            b->velocidad_y=velocidad_bala;
        balas.push_back(b);
	}
