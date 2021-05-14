#include "mundo.h"
#include <stdio.h>
#include "freeglut.h"
#include <time.h>
#include <stdio.h>
mundo::mundo(){
	camara.getobjective(tanque.getposition());
	tanque.setorientation(camara.getorientation());
	paredes.loadmap();
}
void mundo::refresh() {
	// para que esto funcione hay que poner publico walllist.number y inputstates.keystates
	//////////////////////////////////////////////////////////////
	/*
	static time_t lasttime;
	time(NULL);
	static int ticks;
	ticks += 1;
	if (lasttime != time(NULL)) {
		printf("fps=%d muros=%d\n", ticks,paredes.number);
		ticks = 0;
		lasttime = time(NULL);
	}
	if (estadosentradas.keystates[' ']) {
		vector3D pos = tanque.getposition();
		Wall* aux = new Wall((int)pos.x + 3, (int)pos.y, (int)pos.z, 1, 2);
		paredes.add(aux);
	}
	*/
	///  WALL LIST TIENE NUMBER EN PUBLICO
	/// ///////////////////////////////////////////////////////////////////////
	camara.refresh(estadosentradas.getkeystates());
	tanque.refresh(estadosentradas.getkeystates(),estadosentradas.getmousepos(),estadosentradas.getmousestates(),0.25);
	paredes.colision(tanque);
}
void mundo::draw() {
	camara.drawcamera();
	tanque.drawtank();
	paredes.drawwalls();
/*
	vector3D v = tanque.getfireposition();
	glPushMatrix();
	glTranslatef(v.x, v.y, v.z);
	glRotatef(90+tanque.getfireorientation(),0,1,0);
	glutSolidCone(0.05,0.4,10,10);
	glPopMatrix();
*/
}
void mundo::key(unsigned char key, int x ,int y,bool state) {
	estadosentradas.setkeystates(key, state);
}
void mundo::mouseclick(int button, int state) {
	estadosentradas.setmousestates(button, !state);
}
void mundo::mousemotion(int x, int y) {
	estadosentradas.setmousepos(x, y);
}
