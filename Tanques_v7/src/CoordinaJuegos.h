#pragma once
#include"mundo.h"
class CoordinaJuegos
{


   
    public:
        CoordinaJuegos();
        virtual ~CoordinaJuegos() {}
        void key(unsigned char key,int x, int y , bool state);
        void mouseclick(int boton, int state);
        void mousemotion(int x, int y);
        void tecla(int& nivel);
        void refresh();
        void dibuja();
        char* getnivel(int nivel);
        
    protected:
        mundo mundial;
        enum Estado { INICIO, JUEGA,GAMEOVER, GG, PAUSA };
        Estado estado;
   



};

