#pragma once
#include "Tanque.h"
#include "inputstates.h"
#include "camera.h"
#include "ListaParedes.h"
#include "Interaction.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "ListaEnemigos.h"
#include "ListaDisparos.h"
#include "ListaSuelos.h"

class mundo{
	Tanque tanque;
	inputstates estadosentradas;
	camera camara;
	ListaParedes paredes;
	Interaction interaccion;

	ListaSuelos suelos;
	ListaDisparos disparos;
	ListaEnemigos enemigos;
public:
	mundo();
	virtual ~mundo();
	void loadmap(const char* filename);
	void refresh();
	void draw();
	void key(unsigned char key, int x, int y,bool state);
	void tecla();
	void raton();
	void mousemotion(int x, int y);
	void mouseclick(int button,int state);
};