#include "turret.h"
#include "draw.h"
#include "freeglut.h"
#include <math.h>
#include <stdio.h>
turret::turret() {
	statistics = statistics + cannon.getstats();
	FILE* file = fopen(getmodel(), "r");
	if (file == NULL)return;
	else {
		while (!feof(file)) {
			char string[250];
			fflush(file);
			fgets(string, 250, file);
			if (strstr(string, "cannonposition") != NULL) {
				char aux[15];
				float  pos_x, pos_y, pos_z;
				sscanf(string, "%s %f %f %f", aux, &pos_x, &pos_y, &pos_z);
				cannon.setposition(pos_x, pos_y, pos_z);
			}
			//posicion de la secundaria
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
char* turret::getmodel() {
	char string[50];
	if (model == 1)strcpy(string, "./modelos3d/torreta1.txt");
	if (model == 2)strcpy(string, "./modelos3d/torreta2.txt");
	if (model == 3)strcpy(string, "./modelos3d/torreta3.txt");
	if (model == 4)strcpy(string, "./modelos3d/torreta4.txt");
	return string;
}
void turret::drawturret() {
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 0, 1, 0);
	draw(getmodel());
	cannon.drawcannon();
	glPopMatrix();
}
void turret::refresh(bool key[],int mousepos[],bool mousekey[],float t) {
	mouse(mousepos,mousekey);
	keyaction(key);
	cannon.refresh(key, mousepos,mousekey,t);
}
void turret::keyaction(bool key[]) {}
void turret::mouse(int mousepos[],bool mousekey[]) {
}
void turret::setorientation(float orient) {
	orientation = orient;
}
void turret::setposition(vector3D pos) {
	position = pos;
}
void turret::setposition(float x,float y,float z) {
	position.x=x;
	position.y = y;
	position.z = z;
}
stats turret::getstats() {
	return statistics;
}
void turret::setmodel(int m) {
	model = m;
}