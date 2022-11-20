// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "Medico.h"

class Fecha {
private:
	int dia;
	int mes;
	int ann;
public:
	Fecha(int d, int m, int a);
	Fecha();
	virtual ~Fecha();
	//-------------------------
	int getDia();
	int getMes();
	int getAnio();
	//-------------------------

	void setDia(int);
	void setMes(int);
	void setAnn(int);

	string toString();
};