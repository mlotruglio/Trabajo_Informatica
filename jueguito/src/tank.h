#pragma once
#include "body.h"
#include "turret.h"
#include "vector3D.h"
#include "stats.h"
class tank {
private:
	body body;
	turret turret;
	vector3D position;
	float *orientation;
	stats statistics;
	void keyactions(bool key[],float t);
	void mouse(int mousepos[],bool mousekey[]);
public:
	tank();
	void setposition(float, float, float);
	void setorientation(float&);
	void refresh(bool key[], int mousepos[],bool mousekey[],float t);
	void drawtank();
	vector3D& getposition();
};