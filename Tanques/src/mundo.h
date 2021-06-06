#pragma once
#include "tank.h"
#include "inputstates.h"
#include "camera.h"
#include "WallList.h"
#include "Interaction.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
#include "ListaDisparos.h"

class mundo{
	tank tanque;
	inputstates estadosentradas;
	camera camara;
	WallList paredes;
	Interaction interaccion;
	//Disparo disparo;
	//Enemigo enemigo;
	ListaDisparos disparos;
	ListaEnemigos enemigos;
public:
	mundo();
	virtual ~mundo();
	void refresh();
	void draw();
	void key(unsigned char key, int x, int y,bool state);
	void tecla();
	void raton();
	void mousemotion(int x, int y);
	void mouseclick(int button,int state);
};