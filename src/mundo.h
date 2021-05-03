#pragma once
#include "tank.h"
#include "inputstates.h"
#include "camera.h"
class mundo{
	tank tanque;
	inputstates estadosentradas;
	camera camara;
public:
	mundo();
	void refresh();
	void draw();
	void key(unsigned char key, int x, int y,bool state);
	void mousemove(int x, int y);
};