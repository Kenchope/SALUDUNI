// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Transporte.h"

class Ambulancia : public Transporte {
private:
	int codigo;
	bool ocupacion;
public:
	Ambulancia(string, string, string, double, int, bool);
	virtual ~Ambulancia();
	void setCodigo(int);
	void setOcupacion(bool);
	int getCodigo();
	bool getOcupacion();
	string toString();
	int getNumPas();
	void setNumPas(int);

};