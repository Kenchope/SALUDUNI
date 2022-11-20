// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Paciente.h"

class Profesor : public Paciente {
protected:
	string titulo;
	int anniosLab;
public:
	Profesor(string, string, string, int);
	virtual ~Profesor();
	void setTitulo(string);
	void setAnnios(int);
	string getTitulo();
	int getAnnios();
	string toString();
	//------------------------------
	virtual int getCalif();
	
};