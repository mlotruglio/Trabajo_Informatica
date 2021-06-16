#pragma once
#include"mundo.h"
class CoordinaJuegos{
    public:
        CoordinaJuegos();
        virtual ~CoordinaJuegos() {}
        void key(unsigned char key,int x, int y , bool state);
        void mouseclick(int boton, int state);
        void mousemotion(int x, int y);
        void refresh();
        void dibuja();
    private:
        char* getnivel(int nivel);
        mundo mundial;
        enum Estado { INICIO, JUEGA,GAMEOVER,CONTROLES, GG, PAUSA };
        Estado estado;
};

