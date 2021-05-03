#pragma once
#include "cannon.h"
#include "structs.h"
class turret{
	char* getmodel(int model);
	void mousemove(int vector[]);
	void keyaction(bool key[]);
	color color;
	cannon cannon;
	vector3D position = {0,1,0};
	float orientation;
	stats statistics;
	int turret_model = 1;
public:
	void refresh(bool key[],int mousepos[]);
	void setorientation(float orient);
	void drawturret();
};