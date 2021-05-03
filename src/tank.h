#pragma once
#include "turret.h"
#include "structs.h"
class tank{
	char* getmodel(int i);
	void mousemove(int vector[]);
	void keyaction(bool key[]);
	vector3D position; //posicion del tanque (x es hacia delante, y es arriba , z es la derecha)
	vector3D speed;
	float orientation; // angulo en el plano xz respecto del eje Ox,
	float *reforientation;
	color color;
	short int body_model= 2;
	stats statistics;
	turret turret;
public:
	void refresh(bool key[], int vector[]);
	void drawtank();
	vector3D* getrefpositiondirection();
	void setreforientationdirection(float *orient);
};