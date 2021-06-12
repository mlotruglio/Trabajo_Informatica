#pragma once
#include "Tanque.h"
#include "Pared.h"
#include "vector3D.h"
#include "Disparo.h"
#include "Tanque.h"

class Interaction
{
	public:
	static void colision(Tanque& Tanque, Pared Pared);
	static bool colision(Tanque Tanque, Disparo disparo);

	static Disparo* ataque(Tanque& tank1, Tanque& tank2);

	static void choque(Tanque& tank1, Tanque& tank2);
	static bool colision(Disparo& disparo, Pared& Pared);

};

