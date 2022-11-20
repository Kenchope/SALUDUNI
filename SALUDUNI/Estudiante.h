// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "Paciente.h"

class Estudiante :public Paciente {
protected:
	string codCarrera;
	string ultNivCursado;
	string numTel;
public:
	Estudiante(string, string, string, string, string);
	virtual ~Estudiante();
	virtual string toString();
	//----------------------------------------------
	void setCodCar(string);
	void setNivCursado(string);
	void setNumTel(string);
	//----------------------------------------------
	string getCodCar();
	string getUltNivCur();
	string getNumTel();

};