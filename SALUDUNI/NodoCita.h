// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "Cita.h"

class NodoCita {
private:
	NodoCita* sig;
	Cita* citPt;
public:
	NodoCita();
	NodoCita(Cita*, NodoCita*);
	virtual ~NodoCita();
	//--------------------------
	void setSiguiente(NodoCita*);
	void setCita(Cita*);
	//--------------------------
	Cita* getCita();
	NodoCita* getSiguiente();
};