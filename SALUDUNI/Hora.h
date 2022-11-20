// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "Fecha.h"

class Hora {
private:
	int hor;
	int min;
public:
	Hora();
	Hora(int h, int m);
	virtual ~Hora();
	string toString();

	void setHor(int);
	void setMin(int);
};
