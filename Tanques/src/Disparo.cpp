#include "Disparo.h"
#include <math.h>
#include <stdio.h>
#define pi 3.14159265358979323846264

Disparo::Disparo(vector3D pos, float ori, float v,float r,float t, int reb) {
	position = pos;
	orientation = ori;
	speed = v;
	tiempo_vida = t;
	rebotes = reb;
	radio = r;
}

Disparo::Disparo() {
	radio = 0.2;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	orientation = 0;
	speed = 0;
	rebotes = 2;
	tiempo_vida = 10.0f;
}
void Disparo::dibuja() {
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	glColor3ub(0, 255, 255);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(radio * cos(i * 2 * pi / 20), 0, radio * sin(i * 2 * pi / 20));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(orientation, 0, 1, 0);
	glTranslatef(radio * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radio * 0.2, radio * 0.8, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
void Disparo::refresh(float t) {
	tiempo_vida -= t;
	position.x += speed * cos(orientation * 3.1415926535 / 180) * t;
	position.z += -speed * sin(orientation * 3.1415926535 / 180) * t;
	//printf("%f\n",orientation);
}

void Disparo::setPos(vector3D pos) {
	position = pos;
}

void Disparo::setOri(float ori) {
	orientation = ori;
}

void Disparo::setSpeed(float v) {
	speed = v;
}

bool Disparo::setRebote() {
	rebotes = rebotes-1;
	if (rebotes <= 0)
		return true;
	return false;
}

float Disparo::getTime() {
	return tiempo_vida;
}
