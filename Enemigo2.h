#ifndef ENEMIGO2_H
#define ENEMIGO2_H

#include "Personaje.h"
#include "math.h"

class Enemigo2 : public Personaje
{
    public:
        int xStar = 5;
        int yStar = 5;
        int velocidad_bala = 2;
        Enemigo2(SDL_Renderer *renderer);
        virtual ~Enemigo2();

        void logica();
        void dibujar();

        void disparar2();
    protected:
    private:
};

#endif // ENEMIGO2_H
