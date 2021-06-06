#pragma once
#include "vector3D.h"
#include "stats.h"
class tank {
private:
	float body_orientation;
	float turret_orientation;
	float hitboxradius=1.5;
	float speed;
	vector3D position;
	float *orientation;
public:
	tank();
	void setposition(float, float, float);
	void setspeed(float );
	void setorientation(float&);
	float getorientation();
	void setbodyorientationrel(float dir);
	void setturretorientation(float dir);
	void refresh(float t);
	void drawtank();
	float getturretorientation();
	vector3D& getposition();
	friend class Interaction;
};