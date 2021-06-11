#include "Enemigo.h"
#include "Enemigo.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264

Enemigo::Enemigo() {
	posicion.x = 4.0f;
	posicion.z = 4.0f;
	orientacion = -140.0f;
	orientacion_torreta = -37.1f;
	velocidad = 0;
}

void Enemigo::setposition(float x, float y, float z) {
	posicion.x = x;
	posicion.y = y;
	posicion.z = z;
}


void Enemigo::setbodyorientationrel(float dir) {
	orientacion += dir;
}

void Enemigo::setbodyorientationabs(float dir) {
	orientacion = dir;
}

void Enemigo::setturretorientation(float dir) {
	orientacion_torreta = dir;
}

void Enemigo::refresh(float t) {
	ObjetoMovil::refresh(t);
}
void Enemigo::draw() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glPushMatrix();
	glColor3ub(255, 0, 0);
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
	glutSolidCone(radiohitbox * 0.05, radiohitbox * 0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(orientacion_torreta, 0, 1, 0);
	glTranslatef(radiohitbox * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radiohitbox * 0.05, radiohitbox * 0.2, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
vector3D& Enemigo::getposition() {
	return posicion;
}

void Enemigo::setspeed(float v) {
	velocidad = v;
}