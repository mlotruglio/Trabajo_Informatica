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
	ObjetoMovil(vector3D _posicion, float _velocidad=0, float _orientacion=0, float _radiohitbox=1);
	ObjetoMovil();
	void refresh(float t);
	void setPosicion(vector3D);
	void setPosicion(float, float, float);
	vector3D getPosicion();
	void setOrientacion(float);
	float getOrientacion();
	void setVelocidad(float);
	float getVelocidad();
	void setColor(ColorRGB color);
	void setColor(Byte r, Byte v, Byte a);
};

