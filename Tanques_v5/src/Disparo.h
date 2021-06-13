#pragma once
#include "ColorRGB.h"
#include "vector3D.h"
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Disparo: public ObjetoMovil
{
private:
	float tiempo_vida;
	float rebotes;
	float danio;
public:
	Disparo(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox = 0.2);
	Disparo(vector3D _posicion, float _velocidad = 0, float _orientacion = 0, float _radiohitbox = 0.2, float _tiempo_vida = 10, int rebotes = 2, float danio = 1);
	Disparo();

	void dibuja();
	void refresh(float t);
	void actualizaRebote();
	bool getRebote();
	void setDanio(float);
	float getDanio();
	void setTime(float);
	float getTime();

	friend class Interaction;
};

