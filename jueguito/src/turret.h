#pragma once
#include "cannon.h"
#include "vector3D.h"
#include "ColorRGB.h"
#include "stats.h"
class turret{
	ColorRGB color;
	cannon cannon;
	vector3D position;
	float orientation;
	stats statistics;
	int model = 1;
	void mouse(int vector[],bool mousekey[]);
	void keyaction(bool key[]);
public:
	turret();
	char* getmodel();
	void refresh(bool key[],int mousepos[],bool mousekey[],float t);
	void drawturret();
	void setorientation(float);
	void setposition(vector3D);
	void setposition(float,float,float);
	void setmodel(int);
	stats getstats();
};