#include "Tanque.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264
Tanque::Tanque(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox ) : ObjetoMovil(_posicion, _velocidad, _orientacion, _radiohitbox) {
	orientacion_torreta=0;
	tiempo_recarga=1;
	recarga=0;
	vida=100;
	posicion.y = 0.1;
}
Tanque::Tanque(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox, float _vida,float _tiempo_recarga) : ObjetoMovil(_posicion, _velocidad, _orientacion, _radiohitbox) {
	orientacion_torreta = 0;
	vida = _vida;
	tiempo_recarga = _tiempo_recarga;
	recarga = 0;
	posicion.y = 0.1;
}
Tanque::Tanque() {
	orientacion_torreta = 0;
	tiempo_recarga = 1;
	recarga = 0;
	vida = 100;
	posicion.y = 0.1;
}
void Tanque::refresh(float t) {
	ObjetoMovil::refresh(t);
	recarga -= t;
	if (recarga < 0) recarga = 0;
	velocidad= 0;
}
void Tanque::dibuja() {
	glPushMatrix();
		glTranslatef(posicion.x, posicion.y, posicion.z);
		glPushMatrix();
			glColor3ub(color.red, color.green, color.blue);
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
		glPushMatrix();
			glRotatef(orientacion, 0, 1, 0);
			glColor3ub(color.red, color.green, color.blue);
			dibuja::draw("modelos3d/cuerpo.txt",radiohitbox/1.6);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, radiohitbox/1.5, 0);
			glColor3ub(color.red, color.green, color.blue);
			glRotatef(orientacion_torreta, 0, 1, 0);
			dibuja::draw("modelos3d/torreta.txt",radiohitbox/1.6);
			glTranslatef(1.2 * radiohitbox / 1.6, 0.3333 * radiohitbox / 1.6, 0);
			dibuja::draw("modelos3d/cannon.txt",radiohitbox/1.6);
		glPopMatrix();
		//LE BARRAS DE VIDA
		glPushMatrix();
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
	glPopMatrix();
}
vector3D& Tanque::getPunteroPosicion() { return posicion; }
void Tanque::resetRecarga() { recarga = tiempo_recarga; }
void Tanque::setTiempoRecarga(float _tiempo_recarga) { tiempo_recarga = _tiempo_recarga; }
float Tanque::getRecarga() { return recarga; }
void Tanque::setVida(float _vida) { vida = _vida; }
float Tanque::getVida() { return vida; }
void Tanque::setOrientaciontorreta(float _orientacion_torreta) {orientacion_torreta = _orientacion_torreta;}
float Tanque::getOrientaciontorreta() { return orientacion_torreta; }