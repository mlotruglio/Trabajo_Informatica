#pragma once
#include "vector3D.h"
#include "ObjetoMovil.h"

class Tanque:public ObjetoMovil
{
private:
	float orientacion_torreta;
	float tiempo_recarga;
	float recarga;
	float vida;
public:
	Tanque(vector3D _posicion, float _velocidad, float _orientacion, float _radiohitbox = 1);
	Tanque(vector3D _posicion, float _velocidad = 0, float _orientacion = 0, float _radiohitbox = 1, float _vida=100,float _tiempo_recarga=1);
	Tanque();
	void dibuja();
	void refresh(float);
	vector3D& getPunteroPosicion();
	void resetRecarga();
	void setTiempoRecarga(float);
	float getRecarga();
	void setVida(float );
	float getVida();
	void setOrientaciontorreta(float);
	float getOrientaciontorreta();

	friend class Interaction;
};