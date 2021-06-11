#pragma once
#include "vector3D.h"
#include "stats.h"
#include "ObjetoMovil.h"

class Enemigo: public ObjetoMovil
{
private:
	float orientacion_torreta;
public:
	Enemigo();
	void setposition(float, float, float);
	void setspeed(float);
	void setbodyorientationrel(float dir);
	void setbodyorientationabs(float dir);
	void setturretorientation(float dir);
	void refresh(float t);
	void draw();
	vector3D& getposition();
	friend class Interaction;
};

