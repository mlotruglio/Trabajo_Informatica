#pragma once
#include "vector3D.h"
#include "ColorRGB.h"

class ObjetoMovil
{
protected:
	vector3D posicion;
	float velocidad;
	float orientacion;
	float radiohitbox;
	ColorRGB color;

public:
	ObjetoMovil();
	void refresh(float t);
};

