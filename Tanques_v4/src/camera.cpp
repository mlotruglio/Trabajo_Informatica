#include "camera.h"
#include "freeglut.h"
#include <math.h>
camera::camera() {
	orientation = 0;
	distance = 30;
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
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 0.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position[] = { 10.0, 10.0, 1.0, 0.0 };
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
float& camera::getorientation() {
	return orientation;
}


void camera::setdistancerel(float d) {
	distance += d;
}
void camera::setdistanceabs(float d) {
	distance = d;
}
void camera::setorientationabs(float ori) {
	orientation = ori;
}
void camera::setorientationrel(float ori) {
	orientation += ori;
}

float camera::getdistance() {
	return distance;
}