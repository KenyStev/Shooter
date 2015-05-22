#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <list>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Bala
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture *bala;
        SDL_Rect rect_bala;

        Bala(SDL_Renderer *render,SDL_Texture *bala, SDL_Rect *rect_nave)
        {
            this->bala=bala;
            SDL_QueryTexture(bala,NULL,NULL,&rect_bala.w,&rect_bala.h);

            rect_bala.x=rect_nave->x;
            rect_bala.y=rect_nave->y;
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
            rect_bala.x++;
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
        SDL_Texture *nave, *bala, *enemigo;
        SDL_Rect rect_nave, rect_enemigo;
        list<SDL_Rect*>balas;

        virtual void logica() = 0;
        virtual void dibujar() = 0;

        Personaje();
        Personaje(SDL_Renderer *renderer);
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
