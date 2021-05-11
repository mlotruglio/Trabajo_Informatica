#pragma once
#include "turret.h"
#include "vector3D.h"
#include "ColorRGB.h"
#include "stats.h"
class body{
	vector3D position; //posicion del tanque (x es hacia delante, y es arriba , z es la derecha)
	float orientation; // angulo en el plano xz respecto del eje Ox,
	ColorRGB color;
	short int model= 2;
	stats statistics;
	void mousemove(int vector[]);
	void keyaction(bool key[]);
public:
	body();
	char* getmodel();
	void drawbody();
	void refresh(bool key[],int mousepos[],bool mousekey[],float t);
	void setposition(vector3D);
	void addorientation(float);
	void setorientation(float);
	float getorientation(void);
	void setmodel(int);
	stats getstats();
};