
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include<vector>

#include "Nave.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Enemigo3.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background, *pausa;//*nave,*enemigo,*bala;
SDL_Rect rect_background,rect_pausa;//rect_nave,rect_enemigo,rect_bala;

list<Personaje*> actores;

//void pausa();
bool pausado=false, state=true;
int estado_boton, estado_anterior;
int frame=0;

void init(char* message)
	{
	state=false;
	actores.clear();
	actores.push_back(new Enemigo1(renderer));
	actores.push_back(new Enemigo2(renderer));
	actores.push_back(new Enemigo3(renderer));
	actores.push_back(new Nave(renderer,&actores,init));
	frame=0;
	}

void generar()
{
    if(!pausado)
    {
        if(frame%150==0)
        {
            actores.push_back(new Enemigo1(renderer));
        }
        if(frame%180==0)
        {
            actores.push_back(new Enemigo2(renderer));
        }
        if(frame%170==0)
        {
            actores.push_back(new Enemigo3(renderer));
        }
        frame++;
    }
}

int main( int argc, char* args[] )
	{

	//Init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			return 10;
			}
	//Creates a SDL Window
	if((window = SDL_CreateWindow("Image Loading", 100, 100, 640/*WIDTH*/, 480/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL) {
			return 20;
			}
	//SDL Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
	if (renderer == NULL) {
			std::cout << SDL_GetError() << std::endl;
			return 30;
			}

	//Init textures
	int w=0,h=0;
	background = IMG_LoadTexture(renderer,"fondo.png");
	SDL_QueryTexture(background, NULL, NULL, &w, &h);
	rect_background.x = 0;
	rect_background.y = 0;
	rect_background.w = w;
	rect_background.h = h;

	pausa = IMG_LoadTexture(renderer,"pausa.png");
	SDL_QueryTexture(pausa, NULL, NULL, &w, &h);
	rect_pausa.x = 0;
	rect_pausa.y = 0;
	rect_pausa.w = w;
	rect_pausa.h = h;

//    list<Personaje*> actores;
	actores.push_back(new Enemigo1(renderer));
	actores.push_back(new Enemigo2(renderer));
	actores.push_back(new Enemigo3(renderer));
	actores.push_back(new Nave(renderer,&actores,init));

	//hasta aqui el apuntado de funcion

//    float enemigo_y = 0;
//
//    //Main Loop
//    float personaje_x = 100;
//    float personaje_y = 100;
//    list<SDL_Rect*>balas;

	unsigned int frame_anterior = SDL_GetTicks();

	while(true) {
			while(SDL_PollEvent(&Event)) {
					if(Event.type == SDL_QUIT) {
							return 0;
							}
					}

			//Controla el estado de pausa
			const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
			estado_boton = estaPresionada[SDL_SCANCODE_ESCAPE];
			if(estado_boton != estado_anterior) {
					estado_anterior -= 1;
					if(estado_boton==estado_anterior)
						pausado=!pausado;
					}
			estado_anterior = estado_boton;
			//Termina el control del estado del boton

			SDL_RenderCopy(renderer, background, NULL, &rect_background);
//        SDL_RenderCopy(renderer, enemigo, NULL, &rect_enemigo);
//        SDL_RenderCopy(renderer, nave, NULL, &rect_nave);

			for(list<Personaje*>::iterator i=actores.begin();
			    i!=actores.end();
			    i++
			   ) {
					if(!state) break;

					(*i)->dibujar();
					if(!pausado) {
							cout<<"No Esta Pausado!"<<endl;
							(*i)->logica();
							}
					else {
							cout<<"Esta Pausado!"<<endl;
							SDL_RenderCopy(renderer, pausa, NULL, &rect_pausa);
							}
					}
			if(!state) state=true;

//
//        for(list<SDL_Rect*>::iterator i=balas.begin();
//            i!=balas.end();
//            i++)
//        {
//            SDL_RenderCopy(renderer, bala, NULL, *i);
//            (*i)->x+=5;
//        }

//        for(list<SDL_Rect*>::iterator i=balas.begin();
//            i!=balas.end();
//            i++)
//        {
//            SDL_RenderCopy(renderer, bala, NULL, *i);
//            if((*i)->x>=500)
//            {
//                balas.erase(i);
//                break;
//            }
//        }
//
//        if(balas.size()>1)
//        {
//            list<SDL_Rect*>::iterator ultimo=balas.end();
//            ultimo--;
//            if((*ultimo)->x>50)
//            {
//                balas.pop_back();
//            }
//        }

//    cout<<SDL_GetTicks() - frame_anterior;
//    cout<<"+"<<17 - (SDL_GetTicks() - frame_anterior)<<endl;
			if((SDL_GetTicks() - frame_anterior)<17) {
					SDL_Delay(17-(SDL_GetTicks() - frame_anterior));
					}
			frame_anterior = SDL_GetTicks();

			SDL_RenderPresent(renderer);

			generar();
			}

	return 0;
	}
//
//void pausa()
//{
//    pausado=true;
////    while(true)
////    {
//        cout<<"Esta Pausado!"<<endl;
//        const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
//
////    }
//}
