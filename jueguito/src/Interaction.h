#pragma once
#include "tank.h"
#include "wall.h"
#include "vector3D.h"
class Interaction
{
	public:
	static void colision(tank& Tank, Wall wall);
};

