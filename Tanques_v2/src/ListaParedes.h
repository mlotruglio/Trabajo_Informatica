#pragma once
#include "Pared.h"
#include "Tanque.h"
#include "Tanque.h"
#include "Tanque.h"
#include "Disparo.h"

#define MAX_WALLS 100000
class ListaParedes{
public:
	ListaParedes();
	virtual ~ListaParedes();
	bool add(Pared*);
	void draw();
	void colision(Tanque& Tanque);
	void colision(Disparo& disparo);
	int getNumero() {return number;}
	Pared* operator[](int i);
	//friend class ListaDisparos;
private:
	int number;
	Pared* list[MAX_WALLS];
};
