#include "WallList.h"
#include "Interaction.h"
#include <stdio.h>
WallList::WallList(){
	number= 0;
	for (int i = 0; i < MAX_WALLS; i++)
		list[i] = 0;
}
WallList::~WallList() {}
bool WallList::add(Wall* wall) {
	if (number< MAX_WALLS)
		list[number++] = wall;
	else
		return false;
	return true;
}
void WallList::drawwalls(){
	for (int i = 0; i < number; i++)
		list[i]->drawwall();
}
void WallList::colision(tank& Tank) {
	for (int i = 0; i < number;i++) {
		Interaction::colision(Tank,*(list[i]));
	}
}
void WallList::colision(Enemigo& Tank) {
	for (int i = 0; i < number; i++) {
		Interaction::colision(Tank, *(list[i]));
	}
}
void WallList::colision(Disparo& disparo) {
	for (int i = 0; i < number; i++) {
		Interaction::colision(disparo, *(list[i]));
	}
}
void WallList::loadmap() {
	FILE* file = fopen("map.txt", "r");
	char key;
	int i = 0;
	int j = 0;
	if (file == NULL) {
		printf("hello");
	}
	else {
		while (!feof(file)) {
			fflush(file);
			fscanf(file, "%c", &key);
			if (key == 'O') {

				Wall* aux = new Wall((float)-j*2, 0, (float)i*2, 1*2, 2);
				add(aux);
			}
			i+=1;
			if (key == '\n'||key==EOF) {
				j += 1; i = 0;
			}
		}
	}
}

Wall* WallList::operator [](int i) {
	if (i >= number)
		if (i < 0)
			i = 0;
	return list[i];
}