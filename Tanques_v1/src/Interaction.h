#pragma once
#include "Tanque.h"
#include "Pared.h"
#include "vector3D.h"
#include "Disparo.h"
#include "Enemigo.h"

class Interaction
{
	public:
	static void colision(Tanque& Tanque, Pared Pared);
	static void colision(Enemigo& Tanque, Pared& Pared);
	static bool colision(Tanque Tanque, Disparo disparo);
	static bool colision(Enemigo Tanque, Disparo disparo);
	static void choque(Enemigo& tank1, Enemigo& tank2);

	static void ataque(Tanque& tank1, Enemigo& tank2);

	static void choque(Tanque& tank1, Enemigo& tank2);
	static bool colision(Disparo& disparo, Pared& Pared);

};

