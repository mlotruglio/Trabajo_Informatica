#pragma once
#include "Tanque.h"
#include "inputstates.h"
#include "camera.h"
#include "Suelo.h"
#include "Interaction.h"
#include "Disparo.h"
#include "Tanque.h"
#include "Lista.h"

class mundo{
	Tanque jugador;
	inputstates estadosentradas;
	camera camara;
	Interaction interaccion;
	Lista<Pared> paredes;
	Lista<Suelo> suelos;
	Lista<Disparo> disparosjugador;
	Lista<Disparo> disparosenemigo;
	Lista<Tanque> enemigos;
public:
	mundo();
	virtual ~mundo();
	void loadmap(const char* filename);
	void refresh();
	void dibuja();
	void key(unsigned char key, int x, int y,bool state);
	void tecla();
	void raton();
	void mousemotion(int x, int y);
	void mouseclick(int button,int state);
};