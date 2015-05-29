#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <list>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Bala
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture *bala;
        SDL_Rect rect_bala;
        float velocidad_x = 10,velocidad_y = 0;

        Bala(SDL_Renderer *render,SDL_Texture *bala, SDL_Rect rect)
        {
            renderer=render;
            this->bala=bala;
            rect_bala=rect;
//            SDL_QueryTexture(bala,NULL,NULL,&rect_bala.w,&rect_bala.h);

//            rect_bala.x=rect.x;
//            rect_bala.y=rect.y;
        }

        Bala(SDL_Renderer *render)
        {
            renderer=render;

            bala = IMG_LoadTexture(renderer,"bala.png");
            SDL_QueryTexture(bala,NULL,NULL,&rect_bala.w,&rect_bala.h);

            rect_bala.x=0;
            rect_bala.y=100;
        }

        void logica()
        {
            rect_bala.x+=velocidad_x;
            rect_bala.y+=velocidad_y;
        }

        void dibujar()
        {
            SDL_RenderCopy(renderer, bala, NULL, &rect_bala);
//            SDL_RenderPresent(renderer);
        }
//        virtual~Bala();
};

class Personaje
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture *bala, *textura;
        SDL_Rect rectangulo;
        //NEW
//        list<SDL_Rect*>Balas;
        int frame=0;

        list<Bala*>balas;

        virtual void logica() = 0;
        virtual void dibujar() = 0;
        void disparar();
        void disparar2();

        Personaje();
        Personaje(SDL_Renderer *renderer);
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
