#include "mundo.h"
mundo::mundo(){
	camara.getobjectivedirection(tanque.getrefpositiondirection());
	tanque.setreforientationdirection(camara.getorientationdirection());
}
void mundo::refresh() {
	camara.refresh(estadosentradas.getkeystates());
	tanque.refresh(estadosentradas.getkeystates(),estadosentradas.getmousepos());
}
void mundo::draw() {
	camara.drawcamera();
	tanque.drawtank();
}
void mundo::key(unsigned char key, int x ,int y,bool state) {
	estadosentradas.setkeystates(key, state);
}
void mundo::mousemove(int x, int y) {
	estadosentradas.setmousepos(x, y);
}