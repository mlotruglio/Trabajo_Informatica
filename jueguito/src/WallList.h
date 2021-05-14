#pragma once
#include "Wall.h"
#include "tank.h"
#define MAX_WALLS 100000
class WallList{
public:
	WallList();
	virtual ~WallList();
	bool add(Wall*);
	void drawwalls();
	void colision(tank& Tank);
	void loadmap();
private:
	int number;
	Wall* list[MAX_WALLS];
};
