#pragma once
#define MAX_ENEMIGOS 7
#include "Interaction.h"
#include "Disparo.h"
#include "Tanque.h"
#include "Tanque.h"
#include "Pared.h"
#include "ListaParedes.h"

class ListaEnemigos
{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool add(Tanque* e);
	void draw();
	void destruirContenido();
	void refresh(float t);
	void eliminar(int index); // la borra segun su indice
	void eliminar(Tanque* e); // elimina una esfera segun su direccion de memoria

	Tanque* operator[](int i);
	void colision(Tanque& Tanque);
	void colision();
	int getNumero() { return numero; }
private:
	int numero;
	Tanque* list[MAX_ENEMIGOS];

	

};


