#pragma once
#include "Wall.h"
#include "tank.h"
#include "Enemigo.h"
#include "Enemigo.h"
#include "Disparo.h"

#define MAX_WALLS 100000
class WallList{
public:
	WallList();
	virtual ~WallList();
	bool add(Wall*);
	void drawwalls();
	void colision(tank& Tank);
	void colision(Enemigo& Tank);
	void colision(Disparo& disparo);
	void loadmap();
	int getNumero() {return number;}
	Wall* operator[](int i);
	//friend class ListaDisparos;
private:
	int number;
	Wall* list[MAX_WALLS];
};
