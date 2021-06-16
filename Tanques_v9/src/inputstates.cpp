#include "inputstates.h"
inputstates::inputstates() {
	for (int i = 0; i < 255; i++) keystates[i] = 0;
	for (int i = 0; i < 4; i++) mousestates[i] = 0;
	mousepos[0] = 0;
	mousepos[1] = 0;
}
void inputstates::setkeystates(unsigned char key, bool state){
	keystates[key] = state;
}
bool* inputstates::getkeystates(){
	return keystates;
}
void inputstates::setmousestates(int key, bool state) {
	mousestates[key] = state;
}
bool* inputstates::getmousestates() {
	return mousestates;
}
void inputstates::setmousepos(int x, int y) {
	mousepos[0] = x;
	mousepos[1] = y;
}
int* inputstates::getmousepos() {
	return mousepos;
}