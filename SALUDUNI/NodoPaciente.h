// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

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