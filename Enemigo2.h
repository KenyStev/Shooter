#ifndef ENEMIGO2_H
#define ENEMIGO2_H

#include "Personaje.h"
#include "math.h"

class Enemigo2 : public Personaje
{
    public:
        int xStar = 5;
        int yStar = 5;
        Enemigo2(SDL_Renderer *renderer);
        virtual ~Enemigo2();

        void logica();
        void dibujar();
    protected:
    private:
};

#endif // ENEMIGO2_H
