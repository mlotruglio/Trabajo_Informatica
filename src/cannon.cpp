#include "cannon.h"
#include "draw.h"
#include "freeglut.h"
char* cannon::getmodel(int i) {
	char string[50];
	if (i == 1)strcpy(string, "./modelos3d/cannon1.txt");
	if (i == 2)strcpy(string, "./modelos3d/cannon2.txt");
	if (i == 3)strcpy(string, "./modelos3d/cannon3.txt");
	if (i == 4)strcpy(string, "./modelos3d/cannon4.txt");
	return string;
}
void cannon::drawcannon() {
	glPushMatrix();
	glColor3ub(color.red, color.green, color.blue);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 1, 0, 0);
	draw(getmodel(cannon_model));
	glPopMatrix();
}
void cannon::refresh(bool key[], int mousepos[]) {
//if pressed left click and minigun-> static float angularspeed++-->rotation+=angularspeed*fps-->else angularspeed--
	keyaction(key);
}
void cannon::keyaction(bool key[]) {
// esto se va cuando terminen las pruebas, hay que poner un algo para cambiar el modelo
	static bool lastkey[255];
	if ((key['2'] && !lastkey['2']))cannon_model=2;
	if ((key['1'] && !lastkey['1']))cannon_model = 1;
}
void cannon::mousemove(int mousepos[]) {}