#pragma once
#include "vector3D.h"
class camera{

	float orientation;
	vector3D *objective;
	float distance;
	float elevation;
public:
	camera();
	void drawcamera();
	void getobjective(vector3D& obj );
	float getorientation();
	void setdistancerel(float);
	void setdistanceabs(float);
	void setorientationabs(float);
	void setorientationrel(float);
	float getdistance();
};