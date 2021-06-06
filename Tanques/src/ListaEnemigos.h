#pragma once
#include "vector3D.h"
#include "stats.h"
class ListaEnemigos {
private:
	
public:
	tank();
	vector3D getfireposition();
	float getfireorientation();
	void setposition(float, float, float);
	void setorientation(float&);
	void refresh(bool key[], int mousepos[],bool mousekey[],float t);
	void drawtank();
	vector3D& getposition();
	friend class Interaction;
	ListaEnemigos();
	void agregarEnemigos();
	void dibuja();
	void mueve(float t);
	void rebote();
	void rebote(Pared p);
	void destruirContenido();
	void eliminar(Enemigo* e);
};