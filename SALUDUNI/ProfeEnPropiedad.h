// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Profesor.h"

class ProfProp :public Profesor {
private:
	string codPlaza;
public:
	ProfProp(string nomU, string ID, string tit, int aL, string codP);
	virtual ~ProfProp();
	string getCodPla();
	void setCodPla(string codP);
	string toString();
};