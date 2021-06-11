#include "ListaSuelos.h"
#include "Interaction.h"
#include <stdio.h>
ListaSuelos::ListaSuelos() {
	number = 0;
	for (int i = 0; i < MAX_WALLS; i++)
		list[i] = 0;
}
ListaSuelos::~ListaSuelos() {}
bool ListaSuelos::add(Suelo* Suelo) {
	if (number < MAX_WALLS)
		list[number++] = Suelo;
	else
		return false;
	return true;
}
void ListaSuelos::drawsuelos() {
	for (int i = 0; i < number; i++) {
		list[i]->draw();
	}
}

Suelo* ListaSuelos::operator [](int i) {
	if (i >= number)
		if (i < 0)
			i = 0;
	return list[i];
}