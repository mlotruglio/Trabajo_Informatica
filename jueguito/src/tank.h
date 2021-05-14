#pragma once
#include "vector3D.h"
#include "stats.h"
class tank {
private:
	float body_orientation;
	vector3D turret_relativeposition;
	float turret_orientation;
	vector3D cannon_relativeposition;
	vector3D fire_relativeposition;
	int bodymodel=2;
	char* getbodymodel();
	int turretmodel=1;
	char* getturretmodel();
	int cannonmodel=1;
	char* getcannonmodel();
	vector3D fire_absoluteposition;
	float fire_orientation;
	float hitboxradius=1.5;
	vector3D position;
	float *orientation;
	stats statistics;
	void keyactions(bool key[],float t);
	void mouse(int mousepos[],bool mousekey[]);
public:
	tank();
	vector3D getfireposition();
	float getfireorientation();
	void setposition(float, float, float);
	void setorientation(float&);
	void refresh(bool key[], int mousepos[],bool mousekey[],float t);
	void drawtank();
	vector3D& getposition();
	friend class Interaction;
};