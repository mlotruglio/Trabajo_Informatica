#pragma once
#include "vector3D.h"
#include "ObjetoFijo.h"
class Suelo:public ObjetoFijo
{
public:
	Suelo() :ObjetoFijo(0, 0, 0, 1) {};
	Suelo(float _x = 0, float _y = 0, float _z = 0, float _tamanio = 1) :ObjetoFijo(_x, _y, _z, _tamanio) {};
	void dibuja();
	friend class Interaction;
};
