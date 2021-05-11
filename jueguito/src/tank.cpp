#include "tank.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
tank::tank(){
	orientation = NULL;
	statistics = statistics + turret.getstats() + body.getstats();
	FILE* file = fopen(body.getmodel(), "r");
	if (file == NULL)return;
	else {
		while (!feof(file)) {
			char string[250];
			fflush(file);
			fgets(string, 250, file);
			if (strstr(string, "turretposition") != NULL) {
				char aux[15];
				float  pos_x, pos_y, pos_z;
				sscanf(string, "%s %f %f %f", aux, &pos_x, &pos_y, &pos_z);
				turret.setposition({ pos_x,pos_y,pos_z });
			}
		}
	}
	fclose(file);
}
void tank::setposition(float x, float y, float z){
	position.x=x;
	position.y=y;
	position.z=z;
}
void tank::setorientation(float& dir) {
	orientation = &dir;
}
void tank::refresh(bool key[], int mousepos[], bool mousekey[], float t) {
	mouse(mousepos,mousekey);
	keyactions(key, t);
	body.refresh(key, mousepos,mousekey, t);
	turret.refresh(key, mousepos,mousekey, t);
}
void tank::drawtank() {
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	body.drawbody();
	turret.drawturret();
	glPopMatrix();
}
vector3D& tank::getposition() {
	return position;
}
void tank::keyactions(bool key[],float t) {
	if (key['w'] || key['W']) {
		position.x += statistics.speed * cos(body.getorientation() * 3.1415926535 / 180) * t;
		position.z += -statistics.speed * sin(body.getorientation() * 3.1415926535 / 180) * t;
	}
	if (key['a'] || key['A']) {
		body.addorientation(5);
	}
	if (key['s'] || key['S']) {
		position.x -= statistics.speed * cos(body.getorientation() * 3.1415926535 / 180) * t;
		position.z -= -statistics.speed * sin(body.getorientation() * 3.1415926535 / 180) * t;
	}
	if (key['d'] || key['D']) {
		body.addorientation(-5);
	}
}
void tank::mouse(int mousepos[],bool mousekey[]) {
	if (orientation != NULL)
		turret.setorientation(*orientation + atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535);
	else
		turret.setorientation(atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535);
}