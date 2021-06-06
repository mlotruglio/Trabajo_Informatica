#include "mundo.h"
#include <stdio.h>
#include "freeglut.h"
#include <time.h>
#include <stdio.h>
#include <math.h>

mundo::mundo(){
	camara.getobjective(tanque.getposition());
	tanque.setorientation(camara.getorientation());
	paredes.loadmap();
}
void mundo::refresh() {
	tecla();
	raton();
	disparo.refresh(0.025f);
	camara.refresh(estadosentradas.getkeystates());
	tanque.refresh(0.025f);
	paredes.colision(tanque);
	enemigo.refresh(0.025f);
	Interaction::choque(tanque, enemigo);
	paredes.colision(enemigo);
	Interaction::colision(enemigo, disparo);
	//paredes.colision(disparo);

	for (int i = 0; i < disparos.getNumero() ; i++) {
		for (int j = 0; j < paredes.getNumero(); j++) {
			if (Interaction::colision(*disparos[i], *paredes[j])) {
				if(disparos[i]->setRebote())
					disparos.eliminar(disparos[i]);
			}
			if(disparos[i]->getTime()<=0)
				disparos.eliminar(disparos[i]);
		}
	}

	Disparo* aux = disparos.colision(enemigo);
	if (aux != 0) {//si alguna esfera ha chocado
		disparos.eliminar(aux);
	}
	disparos.mueve(0.025f);
}
void mundo::draw(){
	camara.drawcamera();
	tanque.drawtank();
	paredes.drawwalls();
	disparo.dibuja();
	enemigo.drawtank();
	disparos.draw();
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

void mundo::raton() {
		tanque.setturretorientation(tanque.getorientation() + atan2(400.0 - estadosentradas.getmousepos()[0], 300.0 - estadosentradas.getmousepos()[1]) * 180.0 / 3.1415926535) ;
		static bool lastclik[4];
		
		if (estadosentradas.getmousestates()[2] && !lastclik[2]) {
			Disparo* d = new Disparo();
			d->setPos(tanque.getposition());
			d->setOri(tanque.getturretorientation());
			d->setSpeed(5.0f);
			if (disparos.add(d))
				printf("True\n");
			else delete d;
			//estadosentradas.setmousestates(2,0);
		}
		for (int i = 0; i < 4; i++) lastclik[i] = estadosentradas.getmousestates()[i];
}

void mundo::tecla()
{
	tanque.setspeed(0.0f);
	static bool lastkey[255];
	if (estadosentradas.getkeystates()['w']|| estadosentradas.getkeystates()['W'])
		tanque.setspeed(5.0f);
	if (estadosentradas.getkeystates()['s'] || estadosentradas.getkeystates()['S'])
		tanque.setspeed(-5.0f);
	if (estadosentradas.getkeystates()['a'] || estadosentradas.getkeystates()['A'])
		tanque.setbodyorientationrel(2.0f);
	if (estadosentradas.getkeystates()['d'] || estadosentradas.getkeystates()['D'])
		tanque.setbodyorientationrel(-2.0f);
	if ((estadosentradas.getkeystates()['z'] && !lastkey['z']) || (estadosentradas.getkeystates()['Z'] && !lastkey['Z'])) camara.setorientationabs(0);
	if ((estadosentradas.getkeystates()['o'] && !lastkey['o']) || (estadosentradas.getkeystates()['O'] && !lastkey['O'])) { if (camara.getdistance() >= 10)camara.setdistancerel(-5); if(camara.getdistance() <10)camara.setdistanceabs(5); }
	if ((estadosentradas.getkeystates()['p'] && !lastkey['p']) || (estadosentradas.getkeystates()['P'] && !lastkey['P'])) { if (camara.getdistance() <= 25)camara.setdistancerel(5); if(camara.getdistance() >25) camara.setdistanceabs(30); }
	if (estadosentradas.getkeystates()['q'] || estadosentradas.getkeystates()['Q']) { camara.setorientationrel(+5); }
	if (estadosentradas.getkeystates()['e'] || estadosentradas.getkeystates()['E']) { camara.setorientationrel(-5); }
	for (int i = 0; i < 255; i++) lastkey[i] = estadosentradas.getkeystates()[i];
	
}

mundo::~mundo()
{
	disparos.destruirContenido();
}
