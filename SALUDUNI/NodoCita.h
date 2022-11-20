// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

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