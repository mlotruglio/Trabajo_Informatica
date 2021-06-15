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
	float vida_max;
	float danio;
public:
	Tanque(vector3D _posicion, float _velocidad_max, float _orientacion, float _radiohitbox = 1);
	Tanque(vector3D _posicion, float _velocidad_max = 0, float _orientacion = 0, float _radiohitbox = 1, float _vida_max=100,float _tiempo_recarga=1,float _danio=1);
	Tanque();

	void dibuja();
	void refresh(float);

	void setOrientaciontorreta(float);
	float getOrientaciontorreta();

	void setTiempoRecarga(float);

	void resetRecarga();
	float getRecarga();

	void setVida(float );
	float getVida();

	void setVidaMax(float);
	float getVidaMax();

	void setDanio(float);
	float getDanio();

	friend class Interaction;
};