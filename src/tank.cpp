#include "tank.h"
#include "draw.h"
#include "freeglut.h"
#include <math.h>
char* tank::getmodel(int i) {
	char string[50];
	if (i == 1)strcpy(string, "./modelos3d/cuerpo1.txt");
	if (i == 2)strcpy(string, "./modelos3d/cuerpo2.txt");
	if (i == 3)strcpy(string, "./modelos3d/cuerpo3.txt");
	if (i == 4)strcpy(string, "./modelos3d/cuerpo4.txt");
	return string;
}
void tank::drawtank(){
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 0, 1, 0);
	draw(getmodel(body_model));
	glRotatef(-orientation, 0, 1, 0);
	turret.drawturret();
	glPopMatrix();
}
void tank::refresh(bool key[],int mousepos[]){
	// cambiar 0.25 por fps
	position.x+=speed.x*0.25*cos(orientation*3.1415926535/180);
	position.z+=-speed.x*0.25*sin(orientation * 3.1415926535 / 180);
	mousemove(mousepos);
	keyaction(key);
	turret.refresh(key, mousepos);
}
void tank::keyaction(bool key[]) {
	speed.x=0;
	if (key['w'] || key['W']) { speed.x += 1;}
	if (key['a'] || key['A']) { orientation+=5;}
	if (key['s'] || key['S']) { speed.x-=1;}
	if (key['d'] || key['D']) { orientation-=5;}
}
vector3D* tank::getrefpositiondirection() {
	return &position;
}
void tank::setreforientationdirection(float *orient) {
	reforientation = orient;
}
void tank::mousemove(int mousepos[]) {
	turret.setorientation(*reforientation+atan2(400.0-mousepos[0],300.0-mousepos[1])*180.0/3.1415926535);
}