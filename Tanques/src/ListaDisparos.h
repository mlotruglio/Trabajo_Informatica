#pragma once
#define MAX_DISPAROS 3
#include "Interaction.h"
#include "Disparo.h"
#include "tank.h"
#include "Enemigo.h"
#include "Wall.h"
#include "WallList.h"

class ListaDisparos
{
	
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	bool add(Disparo*);
	void draw();
	void destruirContenido();
	void refresh(float t);
	void eliminar(int index); // la borra segun su indice
	void eliminar(Disparo* e); // elimina una esfera segun su direccion de memoria

	Disparo* operator[](int i);
	Disparo* colision(tank& Tank);
	Disparo* colision(Enemigo& Tank);
	//Disparo* contador(Disparo*d);

	int getNumero() { return numero; }
private:
	int numero;
	Disparo* list[MAX_DISPAROS];
	
};

