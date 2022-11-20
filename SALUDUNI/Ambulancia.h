// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

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