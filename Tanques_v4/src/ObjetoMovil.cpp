#include "ObjetoMovil.h"

ObjetoMovil::ObjetoMovil() {
	velocidad = 0;
	radiohitbox = 1.5f;
	orientacion = 0;
	color.set(255, 255, 255);
}
void ObjetoMovil::refresh(float t) {
	posicion.x += velocidad * cos(orientacion * 3.1415926535 / 180) * t;
	posicion.z += -velocidad * sin(orientacion * 3.1415926535 / 180) * t;

}
