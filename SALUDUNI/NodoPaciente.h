// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "EstudianteInternacional.h"
#include "EstudianteNacional.h"
#include "ProfeEnPropiedad.h"
#include "ProfeInterino.h"

class NodoPac {
private:
	NodoPac* siguiente;
	Paciente* paciente;
public:
	NodoPac();
	NodoPac(Paciente*, NodoPac*);
	virtual ~NodoPac();
	//----------------------------
	void setPaciente(Paciente*);
	void setSiguiente(NodoPac*);
	Paciente* getPaciente();
	NodoPac* getSiguiente();
};