#include "Pared.h"
#include "freeglut.h"
#include "ETSIDI.h"
void Pared::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(getTextura()).id);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glNormal3f(1, 0, 0);
		glTexCoord2d(0, 1); glVertex3f(tamanio / 2.0, 0, -tamanio / 2.0);
		glTexCoord2d(1, 1); glVertex3f(tamanio / 2.0, 0, tamanio / 2.0);
		glTexCoord2d(1, 0);  glVertex3f(tamanio / 2.0, tamanio, tamanio / 2.0);
		glTexCoord2d(0, 0); glVertex3f(tamanio / 2.0, tamanio, -tamanio / 2.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(getTextura()).id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glNormal3f(0, 1, 0);
	glTexCoord2d(0, 1); glVertex3f(-tamanio / 2.0, tamanio, -tamanio / 2.0);
	glTexCoord2d(1, 1); glVertex3f(-tamanio / 2.0, tamanio, tamanio / 2.0);
	glTexCoord2d(1, 0); glVertex3f(tamanio / 2.0, tamanio, tamanio / 2.0);
	glTexCoord2d(0, 0);  glVertex3f(tamanio / 2.0, tamanio, -tamanio / 2.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


