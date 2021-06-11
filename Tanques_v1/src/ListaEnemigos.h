#pragma once
#define MAX_ENEMIGOS 7
#include "Interaction.h"
#include "Disparo.h"
#include "Tanque.h"
#include "Enemigo.h"
#include "Pared.h"
#include "ListaParedes.h"

class ListaEnemigos
{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool add(Enemigo* e);
	void draw();
	void destruirContenido();
	void refresh(float t);
	void eliminar(int index); // la borra segun su indice
	void eliminar(Enemigo* e); // elimina una esfera segun su direccion de memoria

	Enemigo* operator[](int i);
	void ataque(Tanque& Tanque);
	void colision(Tanque& Tanque);
	void colision();
	int getNumero() { return numero; }
private:
	int numero;
	Enemigo* list[MAX_ENEMIGOS];

	

};


