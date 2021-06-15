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
	//interaccion enemigo con enemigo paredes disparosjugador jugador y ataque
	for (int i = 0; i < enemigos.getNumero(); i++) {
		//interaccion enemigo con jugador
		Interaction::colision(jugador, *enemigos[i]);
		//enemigo ataque
		disparosenemigo.add(Interaction::ataque(jugador, *enemigos[i]));
		//enemigo con enemigo
		for (int j = i + 1; j < enemigos.getNumero(); j++) {
			Interaction::colision(*enemigos[i], *enemigos[j]);
		}
		//enemigo con pared
		for (int j = 0; j < paredes.getNumero(); j++) {
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
	//interaccion disparosjugador con pared y delete si no quedan rebotes o tiempo
	for (int i = 0; i < disparosjugador.getNumero(); i++) {
		for (int j = 0; j < paredes.getNumero(); j++)
			if (Interaction::colision(*disparosjugador[i], *paredes[j])) {
				disparosjugador[i]->actualizaRebote();
			}
		if (disparosjugador[i]->getTime() <= 0 || disparosjugador[i]->getRebote() <= 0)
			disparosjugador.eliminar(disparosjugador[i]);
	}
	//interaccion disparosenemigo con pared jugador y delete si no quedan rebotes o tiempo
	for (int i = 0; i < disparosenemigo.getNumero(); i++) {
		for (int j = 0; j < paredes.getNumero(); j++) {
			if (Interaction::colision(*disparosenemigo[i], *paredes[j])) {
				disparosenemigo[i]->actualizaRebote();
			}
		}
		if (Interaction::colision(jugador, *disparosenemigo[i]) && jugador.getVida() > 0) {
			jugador.setVida(jugador.getVida() - disparosenemigo[i]->getDanio());
			ETSIDI::play("sonidos/player_hit.wav");
			disparosenemigo.eliminar(disparosenemigo[i]);
			if (jugador.getVida() <= 0) {
				jugador.setVida(0);
				ETSIDI::play("sonidos/muertejugador.wav");
			}
		}
		if (disparosenemigo[i]->getTime() <= 0 || disparosenemigo[i]->getRebote() <= 0)
			disparosenemigo.eliminar(disparosenemigo[i]);
	}
	//interaccion paredes con jugador
	for (int i = 0; i < paredes.getNumero(); i++) {
		Interaction::colision(jugador, *paredes[i]);
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
				Disparo* d = new Disparo(jugador.getPosicion(),15, jugador.getOrientaciontorreta(),0.2,10,2,jugador.getDanio());
				d->setPosicion(d->getPosicion().x, 1.4, d->getPosicion().z);
				d->setColor(0, 150, 150);
				d->setVelocidad(1);
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
		jugador.setVelocidad(1);
	if (estadosentradas.getkeystates()['s'] || estadosentradas.getkeystates()['S'])
		jugador.setVelocidad(-1);
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
				jugador.setDanio(8);
				jugador.setVelocidadMax(10);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == '1') {
				vector3D v(-j * escala, 0.1, i * escala);
				Tanque* aux = new Tanque(v, 7, 0, 1.2, 25, 0.5,2);
				aux->setColor(50, 150, 0);
				enemigos.add(aux);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == '2') {
				vector3D v(-j * escala, 0.1, i * escala);
				Tanque* aux = new Tanque(v, 4, 0, 1.5, 50, 0.5,5);
				aux->setColor(150, 150, 0);
				enemigos.add(aux);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == '3') {
				vector3D v(-j * escala, 0.1, i * escala);
				Tanque* aux = new Tanque(v, 3, 0, 2.0, 75, 0.5,10);
				aux->setColor(150, 0, 0);
				enemigos.add(aux);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == '4') {
				vector3D v(-j * escala, 0.1, i * escala);
				Tanque* aux = new Tanque(v,2,0,3.0,100,0.5,20);
				aux->setColor(50, 50, 50);
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