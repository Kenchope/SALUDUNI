// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "Profesor.h"

class ProfInte :public Profesor {
private:
	int calificacion;
public:
	ProfInte(string nomU, string ID, string tit, int aL, int cal);
	virtual ~ProfInte();
	void setCalif(int);
	int getCalif();
	string toString();
};
