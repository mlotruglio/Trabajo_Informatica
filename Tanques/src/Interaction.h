#pragma once
#include "tank.h"
#include "wall.h"
#include "vector3D.h"
#include "Disparo.h"
#include "Enemigo.h"

class Interaction
{
	public:
	static void colision(tank& Tank, Wall wall);
	static void colision(Enemigo& Tank, Wall& wall);
	static bool colision(tank Tank, Disparo disparo);
	static bool colision(Enemigo Tank, Disparo disparo);
	static void choque(Enemigo& tank1, Enemigo& tank2);

	static void choque(tank& tank1, Enemigo& tank2);
	static bool colision(Disparo& disparo, Wall& wall);

};

