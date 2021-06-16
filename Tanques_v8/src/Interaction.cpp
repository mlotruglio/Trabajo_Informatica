#include "Interaction.h"
#include <math.h>
#include <stdio.h>
#define pi 3.1415926535897932384626433
#define distancia_ataque 25.0
void Interaction::colision(Tanque& Tanque, Pared Pared) {
	vector3D v = Tanque.posicion - Pared.posicion;
	float aux = Pared.tamanio / 2 + Tanque.radiohitbox;
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

bool Interaction::colision(Tanque Tanque, Disparo disparo) {

	vector3D d = (Tanque.posicion - disparo.posicion);

	if (d.modulo() < Tanque.radiohitbox + disparo.radiohitbox)
		return true;
	return false;
}

void Interaction::colision(Tanque& tank1, Tanque& tank2)
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

Disparo* Interaction::ataque(Tanque& tank1, Tanque& tank2) {
	vector3D d = (tank1.posicion - tank2.posicion);
	if (d.modulo() < distancia_ataque) {
		tank2.orientacion_torreta = tank2.orientacion = -atan2(d.z, d.x) * 180 / pi;
		tank2.setVelocidad(1);
		if (tank2.recarga <= 0) {
			Disparo* aux = new Disparo(tank2.getPosicion(), tank2.getVelocidadDisparo(),tank2.getOrientaciontorreta(),tank2.getRadiohitbox()*(0.2/1.5),10,2,tank2.getDanio());
			aux->setPosicion(aux->getPosicion().x, tank2.getRadiohitbox()*(1.4/1.5), aux->getPosicion().z);
			aux->setColor(tank2.getColor());
			aux->setVelocidad(1);
			tank2.resetRecarga();
			return aux;
		}
	}
	else tank2.setVelocidad(0);
	return NULL;
}


bool Interaction::colision(Disparo& disparo, Pared Pared) {
	vector3D v = disparo.posicion - (Pared.posicion);
	float aux = Pared.tamanio / 2 + disparo.radiohitbox;
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