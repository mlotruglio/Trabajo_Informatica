#pragma once
#include "vector3D.h"
#include "ColorRGB.h"
#include "stats.h"
class cannon{
	enum type {normal,minigun,shotgun};
	type type;
	ColorRGB color;
	vector3D position;
	vector3D fireposition;
	stats statistics;

	int model;
	void updatestats();
	void mouse(int vector[],bool mousekey[]);
	void keyaction(bool key[]);
	void shoot(bool state);
public:
	float orientation;
	cannon();
	char* getmodel();
	void refresh(bool key[], int mousepos[],bool mousekey[],float t);
	void drawcannon();
	void setmodel(int);
	stats getstats();
	void setposition(float, float, float);
	void setposition(vector3D);
};

