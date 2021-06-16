#pragma once
#include "vector3D.h"
#include "ObjetoFijo.h"
class Suelo :public ObjetoFijo
{
public:
	Suelo(cosas _textura = none) :ObjetoFijo(0, 0, 0, 1) { texturas = _textura; };
	Suelo(float _x = 0, float _y = 0, float _z = 0, float _tamanio = 1, cosas _textura = none) :ObjetoFijo(_x, _y, _z, _tamanio) { texturas = _textura; };
	void dibuja();
	friend class Interaction;
};
