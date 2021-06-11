#include "Disparo.h"
#include <math.h>
#include <stdio.h>
#define pi 3.14159265358979323846264


Disparo::Disparo() {
	radiohitbox = 0.2;
	posicion.x = 0;
	posicion.y = 0;
	posicion.z = 0;
	orientacion = 0;
	velocidad = 0;
	rebotes = 2;
	tiempo_vida = 10.0f;
}
void Disparo::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glPushMatrix();
	glColor3ub(0, 255, 255);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(radiohitbox * cos(i * 2 * pi / 20), 0, radiohitbox * sin(i * 2 * pi / 20));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(orientacion, 0, 1, 0);
	glTranslatef(radiohitbox * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radiohitbox * 0.2, radiohitbox * 0.8, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
void Disparo::refresh(float t) {
	tiempo_vida -= t;
	posicion.x += velocidad * cos(orientacion * 3.1415926535 / 180) * t;
	posicion.z += -velocidad * sin(orientacion * 3.1415926535 / 180) * t;
}

void Disparo::setPos(vector3D pos) {
	posicion = pos;
}

void Disparo::setOri(float ori) {
	orientacion = ori;
}

void Disparo::setSpeed(float v) {
	velocidad = v;
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
