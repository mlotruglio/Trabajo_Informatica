#include "mundo.h"
#include <stdio.h>
mundo::mundo(){
	camara.getobjective(tanque.getposition());
	tanque.setorientation(camara.getorientation());
}
void mundo::refresh() {
	camara.refresh(estadosentradas.getkeystates());
	tanque.refresh(estadosentradas.getkeystates(),estadosentradas.getmousepos(),estadosentradas.getmousestates(),0.25);
}
void mundo::draw() {
	camara.drawcamera();
	tanque.drawtank();
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