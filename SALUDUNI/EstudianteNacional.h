// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "Estudiante.h"

class EstNac :public Estudiante {
private:
	string estado;
public:
	EstNac(string, string, string, string, string, string);
	virtual ~EstNac();
	void setEstado(string);
	string getEstado();
	string toString();
};