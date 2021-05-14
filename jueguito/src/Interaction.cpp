#include "Interaction.h"
#include <math.h>
#define pi 3.14159265358979323846264
void Interaction::colision(tank& Tank, Wall wall) {
	vector3D v = Tank.position - wall.position;
	float aux = wall.side / 2 + Tank.hitboxradius;
		float alpha = atan2(v.x, v.z) * 180 / pi;
		if (alpha < 45 && alpha>-45) {
			if (aux > v.z)Tank.position.z =  wall.position.z+aux;
		}
		if (alpha > 45 && alpha < 135) {
			if (aux > v.x)Tank.position.x =  wall.position.x+aux;
		}
		if (alpha > -135 && alpha < -45) {
			if (aux > -v.x)Tank.position.x = wall.position.x -aux;
		}
		if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
			if (aux > -v.z)Tank.position.z = wall.position.z -aux;
		}
}