#include "mundo.h"
#include <stdio.h>
#include "freeglut.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "ETSIDI.h"
#include "vector3D.h"
mundo::mundo(){
	camara.getobjective(jugador.getPunteroPosicion());
	loadmap("mapas/map.txt");
	disparosenemigo.destruirContenido();
	ETSIDI::playMusica("sonidos/musicota.wav",true);
}

void mundo::refresh() {
	tecla();
	raton();
	disparosjugador.refresh(0.025f);
	disparosenemigo.refresh(0.025f);
	jugador.refresh(0.025f);
	enemigos.refresh(0.025f);
	//interaccion jugador con paredes disparosenemigo y enemigos
	static bool flag = 0;
	for (int i = 0; i < paredes.getNumero(); i++) {
		Interaction::colision(jugador, *paredes[i]);
	}
	for (int i = 0; i < enemigos.getNumero(); i++) {
		Interaction::colision(jugador, *enemigos[i]);
	}
	for (int i = 0; i < disparosenemigo.getNumero(); i++) {
		if (Interaction::colision(jugador, *disparosenemigo[i]) && !flag) {
			jugador.setVida(jugador.getVida() - disparosenemigo[i]->getDanio());
			ETSIDI::play("sonidos/player_hit.wav");
			disparosenemigo.eliminar(disparosenemigo[i]);
			if (jugador.getVida() <= 0) {
				flag = 1;
				jugador.setVida(0);
				ETSIDI::play("sonidos/muertejugador.wav");
			}
		}
	}
	//interaccion enemigo con paredes disparosjugador y ataque
	for (int i = 0; i < enemigos.getNumero(); i++) {
		//enemigo ataque
		disparosenemigo.add(Interaction::ataque(jugador, *enemigos[i]));
		//enemigo con pared
		for (int j = 0; j < paredes.getNumero(); j++){
			Interaction::colision(*enemigos[i], *paredes[j]);
		}
		//enemigo con disparojugador
		for (int j = 0; j < disparosjugador.getNumero(); j++) {
			if (Interaction::colision(*enemigos[i], *disparosjugador[j])) {
				ETSIDI::play("sonidos/enemy_hit.wav");
				enemigos[i]->setVida(enemigos[i]->getVida() - disparosjugador[j]->getDanio());
				disparosjugador.eliminar(disparosjugador[j]);
				if (enemigos[i]->getVida() <= 0)
					enemigos.eliminar(enemigos[i]);
			}
		}
	}
	//interaccion disparos jugador con pared y delete si no quedan rebotes o tiempo
	for (int i = 0; i < disparosjugador.getNumero() ; i++) {
		for (int j = 0; j < paredes.getNumero(); j++)
			if (Interaction::colision(*disparosjugador[i], *paredes[j])) {
				disparosjugador[i]->actualizaRebote();
			}
		if (disparosjugador[i]->getTime() <= 0|| disparosjugador[i]->getRebote() <= 0)
			disparosjugador.eliminar(disparosjugador[i]);
	}
	//interaccion disparos enemigo con pared y delete si no quedan rebotes o tiempo
	for (int i = 0; i < disparosenemigo.getNumero(); i++) {
		for (int j = 0; j < paredes.getNumero(); j++)
			if (Interaction::colision(*disparosenemigo[i], *paredes[j])) {
				disparosenemigo[i]->actualizaRebote();
			}
		if (disparosenemigo[i]->getTime() <= 0 || disparosenemigo[i]->getRebote() <= 0)
			disparosenemigo.eliminar(disparosenemigo[i]);
	}
}
void mundo::dibuja(){
	camara.drawcamera();
	suelos.dibuja(jugador.getPosicion(),30);
	jugador.dibuja();
	paredes.dibuja(jugador.getPosicion(),30);
	enemigos.dibuja(jugador.getPosicion(),30);
	disparosjugador.dibuja(jugador.getPosicion(),30);
	disparosenemigo.dibuja(jugador.getPosicion(), 30);
}
void mundo::key(unsigned char key, int x ,int y,bool state) {
	estadosentradas.setkeystates(key, state);
}
void mundo::mouseclick(int button, int state) {
	estadosentradas.setmousestates(button, !state);
}
void mundo::mousemotion(int x, int y) {
	estadosentradas.setmousepos(x, y);
}

