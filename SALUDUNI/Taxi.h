// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

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
