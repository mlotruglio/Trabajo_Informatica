#include "ObjetoFijo.h"
#include <cstring>

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

char* ObjetoFijo::getTextura() {
	static char string[50];
	if (texturas == none)strcpy(string, "imagenes/texturas/none.png");
	if (texturas == stone_bricks)strcpy(string, "imagenes/texturas/stone_bricks.png");
	if (texturas == grass)strcpy(string, "imagenes/texturas/grass.png");
	if (texturas == sand)strcpy(string, "imagenes/texturas/sand.png");
	if (texturas == spruce_log)strcpy(string, "imagenes/texturas/spruce_log.png");
	if (texturas == oak_planks)strcpy(string, "imagenes/texturas/oak_planks.png");
	if (texturas == cobblestone)strcpy(string, "imagenes/texturas/cobblestone.png");
	if (texturas == mossy_cobblestone)strcpy(string, "imagenes/texturas/mossy_cobblestone.png");
	if (texturas == coarse_dirt)strcpy(string, "imagenes/texturas/coarse_dirt.png");
	return string;
}
void ObjetoFijo::setPosicion(float _x, float _y, float _z) { posicion.x = _x; posicion.y = _y; posicion.z = _z; }
void ObjetoFijo::setPosicion(vector3D _posicion) { posicion = _posicion; }
vector3D ObjetoFijo::getPosicion() { return posicion; }
void ObjetoFijo::setTamanio(float _tamanio) { tamanio = _tamanio; }
float ObjetoFijo::getTamanio() { return tamanio; }
