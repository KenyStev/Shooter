#ifndef ENEMIGO3_H
#define ENEMIGO3_H

#include "Personaje.h"
#include "math.h"

class Enemigo3 : public Personaje
{
    public:
        int xTemp=5;
        int yTemp=10;

        Enemigo3(SDL_Renderer *renderer);
        virtual ~Enemigo3();

        void logica();
        void dibujar();
    protected:
    private:
};

#endif // ENEMIGO3_H
