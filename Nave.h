#ifndef NAVE_H
#define NAVE_H

#include "Personaje.h"


class Nave : public Personaje
{
    public:
        float nave_x = rect_nave.x;
        float nave_y = rect_nave.y;

        Nave(SDL_Renderer *renderer);
        virtual ~Nave();

        void logica();
        void dibujar();
    protected:
    private:
};

#endif // NAVE_H
