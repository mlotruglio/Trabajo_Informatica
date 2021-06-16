#include "Suelo.h"
#include "freeglut.h"
#include "ETSIDI.h"
void Suelo::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glColor3ub(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(getTextura()).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glNormal3f(0, 1, 0);
	glTexCoord2d(0, 1); glVertex3f(-tamanio / 2.0, 0, tamanio / 2.0);
	glTexCoord2d(1, 1); glVertex3f(-tamanio / 2.0, 0, -tamanio / 2.0);
	glTexCoord2d(1, 0); glVertex3f(tamanio / 2.0, 0, -tamanio / 2.0);
	glTexCoord2d(0, 0); glVertex3f(tamanio / 2.0, 0, tamanio / 2.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
