#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include "Personaje.h"
#include "math.h"

class Enemigo1 : public Personaje
{
    public:
        int xStar = 5;
        int yStar = 200;
        Enemigo1(SDL_Renderer *renderer);
        virtual ~Enemigo1();

        void logica();
        void dibujar();
    protected:
    private:
};

#endif // ENEMIGO1_H
