#pragma once
#include "vector3D.h"
#define MAX 1000

template<typename T> class Lista {

public:
	Lista() {
		numero = 0;
		for (int i = 0; i < MAX; i++)
			lista[i] = 0;
	}
	bool add(T* _d) {
		if (_d != NULL) {
			for (int i = 0; i < numero; i++)
				if (lista[i] == _d) {
					return false;
				}
			if ((numero < MAX))
				lista[numero++] = _d;
			else
				return false;
			return true;
		}
		return false;
	}
	void dibuja(vector3D _posicion, float _radio) {
		for (int i = 0; i < numero; i++) {
			vector3D v = lista[i]->getPosicion() - _posicion;
			if (v.modulo() < _radio)
				lista[i]->dibuja();
		}
	}
	void destruirContenido() {
		for (int i = 0; i < numero; i++)
			delete lista[i];
		numero = 0;
	}
	void refresh(float _t) {
		for (int i = 0; i < numero; i++)
			lista[i]->refresh(_t);
	}
	void eliminar(int _index) {
		if ((_index < 0) || (_index >= numero))
			return;
		delete lista[_index];
		numero--;
		for (int i = _index; i < numero; i++)
			lista[i] = lista[i + 1];
	}
	void eliminar(T* _d) {
		for (int i = 0; i < numero; i++)
			if (lista[i] == _d)
			{
				eliminar(i);
				return;
			}
	}
	T* operator[](int _i) {
		if (_i >= numero)
			return lista[numero];
		if (_i <= 0)
			return lista[0];
		return lista[_i];
	}
	int getNumero() {
		return numero; 
	}
private:
	int numero;
	T* lista[MAX];
};

