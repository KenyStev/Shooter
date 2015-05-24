#ifndef ENEMIGO3_H
#define ENEMIGO3_H

#include "Personaje.h"
#include "math.h"

class Enemigo3 : public Personaje
{
    public:
        int xTemp=1;
        int yTemp=5;
        int velocidad_bala = 2;

        Enemigo3(SDL_Renderer *renderer);
        virtual ~Enemigo3();

        void logica();
        void dibujar();

        void disparar2();
    protected:
    private:
};

#endif // ENEMIGO3_H
