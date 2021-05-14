#include "tank.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264
vector3D rotatevector(vector3D v, float angle) {
	vector3D vout;
	if (sqrt(v.x * v.x + v.y * v.y + v.z * v.z) != 0) {
		float alpha = -atan(v.z / v.x);
		float gamma = atan(v.y / sqrt(v.x * v.x + v.z * v.z));
		vout.x = cos(alpha - angle*pi/180) * cos(gamma) * sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		vout.z = sin(alpha - angle*pi/180) * cos(gamma) * sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		vout.y = v.y;
	}
	return vout;
}
tank::tank(){
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
//	printf("posicion tanque=%f %f %f, posicion torreta= %f %f %f, posicioncañon=%f %f %f, posiciondisparo= %f %f %f\n",position.x,position.y,position.z,turret_relativeposition.x, turret_relativeposition.y, turret_relativeposition.z,canonrotao.x,canonrotao.y,canonrotao.z,disparorotao.x,disparorotao.y,disparorotao.z);
	fire_absoluteposition = position + turret_relativeposition + rotatevector(cannon_relativeposition, turret_orientation)+rotatevector(fire_relativeposition,turret_orientation);
	fire_orientation = turret_orientation;
}
void tank::drawtank() {
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glPushMatrix();
	glColor3ub(0,255,255);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(hitboxradius*cos(i*2*pi/20),0,hitboxradius*sin(i * 2 * pi / 20));
	}
	glEnd();
	glColor3ub(255, 255, 255);
	glPopMatrix();
	glPushMatrix();
	glRotatef(body_orientation,0,1,0);
	draw(getbodymodel());
	glPopMatrix();
	glTranslatef(turret_relativeposition.x, turret_relativeposition.y, turret_relativeposition.z);
	glRotatef(turret_orientation, 0, 1, 0);
	draw(getturretmodel());
	glTranslatef(cannon_relativeposition.x, cannon_relativeposition.y, cannon_relativeposition.z);
	draw(getcannonmodel());
	glPopMatrix();
}
vector3D& tank::getposition() {
	return position;
}
void tank::keyactions(bool key[],float t) {
	if (key['w'] || key['W']) {
		position.x += statistics.speed * cos(body_orientation * 3.1415926535 / 180) * t;
		position.z += -statistics.speed * sin(body_orientation * 3.1415926535 / 180) * t;
	}
	if (key['a'] || key['A']) {
		body_orientation+=5;
	}
	if (key['s'] || key['S']) {
		position.x -= statistics.speed * cos(body_orientation * 3.1415926535 / 180) * t;
		position.z -= -statistics.speed * sin(body_orientation * 3.1415926535 / 180) * t;
	}
	if (key['d'] || key['D']) {
		body_orientation-=5;
	}
}
void tank::mouse(int mousepos[],bool mousekey[]) {
	if (orientation != NULL)
		turret_orientation=*orientation + atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535;
	else
		turret_orientation=atan2(400.0 - mousepos[0], 300.0 - mousepos[1]) * 180.0 / 3.1415926535;
}
char* tank::getbodymodel() {
	static char string[50];
	if (bodymodel == 1)strcpy(string, "./modelos3d/cuerpo1.txt");
	if (bodymodel == 2)strcpy(string, "./modelos3d/cuerpo2.txt");
	if (bodymodel == 3)strcpy(string, "./modelos3d/cuerpo3.txt");
	if (bodymodel == 4)strcpy(string, "./modelos3d/cuerpo4.txt");
	return string;
}
char* tank::getturretmodel() {
	static char string[50];
	if (turretmodel == 1)strcpy(string, "./modelos3d/torreta1.txt");
	if (turretmodel == 2)strcpy(string, "./modelos3d/torreta2.txt");
	if (turretmodel == 3)strcpy(string, "./modelos3d/torreta3.txt");
	if (turretmodel == 4)strcpy(string, "./modelos3d/torreta4.txt");
	return string;
}
char* tank::getcannonmodel() {
	static char string[50];
	if (cannonmodel == 1)strcpy(string, "./modelos3d/cannon1.txt");
	if (cannonmodel == 2)strcpy(string, "./modelos3d/cannon2.txt");
	if (cannonmodel == 3)strcpy(string, "./modelos3d/cannon3.txt");
	if (cannonmodel == 4)strcpy(string, "./modelos3d/cannon4.txt");
	return string;
}
vector3D tank::getfireposition() {
	return fire_absoluteposition;
}
float tank::getfireorientation() {
	return fire_orientation;
}