#pragma once
#include "ColorRGB.h"
#include "vector3D.h"
#include "ObjetoMovil.h"

class Disparo: public ObjetoMovil
{
private:
	float tiempo_vida;
	int rebotes;

public:
	Disparo();
	void dibuja();
	void setPos(vector3D);
	void setOri(float);
	void setSpeed(float);
	bool setRebote();
	float getTime();
	void refresh(float t);
	friend class Interaction;
};

