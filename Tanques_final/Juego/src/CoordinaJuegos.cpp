#include "CoordinaJuegos.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>
#define pi 3.1415926535897932384626433
CoordinaJuegos::CoordinaJuegos(){
    estado = INICIO;
    ETSIDI::playMusica("sonidos/Musicainicio.wav", true);
}
void CoordinaJuegos::mouseclick(int boton, int state){
    mundial.mouseclick(boton, state);
}
void CoordinaJuegos::mousemotion(int x, int y){
    mundial.mousemotion(x, y);
}
void CoordinaJuegos::key(unsigned char key, int x, int y, bool state)
{
        mundial.key(key, x, y, state);  
}
void CoordinaJuegos::dibuja(){
    if (estado == INICIO){
        gluLookAt(0, 7.5, 30,0.0, 7.5, 0.0,0.0, 1.0, 0.0);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton play.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-3.8, 11, 0);
        glTexCoord2d(1, 1); glVertex3f(3.8, 11, 0);
        glTexCoord2d(1, 0);  glVertex3f(3.8, 13, 0);
        glTexCoord2d(0, 0);  glVertex3f(-3.8, 13, 0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton controles.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-3.8, 7, 0);
        glTexCoord2d(1, 1); glVertex3f(3.8, 7, 0);
        glTexCoord2d(1, 0);  glVertex3f(3.8, 9, 0);
        glTexCoord2d(0, 0);  glVertex3f(-3.8, 9, 0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton salir.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-3.8, 3, 0);
        glTexCoord2d(1, 1); glVertex3f(3.8, 3, 0);
        glTexCoord2d(1, 0);  glVertex3f(3.8, 5, 0);
        glTexCoord2d(0, 0);  glVertex3f(-3.8,5, 0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo de inicio.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-15, -5, 0);
        glTexCoord2d(1, 1); glVertex3f(15, -5, 0);
        glTexCoord2d(1, 0);  glVertex3f(15, 20, 0);
        glTexCoord2d(0, 0);  glVertex3f(-15, 20, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        ETSIDI::setTextColor(1, 0.7, 0);
        ETSIDI::setFont("fuentes/Gameplay.ttf", 37);
        ETSIDI::printxy("REALM OF THE MAD TANK", -13.5, 15);
    }
    else if (estado == CONTROLES) {
        gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton salir.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-13, -3, 0);
        glTexCoord2d(1, 1); glVertex3f(-5, -3, 0);
        glTexCoord2d(1, 0);  glVertex3f(-5, -1, 0);
        glTexCoord2d(0, 0);  glVertex3f(-13, -1, 0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo de inicio.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-15, -5, 0);
        glTexCoord2d(1, 1); glVertex3f(15, -5, 0);
        glTexCoord2d(1, 0);  glVertex3f(15, 20, 0);
        glTexCoord2d(0, 0);  glVertex3f(-15, 20, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("Mover: W A S D", -5, 10);
        ETSIDI::printxy("Girar camara: Q E", -5, 9);
        ETSIDI::printxy("Acercar/Alejar camara: I O", -5, 8);
        ETSIDI::printxy("Resetear orientacion camara: Z", -5,7 );
        ETSIDI::printxy("Disparar: Click Izquierdo", -5, 6);
        ETSIDI::printxy("Pausar el juego: P", -5, 5);
    }
    else if (estado == JUEGA){
        mundial.dibuja();
        vector3D v = mundial.getPosicionJugador();
        vector3D p;
        p.x = -mundial.getdistanciacamara() * cos(mundial.getOrientacionCamara()*pi/180);
        p.z = mundial.getdistanciacamara() * sin(mundial.getOrientacionCamara()*pi/180);
        p.y = mundial.getdistanciacamara() * sin(70*pi/180);
        glPushMatrix();
        glTranslatef(v.x, v.y, v.z);
        glTranslatef(p.x * 0.2, p.y * 0.2, p.z * 0.2);
        glRotatef(mundial.getOrientacionCamara()-90, 0, 1, 0);
        glRotatef(-70, 1, 0, 0);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
        ETSIDI::printxy("Pulsa -P- para pausar el juego", 3.0* mundial.getdistanciacamara()/30.0, 11.0* mundial.getdistanciacamara()/30.0);
        glPopMatrix();
    }
    else if (estado == GAMEOVER){
        mundial.dibuja();
        vector3D v = mundial.getPosicionJugador();
        vector3D p;
        p.x = -mundial.getdistanciacamara() * cos(mundial.getOrientacionCamara() * pi / 180);
        p.z = mundial.getdistanciacamara() * sin(mundial.getOrientacionCamara() * pi / 180);
        p.y = mundial.getdistanciacamara() * sin(70 * pi / 180);
        glPushMatrix();
        glTranslatef(v.x, v.y, v.z);
        glTranslatef(p.x * 0.2, p.y * 0.2, p.z * 0.2);
        glRotatef(mundial.getOrientacionCamara() - 90, 0, 1, 0);
        glRotatef(-70, 1, 0, 0);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton menu.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(-10 * mundial.getdistanciacamara() / 30.0, -4 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(1, 1); glVertex3f(-5 * mundial.getdistanciacamara() / 30.0, -4 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(1, 0);  glVertex3f(-5 * mundial.getdistanciacamara() / 30.0, -2 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(0, 0);  glVertex3f(-10 * mundial.getdistanciacamara() / 30.0, -2 * mundial.getdistanciacamara() / 30.0, 0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton reintentar.png").id);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);  glVertex3f(5 * mundial.getdistanciacamara() / 30.0, -4 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(1, 1); glVertex3f(10 * mundial.getdistanciacamara() / 30.0, -4 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(1, 0);  glVertex3f(10 * mundial.getdistanciacamara() / 30.0, -2 * mundial.getdistanciacamara() / 30.0, 0);
        glTexCoord2d(0, 0);  glVertex3f(5 * mundial.getdistanciacamara() / 30.0, -2 * mundial.getdistanciacamara() / 30.0, 0);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        ETSIDI::setTextColor(0.5, 0, 0);
        ETSIDI::setFont("fuentes/Gameplay.ttf", 70);
        ETSIDI::printxy("GAMEOVER", -8 * mundial.getdistanciacamara() / 30.0,5 * mundial.getdistanciacamara() / 30.0);
        glPopMatrix();
    }
    else if (estado == GG){
    gluLookAt(0, 7.5, 30, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boton menu.png").id);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 1);  glVertex3f(-13, -3, 0);
    glTexCoord2d(1, 1); glVertex3f(-5, -3, 0);
    glTexCoord2d(1, 0);  glVertex3f(-5, -1, 0);
    glTexCoord2d(0, 0);  glVertex3f(-13, -1, 0);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
        ETSIDI::setTextColor(1, 0.7, 0);
        ETSIDI::setFont("fuentes/Gameplay.ttf", 50);
        ETSIDI::printxy("HAS GANADO!", -9.5, 8);

    }
    else if (estado == PAUSA){
        mundial.dibuja();
        vector3D v = mundial.getPosicionJugador();
        vector3D p;
        p.x = -mundial.getdistanciacamara() * cos(mundial.getOrientacionCamara() * pi / 180);
        p.z = mundial.getdistanciacamara() * sin(mundial.getOrientacionCamara() * pi / 180);
        p.y = mundial.getdistanciacamara() * sin(70 * pi / 180);
        glPushMatrix();
        glTranslatef(v.x, v.y, v.z);
        glTranslatef(p.x * 0.2, p.y * 0.2, p.z * 0.2);
        glRotatef(mundial.getOrientacionCamara() - 90, 0, 1, 0);
        glRotatef(-70, 1, 0, 0);
        ETSIDI::setTextColor(0, 0, 0);
        ETSIDI::setFont("fuentes/Gameplay.ttf", 50);
        ETSIDI::printxy("PAUSA", -3 * mundial.getdistanciacamara() / 30.0, 8 * mundial.getdistanciacamara() / 30.0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
        ETSIDI::printxy("Pulsa -C- para reanudar", -4 * mundial.getdistanciacamara() / 30.0, 3 * mundial.getdistanciacamara() / 30.0);
        glPopMatrix();

    }
}
void CoordinaJuegos::refresh()
{
    static int nivel;
    bool teclas[255];
    for (int i = 0; i < 255; i++)
        teclas[i] = mundial.getestadosteclas()[i];
    bool teclasraton[4];
    for (int i = 0; i < 4; i++)
        teclasraton[i] = mundial.getestadosraton()[i];
    int ratonpos[2];
        ratonpos[0] = mundial.getposicionraton()[0];
        ratonpos[1] = mundial.getposicionraton()[1];
    if (estado == INICIO){
        if (ratonpos[0]<500&&ratonpos[0]>300&& ratonpos[1] < 200 && ratonpos[1]>150&&teclasraton[0]) {
            nivel = 1;
            mundial.setmundo(getnivel(nivel));
            ETSIDI::playMusica("sonidos/musicota.wav", true);
            estado = JUEGA;
        }
        if (ratonpos[0] < 500 && ratonpos[0]>300 && ratonpos[1] < 420 && ratonpos[1]>370 && teclasraton[0])
            exit(0);
        if (ratonpos[0] < 500 && ratonpos[0]>300 && ratonpos[1] < 310 && ratonpos[1]>260 && teclasraton[0]) {
            estado = CONTROLES;
        }
    }
    if (estado == CONTROLES) {
        if (ratonpos[0] < 260 && ratonpos[0]>45 && ratonpos[1] < 580 && ratonpos[1]>535 && teclasraton[0])
            estado = INICIO;
    }
    else if (estado == JUEGA){
        mundial.refresh();
        if (mundial.getvidajugador() <= 0) {
            estado = GAMEOVER;
        }
        if (mundial.getNumEnemigos() == 0) {
            nivel++;
            if (!mundial.setmundo(getnivel(nivel))) {
                mundial.borrarmundo();
                estado = GG;
                ETSIDI::playMusica("sonidos/Musicafinal.wav", true);
            }
            else
            ETSIDI::playMusica("sonidos/musicota.wav", true);
        }
        if (teclas['p'] || teclas['P'])
            estado = PAUSA;
    }
    else if (estado == GG){
        if (ratonpos[0] < 260 && ratonpos[0]>45 && ratonpos[1] < 580 && ratonpos[1]>535 && teclasraton[0]) {
            ETSIDI::playMusica("sonidos/Musicainicio.wav", true);
            estado = INICIO;
        }
           
    }
    else if (estado == GAMEOVER) {
        if (ratonpos[0] < 216 && ratonpos[0]>35 && ratonpos[1] < 580 && ratonpos[1]>500 && teclasraton[0]) {
            ETSIDI::playMusica("sonidos/Musicainicio.wav", true);
            estado = INICIO;
        }
          
        if (ratonpos[0] < 760 && ratonpos[0]>580 && ratonpos[1] < 580 && ratonpos[1]>500 && teclasraton[0]) {
            mundial.setmundo(getnivel(nivel));
            ETSIDI::playMusica("sonidos/musicota.wav", true);
            estado = JUEGA;
        }
    }
    else if (estado == PAUSA){
        if (teclas['c'] || teclas['C'])
            estado = JUEGA;
    }

}
char* CoordinaJuegos::getnivel(int nivel)
{
    static char str[50];
    if (nivel == 1)strcpy(str, "mapas/map_1.txt");
    if (nivel == 2)strcpy(str, "mapas/map_2.txt");
    if (nivel == 3)strcpy(str, "mapas/map_3.txt");
    if (nivel > 3)strcpy(str, "NULL");
    return str;
}
