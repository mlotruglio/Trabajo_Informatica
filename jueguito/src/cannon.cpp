#include "cannon.h"
#include "draw.h"
#include "freeglut.h"
#include <stdio.h>
#include <Cstring>
cannon::cannon() {
	model = 1;
	updatestats();
}
char* cannon::getmodel() {
	char string[50];
	if (model == 1)strcpy(string, "./modelos3d/cannon1.txt");
	if (model== 2)strcpy(string, "./modelos3d/cannon2.txt");
	if (model == 3)strcpy(string, "./modelos3d/cannon3.txt");
	if (model == 4)strcpy(string, "./modelos3d/cannon4.txt");
	return string;
}
void cannon::drawcannon() {
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 1, 0, 0);
	draw(getmodel());
	glPopMatrix();
}
void cannon::refresh(bool key[], int mousepos[],bool mousekey[],float t) {
	//if click genera nuevo disparo
//if pressed left click and minigun-> static float angularspeed++-->rotation+=angularspeed*fps-->else angularspeed--
	keyaction(key);
	mouse(mousepos, mousekey);
}
void cannon::keyaction(bool key[]) {
// esto se va cuando terminen las pruebas, hay que poner un algo para cambiar el modelo
	static bool lastkey[255];
	if ((key['2'] && !lastkey['2']))setmodel(2);
	if ((key['1'] && !lastkey['1']))setmodel(1);
}
void cannon::mouse(int mousepos[],bool mousekey[]) {
	if (mousekey[GLUT_LEFT_BUTTON])shoot(1);
	else shoot(0);
}
void cannon::setposition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}
void cannon::setposition(vector3D pos) {
	position = pos;
}
stats cannon::getstats() {
	return statistics;
}
void cannon::setmodel(int m) {
	model = m;
	updatestats();
	orientation = 0;
}
void cannon::shoot(bool state) {
	if (type==normal) {
	}
	if (type==minigun) {
		static float angularspeed;
		if (state)angularspeed += 0.1;
		else angularspeed -= 0.4;
		if (angularspeed < 0)angularspeed = 0;
		if (angularspeed > 20)angularspeed = 20;
		orientation += angularspeed;
		if (orientation > 60) {
			orientation -= 60;

		}
	}
	if (type ==shotgun) {}
}
void cannon::updatestats() {
	FILE* file = fopen(getmodel(), "r");
	if (file == NULL)return;
	else {
		while (!feof(file)) {
			char string[250];
			fflush(file);
			fgets(string, 250, file);
			if (strstr(string, "type") != NULL) {
				if (strstr(string, "normal") != NULL)type = normal;
				if (strstr(string, "minigun") != NULL)type = minigun;
				if (strstr(string, "shotgun") != NULL)type = shotgun;
			}
			if (strstr(string, "fireposition") != NULL) {
				char aux[15];
				float  pos_x, pos_y, pos_z;
				sscanf(string, "%s %f %f %f", aux, &pos_x, &pos_y, &pos_z);
				fireposition = { pos_x, pos_y, pos_z };
			}
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