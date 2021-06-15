#include "ObjetoMovil.h"
ObjetoMovil::ObjetoMovil(vector3D _posicion, float _velocidad_max, float _orientacion, float _radiohitbox) {
	posicion = _posicion;
	velocidad_max = _velocidad_max;
	velocidad = 0;
	orientacion = _orientacion;
	radiohitbox = _radiohitbox;
	color.set(255, 255, 255);
}
ObjetoMovil::ObjetoMovil() {
	posicion.x = 0;
	posicion.y = 0;
	posicion.z = 0;
	velocidad_max = 10;
	velocidad = 0;
	radiohitbox = 1.5f;
	orientacion = 0;
	color.set(255, 255, 255);
}
void ObjetoMovil::refresh(float _t) {
	posicion.x += velocidad * cos(orientacion * 3.1415926535 / 180) * _t;
	posicion.z += -velocidad * sin(orientacion * 3.1415926535 / 180) * _t;

}

void ObjetoMovil::setPosicion(vector3D _posicion) { posicion = posicion; }
void ObjetoMovil::setPosicion(float _x, float _y, float _z) { posicion.x = _x; posicion.y = _y; posicion.z = _z; }
vector3D ObjetoMovil::getPosicion() {return posicion;}
vector3D& ObjetoMovil::getPunteroPosicion() { return posicion; }

void ObjetoMovil::setOrientacion(float _orientacion) { orientacion = _orientacion;}
float ObjetoMovil::getOrientacion() { return orientacion; }

void ObjetoMovil::setVelocidadMax(float _velocidad_max) { velocidad_max = _velocidad_max; }
float ObjetoMovil::getVelocidadMax() { return velocidad_max; }

void ObjetoMovil::setVelocidad(float _velocidad) { velocidad = _velocidad*velocidad_max; }
float ObjetoMovil::getVelocidad() { return velocidad; }

void ObjetoMovil::setRadiohitbox(float _radiohitbox) { radiohitbox = _radiohitbox; }
float ObjetoMovil::getRadiohitbox() { return radiohitbox; }

void ObjetoMovil::setColor(ColorRGB _color) { color = _color; }
void ObjetoMovil::setColor(Byte _r, Byte _g, Byte _b) { color.set(_r, _g, _b); }
ColorRGB ObjetoMovil::getColor() { return color; }