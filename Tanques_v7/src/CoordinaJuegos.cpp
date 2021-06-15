#include "CoordinaJuegos.h"


#include "ETSIDI.h"

CoordinaJuegos::CoordinaJuegos()
{
    estado = INICIO;
}

void CoordinaJuegos::mouseclick(int boton, int state)
{
    mundial.mouseclick(boton, state);
}

void CoordinaJuegos::mousemotion(int x, int y)
{
    mundial.mousemotion(x, y);
}

void CoordinaJuegos::key(unsigned char key, int x, int y, bool state)
{
        mundial.key(key, x, y, state);  
}


void CoordinaJuegos::dibuja()
{
    if (estado == INICIO)
    {//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
        gluLookAt(0, 7.5, 30, // posicion del ojo
            0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
        ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("ROTMT: REALM OF THE MAD TANK", -8, 8);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
        ETSIDI::printxy("PULSA ESPACIO PARA EMPEZAR", -8, 7);
        ETSIDI::printxy("PULSA LA TECLA -S- PARA SALIR", -8, 6);
        ETSIDI::printxy("Mover: W A S D", -8, 4);
        ETSIDI::printxy("Disparar: Click Izquierdo", -8, 3);
        ETSIDI::printxy("UBISOFT", 2, 1);
    }
    else if (estado == JUEGA)
    {
        mundial.dibuja();
        ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
        ETSIDI::printxy("PULSA LA TECLA -P- PARA PAUSAR EL JUEGO", -10, 16);
    }
    else if (estado == GAMEOVER)
    {
        mundial.dibuja();
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
        ETSIDI::printxy("GAMEOVER", -2, 7);
        ETSIDI::printxy("Pulsa -C- para volver al menu", -5, 6);
    }
   
    else if (estado == GG)
    {
        mundial.dibuja();
        ETSIDI::setTextColor(0, 1, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
        ETSIDI::printxy("GG WP", -2, 10);
        ETSIDI::printxy("Pulsa -C- para volver al menu", -5, 9);
    }
    else if (estado == PAUSA)
    {
        mundial.dibuja();
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("PAUSA", -1, 13);
        ETSIDI::printxy("Pulsa -C- para reanudar", -4, 12);
    }
    
}


void CoordinaJuegos::tecla(int& nivel)
{
    bool teclas[255];
    for (int i = 0; i < 255; i++)
    {
        teclas[i] = mundial.getestadosteclas()[i];
    }

    bool teclasraton[4];
    for (int i = 0; i < 4; i++)
    {
        teclas[i] = mundial.getestadosraton()[i];
    }

    int ratonpos[2];
    ratonpos[0] = mundial.getposicionraton()[0];
    ratonpos[1] = mundial.getposicionraton()[1];

    if (estado == INICIO)
    {
        if (teclas[' '] )
        {
            nivel = 1;
            mundial.setmundo(getnivel(nivel)); // Ahora no se inicializa desde main de Pang.cpp !!

            ETSIDI::playMusica("sonidos/musicota.wav", true);
            estado = JUEGA;
        }
        if (teclas['s']||teclas['S'])
            exit(0);
    }
    else if (estado == JUEGA)
    {
        
        if (teclas['p'] || teclas['P'])
            estado = PAUSA;
    }
    else if ((estado == GAMEOVER)||(estado== GG))
    {
        if (teclas['c'] || teclas['C'])
            estado = INICIO;
    }
    else if (estado == PAUSA)
    {
        if (teclas['c'] || teclas['C'])
            estado = JUEGA;
    }
}



void CoordinaJuegos::refresh()
{
    static int nivel;
    tecla(nivel);

    if ((estado == JUEGA)||(estado==GG))
    {
        mundial.refresh();
        //mundial.raton();
     
        if (mundial.getvidajugador() <= 0)
        {
            estado = GAMEOVER;
        }

        if (mundial.getNumEnemigos() == 0)
        {
            nivel++;
            if (!mundial.setmundo(getnivel(nivel))) // cargarNivel() devuelve 0 si no ha sido capaz de cargar un nuevo nivel
                estado = GG;
           
        }  
    }

}

char* CoordinaJuegos::getnivel(int nivel)
{
    static char str[50];
    if (nivel == 1)
        strcpy(str, "mapas/map_1.txt");
    if (nivel == 2)
        strcpy(str, "mapas/map_2.txt");
    if (nivel == 3)
        strcpy(str, "mapas/map_3.txt");
    if (nivel > 3)
        strcpy(str, "NULL");

    return str;
}
