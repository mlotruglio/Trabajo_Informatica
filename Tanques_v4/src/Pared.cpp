#include "Pared.h"
#include "freeglut.h"
#include "ETSIDI.h"
Pared::Pared(float x, float y, float z,float s) {
	posicion.x = x;
	posicion.y = y;
	posicion.z = z;
	tamaño = s;
}
void Pared::setposition(float x, float y, float z) {
	posicion.x = x;
	posicion.y = y;
	posicion.z = z;
}
void Pared::setposition(vector3D p) {
	posicion = p;
}
vector3D Pared::getposition() {
	return posicion;
}

void Pared::draw() {
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,posicion.z);
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pared.png").id);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glNormal3f(1, 0, 0);
		glTexCoord2d(0, 1); glVertex3f(tamaño / 2.0, 0, -tamaño / 2.0);
		glTexCoord2d(1, 1); glVertex3f(tamaño / 2.0, 0, tamaño / 2.0);
		glTexCoord2d(1, 0);  glVertex3f(tamaño / 2.0, tamaño, tamaño / 2.0); 
		glTexCoord2d(0, 0); glVertex3f(tamaño / 2.0, tamaño, -tamaño / 2.0); 
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pared.png").id);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glNormal3f(0, 1, 0);
	glTexCoord2d(0, 1); glVertex3f(-tamaño / 2.0, tamaño, -tamaño / 2.0);
	glTexCoord2d(1, 1); glVertex3f(-tamaño / 2.0, tamaño, tamaño / 2.0); 
	glTexCoord2d(1, 0); glVertex3f(tamaño / 2.0, tamaño, tamaño / 2.0);
	glTexCoord2d(0, 0);  glVertex3f(tamaño / 2.0, tamaño, -tamaño / 2.0); 
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
