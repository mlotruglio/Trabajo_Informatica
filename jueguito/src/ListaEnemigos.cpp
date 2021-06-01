#include "ListaEnemigos.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#define pi 3.14159265358979323846264
vector3D rotatevector(vector3D v, float angle) {
	vector3D vout;
	if (sqrt(v.x * v.x + v.y * v.y + v.z * v.z) != 0) {
		float alpha = -atan(v.z / v.x);
		float gamma = atan(v.y / sqrt(v.x * v.x + v.z * v.z));
		vout.x = cos(alpha - angle*pi/180) * cos(gamma) * sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		vout.z = sin(alpha - angle*pi/180) * cos(gamma) * sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		vout.y = v.y;
	}
	return vout;
}
ListaEnemigos::ListaEnemigos(){
	number = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		list[i] = 0;
	}
void ListaEnemigos::agregarEnemigos() 
{
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
				if (key == 'E') {

					Enemigo* aux = new Enemigo((float)-j, 0, (float)i, 1);
					add(aux);
				}
				i += 1;
				if (key == '\n' || key == EOF) {
					j += 1; i = 0;
				}
			}
		}
	
		}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}



void ListaEnemigos::rebote()
{
	for (int i = 0; i < numero - 1; i++)
		for (int j = i + 1; j < numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
}

void ListaEnemigos::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}



void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}

}


	
