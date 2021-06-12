#include "draw.h"
#include <afx.h>
#include "freeglut.h"
#include <stdio.h>
#include <cstring>
#include <math.h>



void dibuja::draw(const char* filename, float scale) {
	FILE* file;
	char string[250];
	file = fopen(filename, "r");
	if (file == NULL) {
		printf("error abriendo el archivo %s\n", filename);
	}
	else {
			while (!feof(file)) {
				fflush(file);
				fgets(string, 250, file);
				if (strstr(string, "cube") != NULL) {
					//cube size pos_x pos_y pos_Z roll pitch yaw (deg) (roll around y, pitch around x, yaw around z)
					char aux[15];
					float size, pos_x, pos_y, pos_z, roll, pitch, yaw;
					sscanf(string, "%s %f %f %f %f %f %f %f", aux, &size, &pos_x, &pos_y, &pos_z, &roll, &pitch, &yaw);
					glPushMatrix();
					glTranslatef(pos_x*scale, pos_y*scale, pos_z*scale);
					glRotatef(yaw, 0, 0, 1);
					glRotatef(pitch, 1, 0, 0);
					glRotatef(roll, 0, 1, 0);
					glutSolidCube(size*scale);
					glPopMatrix();
				}
				if (strstr(string, "sphere") != NULL) {
					// sphere radius position
					char aux[15];
					float radius, pos_x, pos_y, pos_z;
					sscanf(string, "%s %f %f %f %f", aux, &radius, &pos_x, &pos_y, &pos_z);
					glPushMatrix();
					glTranslatef(pos_x*scale, pos_y*scale, pos_z*scale);
					glutSolidSphere(radius*scale, 20, 20);
					glPopMatrix();
				}
				if (strstr(string, "cone") != NULL) {
					//cone base height pos_x pos_y pos_Z pitch yaw (deg) (pitch around x, yaw around z)
					char aux[15];
					float base, height, pos_x, pos_y, pos_z, pitch, yaw;
					sscanf(string, "%s %f %f %f %f %f %f %f", aux, &base, &height, &pos_x, &pos_y, &pos_z, &pitch, &yaw);
					glPushMatrix();
					glTranslatef(pos_x*scale, pos_y * scale, pos_z * scale);
					glRotatef(pitch - 90, 1, 0, 0);
					glRotatef(yaw, 0, 0, 1);
					glutSolidCone(base * scale, height * scale, 20, 20);
					glPopMatrix();
				}
				if (strstr(string, "cylinder") != NULL) {
					//cylinder base height pos_x pos_y pos_Z pitch yaw (deg) (pitch around x, yaw around z)
					char aux[15];
					float base, height, pos_x, pos_y, pos_z, pitch, yaw;
					sscanf(string, "%s %f %f %f %f %f %f %f", aux, &base, &height, &pos_x, &pos_y, &pos_z, &pitch, &yaw);
					glPushMatrix();
					glTranslatef(pos_x * scale, pos_y * scale, pos_z * scale);
					glRotatef(-90, 1, 0, 0);
					glRotatef(pitch, 0, 1, 0);
					glRotatef(yaw, 0, 0, 1);
					GLUquadricObj* quadratic;
					quadratic = gluNewQuadric();
					gluCylinder(quadratic, base * scale, base * scale, height * scale, 20, 20);
					glPopMatrix();
				}
				if (strstr(string, "rectangle") != NULL) {
					//rectangle pos1_x pos1_y pos1_z pos2_x pos2_y pos2_z pos3_x pos3_y pos3_z
					char aux[15];
					float pos1_x, pos1_y, pos1_z, pos2_x, pos2_y, pos2_z, pos3_x, pos3_y, pos3_z;
					sscanf(string, "%s %f %f %f %f %f %f %f %f %f", aux, &pos1_x, &pos1_y, &pos1_z, &pos2_x, &pos2_y, &pos2_z, &pos3_x, &pos3_y, &pos3_z);
					float x1 = pos2_x - pos1_x;
					float y1 = pos2_y - pos1_y;
					float z1 = pos2_z - pos1_z;
					float x2 = pos3_x - pos2_x;
					float y2 = pos3_y - pos2_y;
					float z2 = pos3_z - pos2_z;
					float n1 = y1 * z2 - y2 * z1;
					float n2 = z1 * x2 - x1 * z2;
					float n3 = x1 * y2 - x2 * y1;
					float mod = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
					glBegin(GL_POLYGON);
					glNormal3f(n1 / mod, n2 / mod, n3 / mod);
					glVertex3f(pos1_x * scale, pos1_y * scale, pos1_z * scale);
					glVertex3f(pos2_x * scale, pos2_y * scale, pos2_z * scale);
					glVertex3f(pos3_x * scale, pos3_y * scale, pos3_z * scale);
					glVertex3f((pos1_x + pos3_x - pos2_x) * scale, (pos1_y + pos3_y - pos2_y) * scale, (pos1_z + pos3_z - pos2_z) * scale);
					glEnd();
				}
				if (strstr(string, "triangle") != NULL) {
					//triangle pos1_x pos1_y pos1_z pos2_x pos2_y pos2_z pos3_x pos3_y pos3_z
					char aux[15];
					float pos1_x, pos1_y, pos1_z, pos2_x, pos2_y, pos2_z, pos3_x, pos3_y, pos3_z;
					sscanf(string, "%s %f %f %f %f %f %f %f %f %f", aux, &pos1_x, &pos1_y, &pos1_z, &pos2_x, &pos2_y, &pos2_z, &pos3_x, &pos3_y, &pos3_z);
					float x1 = pos2_x - pos1_x;
					float y1 = pos2_y - pos1_y;
					float z1 = pos2_z - pos1_z;
					float x2 = pos3_x - pos2_x;
					float y2 = pos3_y - pos2_y;
					float z2 = pos3_z - pos2_z;
					float n1 = y1 * z2 - y2 * z1;
					float n2 = z1 * x2 - x1 * z2;
					float n3 = x1 * y2 - x2 * y1;
					float mod = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
					glBegin(GL_POLYGON);
					glNormal3f(n1 / mod, n2 / mod, n3 / mod);
					glVertex3f(pos1_x * scale, pos1_y * scale, pos1_z * scale);
					glVertex3f(pos2_x * scale, pos2_y * scale, pos2_z * scale);
					glVertex3f(pos3_x * scale, pos3_y * scale, pos3_z * scale);
					glEnd();
				}
				if (strstr(string, "circle") != NULL) {
					//circle radius pos_x pos_y pos_Z normal_x normal_y normal_z
					char aux[15];
					float radius, pos_x, pos_y, pos_z, n_x, n_y, n_z;
					int slices = 20;
					float pi = 3.14159265358979323846264;
					sscanf(string, "%s %f %f %f %f %f %f %f", aux, &radius, &pos_x, &pos_y, &pos_z, &n_x, &n_y, &n_z);
					glPushMatrix();
					glTranslatef(pos_x* scale, pos_y* scale, pos_z* scale);
					if (n_y != 0 && n_z != 0)
						glRotatef(-atan(n_y / n_z) * 180 / pi, 1, 0, 0);
					glRotatef(atan(n_x / sqrt(n_z * n_z + n_y * n_y)) * 180 / pi, 0, 1, 0);
					glBegin(GL_POLYGON);
					glNormal3f(n_x, n_y, n_z);
					for (int i = 0; i < slices; i++) {
						glVertex2f(radius * cos(2.0 * pi / slices * i)* scale, radius * sin(2 * 3.14159265358979323846264 / slices * i)* scale);
					}
					glEnd();
					glPopMatrix();
				}
				if (strstr(string, "4polygon") != NULL) {
					//rectangle pos1_x pos1_y pos1_z pos2_x pos2_y pos2_z pos3_x pos3_y pos3_z
					char aux[15];
					float pos1_x, pos1_y, pos1_z, pos2_x, pos2_y, pos2_z, pos3_x, pos3_y, pos3_z, pos4_x, pos4_y, pos4_z;
					sscanf(string, "%s %f %f %f %f %f %f %f %f %f %f %f %f", aux, &pos1_x, &pos1_y, &pos1_z, &pos2_x, &pos2_y, &pos2_z, &pos3_x, &pos3_y, &pos3_z, &pos4_x, &pos4_y, &pos4_z);
					float x1 = pos2_x - pos1_x;
					float y1 = pos2_y - pos1_y;
					float z1 = pos2_z - pos1_z;
					float x2 = pos3_x - pos2_x;
					float y2 = pos3_y - pos2_y;
					float z2 = pos3_z - pos2_z;
					float n1 = y1 * z2 - y2 * z1;
					float n2 = z1 * x2 - x1 * z2;
					float n3 = x1 * y2 - x2 * y1;
					float mod = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
					glBegin(GL_POLYGON);
					glNormal3f(n1 / mod, n2 / mod, n3 / mod);
					glVertex3f(pos1_x* scale, pos1_y* scale, pos1_z* scale);
					glVertex3f(pos2_x* scale, pos2_y* scale, pos2_z* scale);
					glVertex3f(pos3_x* scale, pos3_y* scale, pos3_z* scale);
					glVertex3f(pos4_x * scale, pos4_y * scale, pos4_z * scale);
					glEnd();
				}
			}
			fclose(file);
	}
}