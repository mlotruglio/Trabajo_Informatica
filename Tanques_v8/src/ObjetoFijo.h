#pragma once
#include "vector3D.h"

class ObjetoFijo
{
protected:
	char* getTextura();
	vector3D posicion;
	float tamanio;
	char* textura;
public:
	enum cosas { none, stone_bricks, grass, sand };
	cosas texturas;
	ObjetoFijo();
	ObjetoFijo(vector3D _posicion, float _tamanio = 1);
	ObjetoFijo(float _x, float _y, float _z, float _tamanio = 1);
	void setPosicion(float, float, float);
	void setPosicion(vector3D);
	vector3D getPosicion();
	void setTamanio(float);
	float getTamanio();
};