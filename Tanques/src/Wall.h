#pragma once
#include "vector3D.h"
class Wall
{
	vector3D position;
	float side;
	float height;
public:
	Wall(float x = 0, float y = 0, float z = 0, float s = 1,float h=1);
	void setposition(float,float ,float);
	void setposition(vector3D);
	vector3D getposition();
	void setheight(float);
	void setside(float);
	void drawwall();
	friend class Interaction;
};

