#include "Nave.h"

Nave::Nave(SDL_Renderer *renderer,list<Personaje*> *actores,void (*detener)( char* args ))
{
    this->renderer = renderer;

    textura = IMG_LoadTexture(renderer,"Nave.png");
    bala = IMG_LoadTexture(renderer,"bala.png");

    SDL_QueryTexture(textura,NULL,NULL,&rectangulo.w,&rectangulo.h);

    rectangulo.x=0;
    rectangulo.y=100;

    nave_x = rectangulo.x;
    nave_y = rectangulo.y;

//    velocidad = 3;
//    velocidad_bala = 10;

    this->actores = actores;

    perdi = detener;
}

Nave::~Nave()
{
    //dtor
}

void Nave::logica()
{
//    for(list<SDL_Rect*>::iterator i=Balas.begin();
//        i!=Balas.end();
//        i++)
//        (*i)->x+=velocidad_bala;

    for(list<Bala*>::iterator i=balas.begin();
        i!=balas.end();
        i++)
        (*i)->logica();

    const Uint8 *estaPresionada = SDL_GetKeyboardState(NULL);

    velocidad=3;
    if(estaPresionada[SDL_SCANCODE_LSHIFT])
    {
        velocidad=0.5;
    }

    if(estaPresionada[SDL_SCANCODE_LEFT])
    {
        nave_x-=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_RIGHT])
    {
        nave_x+=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_UP])
    {
        nave_y-=velocidad;
    }
    if(estaPresionada[SDL_SCANCODE_DOWN])
    {
        nave_y+=velocidad;
    }

    rectangulo.x = nave_x;
    rectangulo.y = nave_y;

//    if(estaPresionada[SDL_SCANCODE_X])
//    {
//        if(frame%10==0)
//        {
//            disparar();
//        }
//    }

    if(estaPresionada[SDL_SCANCODE_Z])
    {
        if(frame%10==0)
        {
            disparar2();
        }
    }

    for(list<Personaje*>::iterator i=actores->begin();
        i!=actores->end();
        i++)
    {
        if(*i==this)
            continue;
        //con rects
//        for(list<SDL_Rect*>::iterator j=Balas.begin();
//            j!=Balas.end();
//            j++)
//        {
//            SDL_Rect rect1 = (**j);
//            SDL_Rect rect2 = (*i)->rectangulo;
//            if((rect1.x+rect1.w<rect2.x)==false
//                && (rect1.x>rect2.x+rect2.w)==false
//                && (rect1.y+rect1.h<rect2.y)==false
//                && (rect1.y>rect2.y+rect2.h)==false
//                )
//            {
//            cout<<"Entro!!"<<endl;
//                actores->erase(i);
//                Balas.erase(j);
//                return;
//            }
//        }
        //crea balas con Clase Bala
        for(list<Bala*>::iterator j=balas.begin();
            j!=balas.end();
            j++)
        {
            SDL_Rect rect1 = (*j)->rect_bala;
            SDL_Rect rect2 = (*i)->rectangulo;
            if((rect1.x+rect1.w<rect2.x)==false
                && (rect1.x>rect2.x+rect2.w)==false
                && (rect1.y+rect1.h<rect2.y)==false
                && (rect1.y>rect2.y+rect2.h)==false
                )
            {
            cout<<"Entro!!"<<endl;
                actores->erase(i);
                balas.erase(j);
                return;
            }
        }
        //colisiono con nave
        for(list<Bala*>::iterator j=(*i)->balas.begin();
            j!=(*i)->balas.end();
            j++)
        {
            SDL_Rect rect1 = (*j)->rect_bala;
            SDL_Rect rect2 = rectangulo;
            if((rect1.x+rect1.w<rect2.x)==false
                && (rect1.x>rect2.x+rect2.w)==false
                && (rect1.y+rect1.h<rect2.y)==false
                && (rect1.y>rect2.y+rect2.h)==false
                )
            {
            cout<<"Colisiono con nave!!"<<endl;
                (*i)->balas.erase(j);
                perdi("Perdiste!");
//                exit(121);
                return;
            }
        }
    }

//    for(list<Personaje*>::iterator i=actores->begin();
//        i!=actores->end();
//        i++)
//    {
//        if(*i==this)
//            continue;
//        //crea balas con Clase Bala
//        for(list<Bala*>::iterator j=balas.begin();
//            j!=balas.end();
//            j++)
//        {
//            SDL_Rect rect1 = (*j)->rect_bala;
//            SDL_Rect rect2 = (*i)->rectangulo;
//            if((rect1.x+rect1.w<rect2.x)==false
//                && (rect1.x>rect2.x+rect2.w)==false
//                && (rect1.y+rect1.h<rect2.y)==false
//                && (rect1.y>rect2.y+rect2.h)==false
//                )
//            {
//            cout<<"Colisiono con nave!!"<<endl;
//                actores->erase(i);
//                balas.erase(j);
//                return;
//            }
//        }
//    }

    frame++;
}

void Nave::dibujar()
{
//    for(list<SDL_Rect*>::iterator i=Balas.begin();
//            i!=Balas.end();
//            i++)
//    {
//        SDL_RenderCopy(renderer, bala, NULL, *i);
//    }

    for(list<Bala*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
    {
        SDL_RenderCopy(renderer, bala, NULL, &(*i)->rect_bala);
    }
    SDL_RenderCopy(renderer, textura, NULL, &rectangulo);
//    SDL_RenderPresent(renderer);
}

//void Nave::disparar()
//{
//	SDL_Rect *temp = new SDL_Rect;
//	SDL_QueryTexture(bala,NULL,NULL,&temp->w,&temp->h);
//	temp->x = rectangulo.x + rectangulo.w - temp->w;
//	temp->y = rectangulo.y + rectangulo.h*0.5 - temp->h;
//	Balas.push_back(temp);
//}
