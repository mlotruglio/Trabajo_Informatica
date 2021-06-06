#pragma once
#include "ColorRGB.h"
#include "vector3D.h"


class Disparo
{
private:
	vector3D position;
	ColorRGB color;
	float radio;
	float orientation;
	float speed;
	float tiempo_vida;
	int rebotes;

public:
	Disparo(vector3D pos, float ori, float v = 3.0f,float r = 0.2f, float t = 5, int rebote = 0);
	Disparo();
	void dibuja();
	void setPos(vector3D);
	void setOri(float);
	void setSpeed(float);
	bool setRebote();
	float getTime();
	void refresh(float t);
	//static bool getRebotes(Disparo& d);
	friend class Interaction;
};

