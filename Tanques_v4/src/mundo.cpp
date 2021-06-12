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
	camara.getobjective(jugador.getposition());
	loadmap("mapas/map.txt");
	ETSIDI::playMusica("sonidos/musicota.wav",true);
}

void mundo::refresh() {
	tecla();
	raton();
	disparos.refresh(0.025f);
	disparosenemigo.refresh(0.025f);
	jugador.refresh(0.025f);
	paredes.colision(jugador);
	enemigos.refresh(0.025f);
	enemigos.colision(jugador);
	enemigos.colision();

	for (int i = 0; i < enemigos.getNumero(); i++) {
		disparosenemigo.add(Interaction::ataque(jugador, *enemigos[i]));
	}

	for (int i = 0; i < disparos.getNumero() ; i++) 
	{
		for (int j = 0; j < paredes.getNumero(); j++) {
			if (Interaction::colision(*disparos[i], *paredes[j])) {
				if(disparos[i]->setRebote())
					disparos.eliminar(disparos[i]);
			}
			
		}
		for (int a = 0; a < enemigos.getNumero(); a++)
		{
			if (Interaction::colision(*enemigos[a], *disparos[i])) {
				ETSIDI::play("sonidos/enemy_hit.wav");
				enemigos[a]->setVida(enemigos[a]->getVida() - disparos[i]->getDanio());
				disparos.eliminar(disparos[i]);
				if (enemigos[a]->getVida()<=0)
					enemigos.eliminar(enemigos[a]);
			}

		}
		
		if (disparos[i]->getTime() <= 0)
			disparos.eliminar(disparos[i]);
	}
	for (int i = 0; i < disparosenemigo.getNumero(); i++)
	{
		for (int j = 0; j < paredes.getNumero(); j++) {
			if (Interaction::colision(*disparosenemigo[i], *paredes[j])) {
				if (disparosenemigo[i]->setRebote())
					disparosenemigo.eliminar(disparosenemigo[i]);
			}

		}
		static bool flag = 0;
		if (Interaction::colision(jugador, *disparosenemigo[i])&&!flag) {
			jugador.setVida(jugador.getVida() - disparosenemigo[i]->getDanio());
			ETSIDI::play("sonidos/player_hit.wav");
				disparosenemigo.eliminar(disparosenemigo[i]);
				if (jugador.getVida() <= 0) {
					flag = 1;
					jugador.setVida(0);
					ETSIDI::play("sonidos/muertejugador.wav");
				}
		}

		if (disparosenemigo[i]->getTime() <= 0)
			disparosenemigo.eliminar(disparosenemigo[i]);
	}

	for (int p = 0; p < paredes.getNumero(); p++)
	{
		for (int a = 0; a < enemigos.getNumero(); a++)
		{
			Interaction::colision(*enemigos[a], *paredes[p]);
		}

	}
}
void mundo::draw(){
	camara.drawcamera();
	suelos.drawsuelos();
	jugador.draw();
	paredes.draw();
	enemigos.draw();
	disparos.draw();
	disparosenemigo.draw();
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
		jugador.setturretorientation(camara.getorientation() + atan2(400.0 - estadosentradas.getmousepos()[0], 300.0 - estadosentradas.getmousepos()[1]) * 180.0 / 3.1415926535) ;
		
		
		if (estadosentradas.getmousestates()[0]) {
			if (jugador.getRecarga() <= 0) {
				ETSIDI::play("sonidos/disparo.wav");
				Disparo* d = new Disparo();
				d->setPos(jugador.getposition());
				d->setOri(jugador.getturretorientation());
				d->setSpeed(15.0f);
				d->setDanio(7.0);
				d->setColor(0, 150, 150);
				if (disparos.add(d));
				else delete d;
				//estadosentradas.setmousestates(2,0);
				jugador.setRecarga(0.25);
			}
		
		}
		//for (int i = 0; i < 4; i++) lastclik[i] = estadosentradas.getmousestates()[i];
}

void mundo::tecla()
{
	static bool lastkey[255];
	if (estadosentradas.getkeystates()['w']|| estadosentradas.getkeystates()['W'])
		jugador.setspeed(7.5f);
	if (estadosentradas.getkeystates()['s'] || estadosentradas.getkeystates()['S'])
		jugador.setspeed(-7.5f);
	if (estadosentradas.getkeystates()['a'] || estadosentradas.getkeystates()['A'])
		jugador.setbodyorientationrel(3.0f);
	if (estadosentradas.getkeystates()['d'] || estadosentradas.getkeystates()['D'])
		jugador.setbodyorientationrel(-3.0f);
	if ((estadosentradas.getkeystates()['z'] && !lastkey['z']) || (estadosentradas.getkeystates()['Z'] && !lastkey['Z'])) camara.setorientationabs(0);
	if ((estadosentradas.getkeystates()['o'] && !lastkey['o']) || (estadosentradas.getkeystates()['O'] && !lastkey['O'])) { if (camara.getdistance() >= 10)camara.setdistancerel(-5); if(camara.getdistance() <10)camara.setdistanceabs(5); }
	if ((estadosentradas.getkeystates()['p'] && !lastkey['p']) || (estadosentradas.getkeystates()['P'] && !lastkey['P'])) { if (camara.getdistance() <= 50)camara.setdistancerel(5); if(camara.getdistance() >50) camara.setdistanceabs(50); }
	if (estadosentradas.getkeystates()['q'] || estadosentradas.getkeystates()['Q']) { camara.setorientationrel(+5); }
	if (estadosentradas.getkeystates()['e'] || estadosentradas.getkeystates()['E']) { camara.setorientationrel(-5); }
	if ((estadosentradas.getkeystates()['f'] && !lastkey['f']) || (estadosentradas.getkeystates()['F'] && !lastkey['F'])) {
		int num = suelos.getNumero();
		for (int i = 0; i < num; i++) {
			std::cout << num << " " << (*suelos[i]).getposition() << std::endl;
		}
	}
	if ((estadosentradas.getkeystates()['g'] && !lastkey['g']) || (estadosentradas.getkeystates()['G'] && !lastkey['G'])) {
		int num = paredes.getNumero();
		for (int i = 0; i < num; i++) {
			std::cout << num << " " << (*paredes[i]).getposition() << std::endl;
		}
	}
	for (int i = 0; i < 255; i++) lastkey[i] = estadosentradas.getkeystates()[i];

}

mundo::~mundo()
{
	disparos.destruirContenido();
	disparosenemigo.destruirContenido();
	enemigos.destruirContenido();
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
				jugador.setposition((float)-j * escala, 0.1, (float)i * escala);
				jugador.setColor(0,150, 150);
				Suelo* a = new Suelo((float)-j * escala, 0, (float)i * escala, escala);
				suelos.add(a);
			}
			if (key == 'x') {
				Tanque* aux = new Tanque();
				aux->setposition((float)-j * escala, 0.1, (float)i * escala);
				aux->setColor(150, 0, 0);
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