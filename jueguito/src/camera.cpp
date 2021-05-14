#include "camera.h"
#include "freeglut.h"
#include <math.h>
camera::camera() {
	orientation = 0;
	distance = 10;
	objective = NULL;
	elevation = 60;
}
void camera::getobjective(vector3D& object) {
		objective = &object;
}
void camera::drawcamera() {
	if (objective != NULL)
		gluLookAt(objective->x - distance * cos(elevation * pi / 180) * cos(orientation * pi / 180), sin(elevation * pi / 180) * distance, objective->z + distance * cos(elevation * pi / 180) * sin(orientation * pi / 180),
			objective->x, objective->y, objective->z,
			0.0, 1.0, 0.0);
	else
		gluLookAt(5,5,5,0,0,0,0,1,0);
}
float& camera::getorientation() {
	return orientation;
}
void camera::refresh(bool key[]) {
	static bool lastkey[255];
	if ((key['z'] && !lastkey['z']) || (key['Z'] && !lastkey['Z']))orientation = 0;
	if ((key['o'] && !lastkey['o']) || (key['O'] && !lastkey['O'])) { if (distance >= 10)distance -= 5; if(distance<10)distance = 5; }
	if ((key['p'] && !lastkey['p']) || (key['P'] && !lastkey['P'])) { if (distance <= 25)distance += 5; if(distance>25) distance = 30; }
	if (key['q'] || key['Q']) { orientation += 5; }
	if (key['e'] || key['E']) { orientation -= 5; }
	for (int i = 0; i < 255; i++) lastkey[i] = key[i];
}