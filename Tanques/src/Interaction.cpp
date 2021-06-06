#include "Interaction.h"
#include <math.h>
#include <stdio.h>
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
void Interaction::colision(Enemigo& Tank, Wall &wall) {
	vector3D v = Tank.position - wall.position;
	float aux = wall.side / 2 + Tank.hitboxradius;
	float alpha = atan2(v.x, v.z) * 180 / pi;
	if (alpha < 45 && alpha>-45) {
		if (aux > v.z)Tank.position.z = wall.position.z + aux;
	}
	if (alpha > 45 && alpha < 135) {
		if (aux > v.x)Tank.position.x = wall.position.x + aux;
	}
	if (alpha > -135 && alpha < -45) {
		if (aux > -v.x)Tank.position.x = wall.position.x - aux;
	}
	if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
		if (aux > -v.z)Tank.position.z = wall.position.z - aux;
	}
}

bool Interaction::colision(tank Tank, Disparo disparo) {

	vector3D d = (Tank.position - disparo.position);

	if (d.modulo() < Tank.hitboxradius + disparo.radio)
		return true;
	return false;
}
bool Interaction::colision(Enemigo Tank, Disparo disparo) {

	vector3D d = (Tank.position - disparo.position);

	if (d.modulo() < Tank.hitboxradius + disparo.radio)
		return true;
	return false;
}
void Interaction::choque(Enemigo& tank1, Enemigo& tank2)
{
	{
		vector3D d = (tank1.position - tank2.position);
		if (d.modulo() < tank1.hitboxradius + tank2.hitboxradius) {

			vector3D p = (tank1.position + tank2.position) / 2.0f;
			vector3D v = (tank1.position - tank2.position);

			tank1.position = p + v.unitario() * (tank1.hitboxradius + tank2.hitboxradius) / 2.0f;
			tank2.position = p - v.unitario() * (tank1.hitboxradius + tank2.hitboxradius) / 2.0f;
		}

	}

}
/*bool Interaction::colision(Wall& pared, Disparo& disparo) {
	vector3D v = disparo.position - (pared.position);
	float aux = pared.side / 2 + disparo.radio;
	if (aux > v.x || aux > -v.x || aux > v.z || aux > -v.z)
		return true;
	return false;
 }*/

void  Interaction::choque(tank& tank1, Enemigo& tank2) {
	vector3D d = (tank1.position - tank2.position);
	if (d.modulo() < tank1.hitboxradius + tank2.hitboxradius) {

		vector3D p = (tank1.position + tank2.position)/2.0f;
		vector3D v = (tank1.position - tank2.position);

		tank1.position = p + v.unitario() * (tank1.hitboxradius + tank2.hitboxradius)/2.0f;
		tank2.position = p - v.unitario() * (tank1.hitboxradius + tank2.hitboxradius) / 2.0f;
	}

}

bool Interaction::colision(Disparo& disparo, Wall& wall) {
	vector3D v = disparo.position - (wall.position);
	float aux = wall.side / 2 + disparo.radio;
	float alpha = atan2(v.x, v.z) * 180 / pi;
	if (alpha < 45 && alpha>-45) {
		if (aux > v.z) {
			disparo.position.z = wall.position.z + aux;
			disparo.orientation = -disparo.orientation;
			return true;
		}
	}
	if (alpha > 45 && alpha < 135) {
		if (aux > v.x){
			disparo.position.x = wall.position.x + aux;
			disparo.orientation =180 -disparo.orientation;
			return true;
		}
	}
	if (alpha > -135 && alpha < -45) {
		if (aux > -v.x){
			disparo.position.x = wall.position.x - aux;
			disparo.orientation = 180-disparo.orientation;
			return true;
		}
	}
	if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
		if (aux > -v.z) {
			disparo.position.z = wall.position.z - aux;
			disparo.orientation =-disparo.orientation;
			return true;
		}
	}
	return false;
}