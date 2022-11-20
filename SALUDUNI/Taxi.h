// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Transporte.h"

class Taxi :public Transporte {
private:
	int numPas;
public:
	Taxi(string, string, string, double, int);
	virtual ~Taxi();
	//-------------------------------------------
	void setNumPas(int);
	int getNumPas();
	//-------------------------------------------
	string toString();

	bool getOcupacion();
	void setOcupacion(bool);
	int getCodigo();
};
