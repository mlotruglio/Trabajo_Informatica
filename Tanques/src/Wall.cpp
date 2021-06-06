#include "Wall.h"
#include "freeglut.h"
Wall::Wall(float x, float y, float z,float s,float h) {
	position.x = x;
	position.y = y;
	position.z = z;
	side = s;
	height = h;
}
void Wall::setposition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}
void Wall::setposition(vector3D p) {
	position = p;
}
vector3D Wall::getposition() {
	return position;
}
void Wall::setheight(float h) {
	height = h;
}
void Wall::setside(float s) {
	side = s;
}
void Wall::drawwall() {
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(side/2.0,0,side/2.0);
		glVertex3f(side / 2.0, height, side / 2.0);
		glVertex3f(side / 2.0, height, -side / 2.0);
		glVertex3f(side / 2.0, 0, -side / 2.0);
		glEnd();
		glPopMatrix();
	}
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(side / 2.0, height, side / 2.0);
	glVertex3f(side / 2.0, height, -side / 2.0);
	glVertex3f(-side / 2.0, height, -side / 2.0);
	glVertex3f(-side / 2.0, height, side / 2.0);
	glEnd();
	glPopMatrix();
}
