#include "turret.h"
#include "draw.h"
#include "freeglut.h"
#include <math.h>
#include <stdio.h>
char* turret::getmodel(int i) {
	char string[50];
	if (i == 1)strcpy(string, "./modelos3d/torreta1.txt");
	if (i == 2)strcpy(string, "./modelos3d/torreta2.txt");
	if (i == 3)strcpy(string, "./modelos3d/torreta3.txt");
	if (i == 4)strcpy(string, "./modelos3d/torreta4.txt");
	return string;
}
void turret::drawturret() {
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 0, 1, 0);
	draw(getmodel(turret_model));
	cannon.drawcannon();
	glPopMatrix();
}
void turret::refresh(bool key[],int mousepos[]) {
	mousemove(mousepos);
	keyaction(key);
	cannon.refresh(key, mousepos);
}
void turret::keyaction(bool key[]) {
}
void turret::mousemove(int mousepos[]) {
}
void turret::setorientation(float orient) {
	orientation = orient;
}