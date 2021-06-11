#include "Interaction.h"
#include <math.h>
#include <stdio.h>
#define pi 3.1415926535897932384626433
#define distancia_ataque 15.0
void Interaction::colision(Tanque& Tanque, Pared Pared) {
	vector3D v = Tanque.posicion - Pared.posicion;
	float aux = Pared.tamaño / 2 + Tanque.radiohitbox;
		float alpha = atan2(v.x, v.z) * 180 / pi;
		if (alpha < 45 && alpha>-45) {
			if (aux > v.z)Tanque.posicion.z =  Pared.posicion.z+aux;
		}
		if (alpha > 45 && alpha < 135) {
			if (aux > v.x)Tanque.posicion.x =  Pared.posicion.x+aux;
		}
		if (alpha > -135 && alpha < -45) {
			if (aux > -v.x)Tanque.posicion.x = Pared.posicion.x -aux;
		}
		if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
			if (aux > -v.z)Tanque.posicion.z = Pared.posicion.z -aux;
		}
}
void Interaction::colision(Enemigo& Tanque, Pared &Pared) {
	vector3D v = Tanque.posicion - Pared.posicion;
	float aux = Pared.tamaño / 2 + Tanque.radiohitbox;
	float alpha = atan2(v.x, v.z) * 180 / pi;
	if (alpha < 45 && alpha>-45) {
		if (aux > v.z)Tanque.posicion.z = Pared.posicion.z + aux;
	}
	if (alpha > 45 && alpha < 135) {
		if (aux > v.x)Tanque.posicion.x = Pared.posicion.x + aux;
	}
	if (alpha > -135 && alpha < -45) {
		if (aux > -v.x)Tanque.posicion.x = Pared.posicion.x - aux;
	}
	if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
		if (aux > -v.z)Tanque.posicion.z = Pared.posicion.z - aux;
	}
}

bool Interaction::colision(Tanque Tanque, Disparo disparo) {

	vector3D d = (Tanque.posicion - disparo.posicion);

	if (d.modulo() < Tanque.radiohitbox + disparo.radiohitbox)
		return true;
	return false;
}
bool Interaction::colision(Enemigo Tanque, Disparo disparo) {

	vector3D d = (Tanque.posicion - disparo.posicion);

	if (d.modulo() < Tanque.radiohitbox + disparo.radiohitbox)
		return true;
	return false;
}
void Interaction::choque(Enemigo& tank1, Enemigo& tank2)
{
	{
		vector3D d = (tank1.posicion - tank2.posicion);
		if (d.modulo() < tank1.radiohitbox + tank2.radiohitbox) {

			vector3D p = (tank1.posicion + tank2.posicion) / 2.0f;
			vector3D v = (tank1.posicion - tank2.posicion);

			tank1.posicion = p + v.unitario() * (tank1.radiohitbox + tank2.radiohitbox) / 2.0f;
			tank2.posicion = p - v.unitario() * (tank1.radiohitbox + tank2.radiohitbox) / 2.0f;
		}

	}

}

void Interaction::ataque(Tanque& tank1, Enemigo& tank2) {
	vector3D d = (tank1.posicion - tank2.posicion);
	if (d.modulo() < distancia_ataque) {
		tank2.orientacion_torreta = tank2.orientacion = -atan2(d.z, d.x) * 180 / pi;
		tank2.velocidad = 4.5f;
	}
	else tank2.velocidad = 0;
}

void  Interaction::choque(Tanque& tank1, Enemigo& tank2) {
	vector3D d = (tank1.posicion - tank2.posicion);
	if (d.modulo() < tank1.radiohitbox + tank2.radiohitbox) {

		vector3D p = (tank1.posicion + tank2.posicion)/2.0f;
		vector3D v = (tank1.posicion - tank2.posicion);

		tank1.posicion = p + v.unitario() * (tank1.radiohitbox + tank2.radiohitbox)/2.0f;
		tank2.posicion = p - v.unitario() * (tank1.radiohitbox + tank2.radiohitbox) / 2.0f;
	}

}

bool Interaction::colision(Disparo& disparo, Pared& Pared) {
	vector3D v = disparo.posicion - (Pared.posicion);
	float aux = Pared.tamaño / 2 + disparo.radiohitbox;
	float alpha = atan2(v.x, v.z) * 180 / pi;
	if (alpha < 45 && alpha>-45) {
		if (aux > v.z) {
			disparo.posicion.z = Pared.posicion.z + aux;
			disparo.orientacion = -disparo.orientacion;
			return true;
		}
	}
	if (alpha > 45 && alpha < 135) {
		if (aux > v.x){
			disparo.posicion.x = Pared.posicion.x + aux;
			disparo.orientacion =180 -disparo.orientacion;
			return true;
		}
	}
	if (alpha > -135 && alpha < -45) {
		if (aux > -v.x){
			disparo.posicion.x = Pared.posicion.x - aux;
			disparo.orientacion = 180-disparo.orientacion;
			return true;
		}
	}
	if (alpha < -135 && alpha>-180 || alpha < 180 && alpha>135) {
		if (aux > -v.z) {
			disparo.posicion.z = Pared.posicion.z - aux;
			disparo.orientacion =-disparo.orientacion;
			return true;
		}
	}
	return false;
}