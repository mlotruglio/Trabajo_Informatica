#include "Disparo.h"
#include <math.h>
#include <stdio.h>
#define pi 3.14159265358979323846264
Disparo::Disparo(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox ): ObjetoMovil(_posicion, _velocidad, _orientacion, _radiohitbox) {
	tiempo_vida =10;
	rebotes = 2;
	danio = 10;
}
Disparo::Disparo(vector3D _posicion, float _velocidad , float _orientacion , float _radiohitbox , float _tiempo_vida , int _rebotes , float _danio ) :ObjetoMovil(_posicion, _velocidad, _orientacion, _radiohitbox) {
	tiempo_vida = _tiempo_vida;
	rebotes = _rebotes;
	danio = _danio;
}
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
	glTranslatef(posicion.x,posicion.y, posicion.z);
	glutSolidSphere(radiohitbox, 10, 10);
	glPopMatrix();
}
void Disparo::refresh(float t) {
	tiempo_vida -= t;
	posicion.x += velocidad * cos(orientacion * 3.1415926535 / 180) * t;
	posicion.z += -velocidad * sin(orientacion * 3.1415926535 / 180) * t;
}
void Disparo::actualizaRebote() { rebotes -= 1; }
bool Disparo::getRebote() { return rebotes; }
void Disparo::setDanio(float _danio) { danio = _danio; }
float Disparo::getDanio() { return danio; }
void Disparo::setTime(float _tiempo_vida) { tiempo_vida = _tiempo_vida; }
float Disparo::getTime() { return tiempo_vida; }