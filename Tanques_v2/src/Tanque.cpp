#include "Tanque.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264

Tanque::Tanque() {
	orientacion = 0.0f;
	orientacion_torreta = 0.0f;
	velocidad = 0;
	posicion.y = 0.1;
}

/*Tanque::Tanque(){
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

void Tanque::setposition(float x, float y, float z){
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}
void Tanque::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}
void Tanque::setbodyorientationrel(float dir) {
	orientacion += dir;
}

void Tanque::setturretorientation(float dir) {
	orientacion_torreta= dir;
}

void Tanque::refresh(float t) {
	ObjetoMovil::refresh(t);
	velocidad= 0;
}
void Tanque::draw() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	//glColor3ub(0, 255, 255);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(radiohitbox * cos(i * 2 * pi / 20), 0, radiohitbox * sin(i * 2 * pi / 20));
	}
	glEnd();

	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(orientacion, 0, 1, 0);
	glTranslatef(radiohitbox * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radiohitbox * 0.05, radiohitbox * 0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(orientacion_torreta, 0, 1, 0);
	glTranslatef(radiohitbox * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(radiohitbox * 0.05, radiohitbox * 0.2, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
vector3D& Tanque::getposition() {
	return posicion;
}

void Tanque::setspeed(float v) {
	velocidad = v;
}

float Tanque::getturretorientation() {
	return orientacion_torreta;
}
