// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "ListaPaciente.h"
#include "ListaMedico.h"
#include "ListaTransporte.h"
#include "Fecha.h"
#include "Hora.h"

class Cita {
private:
	Medico* medPtr;
	Paciente* pacPtr;
	Transporte* traPtr;
	Fecha* fecPtr;
	Hora* horPtr;
	string codigo;
public:
	Cita(Medico*, Paciente*, Transporte*, Fecha*, Hora*, string);
	virtual ~Cita();
	string toString();
	//----------------
	void setMed(Medico*);
	void setPac(Paciente*);
	void setTra(Transporte*);
	void setFec(Fecha*);
	void setHora(Hora*);
	void setCodigo(string);
	//-----------------
	Medico* getMed();
	Paciente* getPac();
	Transporte* getTra();
	Fecha* getFec();
	Hora* getHor();
	string getCodigo();
	//-----------------
	void clonaPaciente(Paciente*);
	void clonaMedico(Medico*);
	void clonaTransporte(Transporte*);
};