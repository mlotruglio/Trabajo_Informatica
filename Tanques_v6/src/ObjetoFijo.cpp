#include "ObjetoFijo.h"


ObjetoFijo::ObjetoFijo() {
	tamanio = 1.0f;
}
ObjetoFijo::ObjetoFijo(vector3D _posicion, float _tamanio) {
	posicion = _posicion;
	tamanio = _tamanio;
}
ObjetoFijo::ObjetoFijo(float _x, float _y, float _z, float _tamanio) {
	posicion.x = _x;
	posicion.y = _y;
	posicion.z = _z;
	tamanio = _tamanio;
}
void ObjetoFijo::setPosicion(float _x, float _y, float _z) { posicion.x = _x; posicion.y = _y; posicion.z = _z; }
void ObjetoFijo::setPosicion(vector3D _posicion) { posicion = _posicion; }
vector3D ObjetoFijo::getPosicion() { return posicion; }
void ObjetoFijo::setTamanio(float _tamanio) { tamanio = _tamanio; }
float ObjetoFijo::getTamanio() { return tamanio; }