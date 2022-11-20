// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Ambulancia.h"
#include "Taxi.h"

class NodoTrans {
private:
	NodoTrans* siguiente;
	Transporte* ptrTra;
public:
	NodoTrans();
	NodoTrans(NodoTrans*, Transporte*);
	virtual ~NodoTrans();
	void setSiguiente(NodoTrans*);
	void setTransporte(Transporte*);
	NodoTrans* getSiguiente();
	Transporte* getTransporte();
};