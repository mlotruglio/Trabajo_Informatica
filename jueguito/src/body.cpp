#include "body.h"
#include "draw.h"
#include "freeglut.h"
#include <math.h>
#include <stdio.h>
body::body() {
	orientation = 0;
	FILE *file=fopen(getmodel(), "r");
	if (file == NULL)return;
	else {
		while (!feof(file)) {
			char string[250];
			fflush(file);
			fgets(string, 250, file);
			if (strstr(string, "health") != NULL) {
				char aux[15]; float  health;
				sscanf(string, "%s %f ", aux, &health);
				statistics.sethealth(health);
			}
			if (strstr(string, "armor") != NULL) {
				char aux[15]; float  armor;
				sscanf(string, "%s %f ", aux, &armor);
				statistics.setarmor(armor);
			}
			if (strstr(string, "speed") != NULL) {
				char aux[15]; float  speed;
				sscanf(string, "%s %f ", aux, &speed);
				statistics.setspeed(speed);
			}
			if (strstr(string, "damage") != NULL) {
				char aux[15]; float  damage;
				sscanf(string, "%s %f ", aux, &damage);
				statistics.setdamage(damage);
			}
		}
	}
	fclose(file);
}
char* body::getmodel() {
	char string[50];
	if (model == 1)strcpy(string, "./modelos3d/cuerpo1.txt");
	if (model == 2)strcpy(string, "./modelos3d/cuerpo2.txt");
	if (model == 3)strcpy(string, "./modelos3d/cuerpo3.txt");
	if (model == 4)strcpy(string, "./modelos3d/cuerpo4.txt");
	return string;
}
void body::drawbody(){
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 0, 1, 0);
	draw(getmodel());
	glPopMatrix();
}
void body::refresh(bool key[], int mousepos[],bool mousekey[],float t) {}
void body::setposition(vector3D pos) {
	position = pos;
}
stats body::getstats() {
	return statistics;
}
void body::setmodel(int m) {
	model = m;
}
void body::addorientation(float angle) {
	orientation += angle;
}
void body::setorientation(float angle) {
	orientation = angle;
}
float body::getorientation(void) {
	return orientation;
}