// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Estudiante.h"

class EstInt :public Estudiante {
private:
	string nacionalidad;
	string condMigrat;
public:
	EstInt(string nomU, string ID, string cod, string niv, string nT, string nac, string cond);
	virtual ~EstInt();
	void setNac(string);
	void setCond(string);
	string getNac();
	string getCond();
	string toString();
};