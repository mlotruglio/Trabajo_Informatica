#pragma once
#include "vector3D.h"
#include "stats.h"
class Enemigo
{
private:
	float body_orientation;
	float turret_orientation;
	float hitboxradius = 1.5;
	float speed;
	vector3D position;
public:
	Enemigo();
	void setposition(float, float, float);
	void setspeed(float);
	void setbodyorientationrel(float dir);
	void setturretorientation(float dir);
	void refresh(float t);
	void drawtank();
	vector3D& getposition();
	friend class Interaction;
};

