#pragma once
#include "vector3D.h"
class camera{
	float pi=3.14159295358979323846264;
	float orientation;
	vector3D *objective;
	float distance;
	float elevation;
public:
	camera();
	void refresh(bool key[]);
	void drawcamera();
	void getobjective(vector3D& obj );
	float& getorientation();
	void setdistancerel(float);
	void setdistanceabs(float);
	void setorientationabs(float);
	void setorientationrel(float);
	float getdistance();
};