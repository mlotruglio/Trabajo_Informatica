#include "tank.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264

tank::tank() {
	body_orientation = 0.0f;
	turret_orientation = 0.0f;
	orientation = NULL;
	speed = 0;
}

/*tank::tank(){
	orientation = NULL;
	FILE* file = fopen(getbodymodel(), "r");
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
				turret_relativeposition.x = pos_x; 
				turret_relativeposition.y = pos_y;
				turret_relativeposition.z = pos_z;
			}
			if (strstr(string, "health") != NULL) {
				char aux[15]; float  health;
				sscanf(string, "%s %f ", aux, &health);
				statistics.health+=health;
			}
			if (strstr(string, "armor") != NULL) {
				char aux[15]; float  armor;
				sscanf(string, "%s %f ", aux, &armor);
				statistics.armor+=armor;
			}
			if (strstr(string, "speed") != NULL) {
				char aux[15]; float  speed;
				sscanf(string, "%s %f ", aux, &speed);
				statistics.speed*=speed;
			}
			if (strstr(string, "damage") != NULL) {
				char aux[15]; float  damage;
				sscanf(string, "%s %f ", aux, &damage);
				statistics.damage*=damage;
			}
		}
	}
	fclose(file);
	file = fopen(getturretmodel(), "r");
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
				cannon_relativeposition.x = pos_x;
				cannon_relativeposition.y = pos_y;
				cannon_relativeposition.z = pos_z;
			}
			if (strstr(string, "health") != NULL) {
				char aux[15]; float  health;
				sscanf(string, "%s %f ", aux, &health);
				statistics.health += health;
			}
			if (strstr(string, "armor") != NULL) {
				char aux[15]; float  armor;
				sscanf(string, "%s %f ", aux, &armor);
				statistics.armor += armor;
			}
			if (strstr(string, "speed") != NULL) {
				char aux[15]; float  speed;
				sscanf(string, "%s %f ", aux, &speed);
				statistics.speed *= speed;
			}
			if (strstr(string, "damage") != NULL) {
				char aux[15]; float  damage;
				sscanf(string, "%s %f ", aux, &damage);
				statistics.damage *= damage;
			}
		}
	}
	fclose(file);
	file = fopen(getcannonmodel(), "r");
	if (file == NULL)return;
	else {
		while (!feof(file)) {
			char string[250];
			fflush(file);
			fgets(string, 250, file);
			if (strstr(string, "fireposition") != NULL) {
				char aux[15];
				float  pos_x, pos_y, pos_z;
				sscanf(string, "%s %f %f %f", aux, &pos_x, &pos_y, &pos_z);
				fire_relativeposition.x = pos_x;
				fire_relativeposition.y = pos_y;
				fire_relativeposition.z = pos_z;
			}
			if (strstr(string, "health") != NULL) {
				char aux[15]; float  health;
				sscanf(string, "%s %f ", aux, &health);
				statistics.health += health;
			}
			if (strstr(string, "armor") != NULL) {
				char aux[15]; float  armor;
				sscanf(string, "%s %f ", aux, &armor);
				statistics.armor += armor;
			}
			if (strstr(string, "speed") != NULL) {
				char aux[15]; float  speed;
				sscanf(string, "%s %f ", aux, &speed);
				statistics.speed *= speed;
			}
			if (strstr(string, "damage") != NULL) {
				char aux[15]; float  damage;
				sscanf(string, "%s %f ", aux, &damage);
				statistics.damage *= damage;
			}
		}
	}
	fclose(file);
}*/

void tank::setposition(float x, float y, float z){
	position.x=x;
	position.y=y;
	position.z=z;
}
void tank::setorientation(float& dir) {
	orientation = &dir;
}

float tank::getorientation() {
	return *orientation;
}

void tank::setbodyorientationrel(float dir) {
	body_orientation += dir;
}

void tank::setturretorientation(float dir) {
	turret_orientation= dir;
}

void tank::refresh(float t) {
	/*mouse(mousepos, mousekey);
	keyactions(key, t);*/
	//
	position.x += speed * cos(body_orientation * 3.1415926535 / 180) * t;
	position.z += -speed * sin(body_orientation * 3.1415926535 / 180) * t;
	//	printf("posicion tanque=%f %f %f, posicion torreta= %f %f %f, posicioncañon=%f %f %f, posiciondisparo= %f %f %f\n",position.x,position.y,position.z,turret_relativeposition.x, turret_relativeposition.y, turret_relativeposition.z,canonrotao.x,canonrotao.y,canonrotao.z,disparorotao.x,disparorotao.y,disparorotao.z);
}
void tank::drawtank() {
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	glColor3ub(0, 255, 255);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(hitboxradius * cos(i * 2 * pi / 20), 0, hitboxradius * sin(i * 2 * pi / 20));
	}
	glEnd();

	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(body_orientation, 0, 1, 0);
	glTranslatef(hitboxradius * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(hitboxradius * 0.05, hitboxradius * 0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(turret_orientation, 0, 1, 0);
	glTranslatef(hitboxradius * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(hitboxradius * 0.05, hitboxradius * 0.2, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
vector3D& tank::getposition() {
	return position;
}

/*void tank::mouse(int mousepos[],bool mousekey[]) {
	if (orientation != NULL)
		turret_orientation=*orientation + atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535;
	else
		turret_orientation=atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535;
}*/

void tank::setspeed(float v) {
	speed = v;
}

float tank::getturretorientation() {
	return turret_orientation;
}
