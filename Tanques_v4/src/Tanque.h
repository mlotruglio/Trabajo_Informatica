#pragma once
#include "vector3D.h"
#include "stats.h"
#include "ObjetoMovil.h"

class Tanque:public ObjetoMovil
{
private:
	float orientacion_torreta;
	float recarga;
	float vida;
public:
	Tanque();
	void setposition(float, float, float);
	void setspeed(float );
	void setRecarga(float);
	void setVida(float );
	float getVida();
	float getRecarga();
	void setColor(Byte , Byte , Byte );
	void setbodyorientationrel(float dir);
	void setturretorientation(float dir);
	void refresh(float t);
	void draw();
	float getturretorientation();
	vector3D& getposition();
	friend class Interaction;
};