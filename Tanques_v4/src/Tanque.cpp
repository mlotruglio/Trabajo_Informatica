#include "Tanque.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264

Tanque::Tanque() {
	orientacion = 0.0f;
	orientacion_torreta = 0.0f;
	velocidad = 0;
	posicion.y = 0.1;
	vida = 100;
}

void Tanque::setposition(float x, float y, float z){
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}
void Tanque::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}
void Tanque::setbodyorientationrel(float dir) {
	orientacion += dir;
}

void Tanque::setturretorientation(float dir) {
	orientacion_torreta= dir;
}

void Tanque::refresh(float t) {
	ObjetoMovil::refresh(t);
	recarga -= t;
	if (recarga < 0) recarga = 0;
	velocidad= 0;
}

void Tanque::setRecarga(float t) {
	recarga = t;
}
float Tanque::getRecarga() {
	return recarga;
}
void Tanque::draw() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	//glColor3ub(0, 255, 255);
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
	glPushMatrix();
	glRotatef(orientacion, 0, 1, 0);
	glColor3ub(color.red, color.green, color.blue);
	dibuja::draw("modelos3d/cuerpo.txt",radiohitbox/1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, radiohitbox/1.5, 0);
	glColor3ub(color.red, color.green, color.blue);
	glRotatef(orientacion_torreta, 0, 1, 0);
	dibuja::draw("modelos3d/torreta.txt",radiohitbox/1.5);
	glTranslatef(1.2 * radiohitbox / 1.5, 0.3333 * radiohitbox / 1.5, 0);
	dibuja::draw("modelos3d/cannon.txt",radiohitbox/1.5);
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 255);
		glNormal3f(0,1,0);
		glVertex3f(-radiohitbox * 1.5, 0.1, -radiohitbox * 0.75);
		glVertex3f(-radiohitbox * 1.55, 0.1, -radiohitbox * 0.75);
		glVertex3f(-radiohitbox * 1.55, 0.1, -radiohitbox * 0.75 + vida/100 * 1.5 *radiohitbox);
		glVertex3f(-radiohitbox * 1.5, 0.1, -radiohitbox * 0.75 + vida / 100 * 1.5 * radiohitbox);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
		glNormal3f(0,1,0);
		glVertex3f(-radiohitbox * 1.5, 0.1, +radiohitbox * 0.75);
		glVertex3f(-radiohitbox * 1.55, 0.1, +radiohitbox * 0.75);
		glVertex3f(-radiohitbox * 1.55, 0.1, +radiohitbox * 0.75 - (100 - vida) / 100 * 1.5 * radiohitbox);
		glVertex3f(-radiohitbox * 1.5, 0.1, +radiohitbox * 0.75 - (100-vida) / 100 * 1.5 * radiohitbox);
	glEnd();
	glPopMatrix();
}
vector3D& Tanque::getposition() {
	return posicion;
}

void Tanque::setspeed(float v) {
	velocidad = v;
}

float Tanque::getturretorientation() {
	return orientacion_torreta;
}

void Tanque::setVida(float v) {
	vida = v;
}
float Tanque::getVida() {
	return vida;
}
