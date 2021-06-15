#pragma once
#include "vector3D.h"
#include "ColorRGB.h"

class ObjetoMovil
{
protected:
	vector3D posicion;
	float orientacion;
	float velocidad_max;
	float velocidad;
	float radiohitbox;
	ColorRGB color;

public:
	ObjetoMovil(vector3D _posicion, float _velocidad_max=0, float _orientacion=0, float _radiohitbox=1);
	ObjetoMovil();
	void refresh(float _t);

	void setPosicion(vector3D _posicion);
	void setPosicion(float _x, float _y, float _z);
	vector3D getPosicion();
	vector3D& getPunteroPosicion();

	void setOrientacion(float _orientacion);
	float getOrientacion();

	void setVelocidadMax(float _velocidad_max);
	float getVelocidadMax();

	void setVelocidad(float _velocidad); /// la velocidad de esto va entre -1 y 1, -1 es para atras a la velocidad max, 0 es quieto, 1 es para delante a velocidad max
	float getVelocidad();

	void setRadiohitbox(float _radiohitbox);
	float getRadiohitbox();

	void setColor(ColorRGB _color);
	void setColor(Byte _r, Byte _g, Byte _b);
	ColorRGB getColor();
};

