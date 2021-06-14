#include "ObjetoMovil.h"
ObjetoMovil::ObjetoMovil(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox) {
	posicion = _posicion;
	velocidad = _velocidad;
	orientacion = _orientacion;
	radiohitbox = _radiohitbox;
	color.set(255, 255, 255);
}
ObjetoMovil::ObjetoMovil() {
	posicion.x = 0;
	posicion.y = 0;
	posicion.z = 0;
	velocidad = 0;
	radiohitbox = 1.5f;
	orientacion = 0;
	color.set(255, 255, 255);
}
void ObjetoMovil::refresh(float t) {
	posicion.x += velocidad * cos(orientacion * 3.1415926535 / 180) * t;
	posicion.z += -velocidad * sin(orientacion * 3.1415926535 / 180) * t;

}
void ObjetoMovil::setPosicion(vector3D _posicion) { posicion = posicion; }
void ObjetoMovil::setPosicion(float _x, float _y, float _z) { posicion.x = _x; posicion.y = _y; posicion.z = _z; }
vector3D ObjetoMovil::getPosicion() {return posicion;}
void ObjetoMovil::setOrientacion(float _orientacion) { orientacion = _orientacion;}
float ObjetoMovil::getOrientacion() { return orientacion; }
void ObjetoMovil::setVelocidad(float _velocidad) { velocidad = _velocidad; }
float ObjetoMovil::getVelocidad() { return velocidad; }
void ObjetoMovil::setColor(ColorRGB _color) { color = _color; }
void ObjetoMovil::setColor(Byte _r, Byte _g, Byte _b) { color.red = _r; color.green = _g; color.blue = _b; }
void ObjetoMovil::setRadiohitbox(float R) { radiohitbox = R; }
ColorRGB ObjetoMovil::getColor() { return color; }
float ObjetoMovil::getRadiohitbox() { return radiohitbox ; }