// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Medico.h"

class NodoMed {
private:
	Medico* medPtr;
	NodoMed* sig;
public:
	NodoMed();
	NodoMed(Medico*, NodoMed*);
	virtual ~NodoMed();
	//---------------------
	Medico* getMedico();
	NodoMed* getSiguiente();
	//---------------------
	void setMedico(Medico*);
	void setSiguiente(NodoMed*);
};