#pragma once
#include "structs.h"
class cannon{
	char* getmodel(int i);
	void mousemove(int vector[]);
	void keyaction(bool key[]);
	color color;
	vector3D position = {1.2,0.3333,0};
	float orientation;
	stats statistics;
	int cannon_model=1;
public:
	void refresh(bool key[], int mousepos[]);
	void drawcannon();
};

