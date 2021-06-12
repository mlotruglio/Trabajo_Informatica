#include "Suelo.h"
#include "freeglut.h"
#include "ETSIDI.h"
Suelo::Suelo(float x, float y, float z, float s) {
	posicion.x = x;
	posicion.y = y;
	posicion.z = z;
	tamaño = s;

}
void Suelo::setposition(float x, float y, float z) {
	posicion.x = x;
	posicion.y = y;
	posicion.z = z;
}
void Suelo::setposition(vector3D p) {
	posicion = p;
}
vector3D Suelo::getposition() {
	return posicion;
}
void Suelo::draw() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suelo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-tamaño / 2.0, 0, tamaño / 2.0);
	glTexCoord2d(1, 1); glVertex3f(-tamaño / 2.0, 0, -tamaño / 2.0);
	glTexCoord2d(1, 0); glVertex3f(tamaño / 2.0, 0, -tamaño / 2.0);
	glTexCoord2d(0, 0); glVertex3f(tamaño / 2.0, 0, tamaño / 2.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
