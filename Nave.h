#ifndef NAVE_H
#define NAVE_H

#include "Personaje.h"


class Nave : public Personaje
{
    public:
        float nave_x = rectangulo.x;
        float nave_y = rectangulo.y;
        float velocidad;//, velocidad_bala;
        void (*perdi)( char* msg );

        list<Personaje*> *actores;

        Nave(SDL_Renderer *renderer,list<Personaje*> *actores,void (*detener)( char* args ));
        virtual ~Nave();

        void logica();
        void dibujar();
    protected:
    private:
};

#endif // NAVE_H
