#include "ListaParedes.h"
#include "Interaction.h"
#include <stdio.h>
ListaParedes::ListaParedes(){
	number= 0;
	for (int i = 0; i < MAX_WALLS; i++)
		list[i] = 0;
}
ListaParedes::~ListaParedes() {}
bool ListaParedes::add(Pared* Pared) {
	if (number< MAX_WALLS)
		list[number++] = Pared;
	else
		return false;
	return true;
}
void ListaParedes::drawwalls(){
	for (int i = 0; i < number; i++)
		list[i]->draw();
}
void ListaParedes::colision(Tanque& Tanque) {
	for (int i = 0; i < number;i++) {
		Interaction::colision(Tanque,*(list[i]));
	}
}
void ListaParedes::colision(Enemigo& Tanque) {
	for (int i = 0; i < number; i++) {
		Interaction::colision(Tanque, *(list[i]));
	}
}
void ListaParedes::colision(Disparo& disparo) {
	for (int i = 0; i < number; i++) {
		Interaction::colision(disparo, *(list[i]));
	}
}

Pared* ListaParedes::operator [](int i) {
	if (i >= number)
		if (i < 0)
			i = 0;
	return list[i];
}