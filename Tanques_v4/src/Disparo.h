#pragma once
#include "ColorRGB.h"
#include "vector3D.h"
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Disparo: public ObjetoMovil
{
private:
	float tiempo_vida;
	int rebotes;
	float danio;

public:
	Disparo();
	void dibuja();
	void setPos(vector3D);
	void setOri(float);
	void setSpeed(float);
	bool setRebote();
	void setDanio(float);
	float getDanio();
	float getTime();
	void setColor(Byte r, Byte v, Byte a);
	void refresh(float t);
	friend class Interaction;
};

