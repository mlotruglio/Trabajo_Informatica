#pragma once
#include "vector3D.h"
#include "ObjetoFijo.h"

class Pared: public ObjetoFijo
{
public:
	Pared(float x = 0, float y = 0, float z = 0, float s = 1);
	void setposition(float,float ,float);
	void setposition(vector3D);
	vector3D getposition();
	void draw();
	friend class Interaction;
};

