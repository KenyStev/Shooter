#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include "Personaje.h"
#include "math.h"

class Enemigo1 : public Personaje
{
    public:
        float xStar = 5;
        float yStar = 200;
        float velocidad_bala = 2;
        Enemigo1(SDL_Renderer *renderer);
        virtual ~Enemigo1();

        void logica();
        void dibujar();

        void disparar2();
    protected:
    private:
};

#endif // ENEMIGO1_H