void mundo::raton() {
		jugador.setOrientaciontorreta(camara.getorientation() + atan2(400.0 - estadosentradas.getmousepos()[0], 300.0 - estadosentradas.getmousepos()[1]) * 180.0 / 3.1415926535) ;
		
		if (estadosentradas.getmousestates()[0]) {
			if (jugador.getRecarga() <= 0) {
				ETSIDI::play("sonidos/disparo.wav");
				Disparo* d = new Disparo(jugador.getPosicion(),15, jugador.getOrientaciontorreta(),0.2,10,2,7);
				d->setPosicion(d->getPosicion().x, 1.4, d->getPosicion().z);
				d->setColor(0, 150, 150);
				if (disparosjugador.add(d));
				else delete d;
				jugador.resetRecarga();
			}
		}
}

void mundo::tecla()
{
	static bool lastkey[255];
	if (estadosentradas.getkeystates()['w']|| estadosentradas.getkeystates()['W'])
		jugador.setVelocidad(7.5f);
	if (estadosentradas.getkeystates()['s'] || estadosentradas.getkeystates()['S'])
		jugador.setVelocidad(-7.5f);
	if (estadosentradas.getkeystates()['a'] || estadosentradas.getkeystates()['A'])
		jugador.setOrientacion(jugador.getOrientacion()+3.0f);
	if (estadosentradas.getkeystates()['d'] || estadosentradas.getkeystates()['D'])
		jugador.setOrientacion(jugador.getOrientacion() -3.0f);
	if ((estadosentradas.getkeystates()['z'] && !lastkey['z']) || (estadosentradas.getkeystates()['Z'] && !lastkey['Z'])) camara.setorientationabs(0);
	if ((estadosentradas.getkeystates()['o'] && !lastkey['o']) || (estadosentradas.getkeystates()['O'] && !lastkey['O'])) { if (camara.getdistance() >= 10)camara.setdistancerel(-5); if(camara.getdistance() <10)camara.setdistanceabs(5); }
	if ((estadosentradas.getkeystates()['p'] && !lastkey['p']) || (estadosentradas.getkeystates()['P'] && !lastkey['P'])) { if (camara.getdistance() <= 50)camara.setdistancerel(5); if(camara.getdistance() >50) camara.setdistanceabs(50); }
	if (estadosentradas.getkeystates()['q'] || estadosentradas.getkeystates()['Q']) { camara.setorientationrel(+5); }
	if (estadosentradas.getkeystates()['e'] || estadosentradas.getkeystates()['E']) { camara.setorientationrel(-5); }
	for (int i = 0; i < 255; i++) lastkey[i] = estadosentradas.getkeystates()[i];

}

mundo::~mundo()
{
	disparosjugador.destruirContenido();
	disparosenemigo.destruirContenido();
	enemigos.destruirContenido();
	paredes.destruirContenido();
	suelos.destruirContenido();
}

void mundo::loadmap(const char* filename) {
	FILE* file = fopen(filename, "r");
	char key;
	int i = 0;
	int j = 0;
	int escala = 2;
	if (file == NULL) {
		printf("error abriendo el mapa");
	}
	else {
		while (!feof(file)) {
			fflush(file);
			fscanf(file, "%c", &key);
			if (key == '^') {
				jugador.setPosicion((float)-j * escala, 0.1, (float)i * escala);
				jugador.setColor(0,150, 150);
				jugador.setTiempoRecarga(0.25);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == 'x') {
				Tanque* aux = new Tanque();
				aux->setPosicion((float)-j * escala, 0.1, (float)i * escala);
				aux->setColor(150, 0, 0);
				aux->setTiempoRecarga(0.5);
				enemigos.add(aux);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == 'O') {
				Pared* aux = new Pared((float)-j * escala, 0, (float)i * escala,escala);
				paredes.add(aux);
			}
			if (key == '.') {
				Suelo* aux = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(aux);
			}
			i += 1;
			if (key == '\n' || key == EOF) {
				j += 1; i = 0;
			}
		}
	}
}