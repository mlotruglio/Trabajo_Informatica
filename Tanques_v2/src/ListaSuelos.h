#pragma once
#include "Suelo.h"

#define MAX_WALLS 100000
class ListaSuelos {
public:
	ListaSuelos();
	virtual ~ListaSuelos();
	bool add(Suelo*);
	void drawsuelos();
	int getNumero() { return number; }
	Suelo* operator[](int i);
	//friend class ListaDisparos;
private:
	int number;
	Suelo* list[MAX_WALLS];
};
