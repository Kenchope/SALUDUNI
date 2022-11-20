// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "NodoCita.h"


class ContCita {
private: 
	NodoCita* ppio;
public:
	ContCita();
	virtual ~ContCita();
	string toString();		//Muestra todas las citas
	//---------------------
	void agregaCita(Cita* ptr);
	bool eliminaCita(string cod);
	string muestraCita(string cod);
	void editaCita(string cod, int, int, int, int, int);
	Cita* retornaCita(string);
	//--------------------
	string citaPorPaciente(string);
	Paciente* cuentaCitas(contPac*);
	Fecha* FechaConMasPacientes();

	int cantTaxi();
	int cantAmb();
	//-----------------------
};