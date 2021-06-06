#include "ListaDisparos.h"

ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		list[i] = 0;
}
ListaDisparos::~ListaDisparos() {}

bool ListaDisparos::add(Disparo* d) {
	int control = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		if (list[i] == d) {
			control++;
			return false;
		}

	if ((numero < MAX_DISPAROS) && (control == 0))
		list[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}
void ListaDisparos::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete list[i];
	numero = 0; // inicializa lista 
}
void ListaDisparos::draw() {
	for (int i = 0; i < numero; i++)
		list[i]->dibuja();
}
void ListaDisparos::refresh(float t) {
	for (int i = 0; i < numero; i++)
		list[i]->refresh(t);
}


Disparo* ListaDisparos::operator [](int i) {
	if (i >= numero)
		if (i < 0)
			i = 0;
	return list[i];
}

Disparo* ListaDisparos::colision(tank& Tank) {
	for (int i = 0; i < numero; i++)
	{
		if (Interaction::colision(Tank, *(list[i])))
				return list[i];
	}
	return 0; //no hay colisión
}
Disparo* ListaDisparos::colision(Enemigo& Tank) {
	for (int i = 0; i < numero; i++)
	{
		if (Interaction::colision(Tank, *list[i]))
			return list[i];
	}
	return 0; //no hay colisión
}
/*Disparo* ListaDisparos::contador(Disparo*d) {
	for (int i = 0; i < numero; i++)
	{
		if (d == list[i]) {
			if (Disparo::setRebote(*list[i]))
				return list[i];
		}
	}
	return 0;
}*/

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete list[index];
	numero--;
	for (int i = index; i < numero; i++)
		list[i] = list[i + 1];
}
void ListaDisparos::eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (list[i] == d)
		{
			eliminar(i);
			return;
		}
}
