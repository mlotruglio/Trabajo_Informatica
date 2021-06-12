#pragma once
#define MAX_DISPAROS 100
#include "Interaction.h"
#include "Disparo.h"
#include "Tanque.h"
#include "Tanque.h"
#include "Pared.h"
#include "ListaParedes.h"

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
	Disparo* colision(Tanque& Tanque);
	//Disparo* contador(Disparo*d);

	int getNumero() { return numero; }
private:
	int numero;
	Disparo* list[MAX_DISPAROS];
	
};

