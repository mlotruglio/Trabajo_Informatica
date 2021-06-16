#pragma once
#include "Tanque.h"
#include "inputstates.h"
#include "camera.h"
#include "Suelo.h"
#include "Interaction.h"
#include "Disparo.h"
#include "Tanque.h"
#include "Lista.h"
#include "vector3D.h"
class mundo{
	Tanque jugador;
	inputstates estadosentradas;
	camera camara;
	Lista<Pared> paredes;
	Lista<Suelo> suelos;
	Lista<Disparo> disparosjugador;
	Lista<Disparo> disparosenemigo;
	Lista<Tanque> enemigos;
public:
	mundo();
	virtual ~mundo();

	bool setmundo(const char *);
	void borrarmundo();
	bool loadmap(const char* filename);
	void refresh();
	void dibuja();
	void key(unsigned char key, int x, int y,bool state);
	void tecla();
	void raton();
	void mousemotion(int x, int y);
	void mouseclick(int button,int state);
	float getdistanciacamara() { return camara.getdistance(); }
	float getOrientacionCamara() { return camara.getorientation(); }
	vector3D getPosicionJugador() { return jugador.getPosicion(); }
	int getNumEnemigos() { return enemigos.getNumero(); }
	float getvidajugador() { return jugador.getVida(); }
	bool* getestadosteclas() { return estadosentradas.getkeystates(); }
	int* getposicionraton() { return estadosentradas.getmousepos(); }
	bool* getestadosraton() { return estadosentradas.getmousestates(); }
};