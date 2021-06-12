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
	danio = 1;
}
void Disparo::dibuja() {
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(posicion.x,1.4, posicion.z);
	glutSolidSphere(radiohitbox, 10, 10);
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

void Disparo::setDanio(float d) {
	danio = d;
}
float Disparo::getDanio() {
	return danio;
}

void Disparo::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}