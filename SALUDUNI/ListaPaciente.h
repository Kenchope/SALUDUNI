// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "NodoPaciente.h"

class contPac {
private:
	NodoPac* ppio;
public:
	contPac();
	virtual ~contPac();
	string toString(); // muestra todo lo que hay en la lista
	bool isEmpty();
	NodoPac* getPpio();

	void agregaPaciente(Paciente*);
	bool eliminaConID(string);
	string mostrarConID(string);

	string listaExiliados();
	string mejorCalificacionInterinos();

	string mostrarProInt();
	string mostrarProEnProp();
	string mostrarEstNac();
	string mostrarEstInt();

	void editaPI(string ced, int aL, int cal);
	void editaPP(string ced, int aL, string cP);
	void editaEN(string ced, string est, string nT);
	void editaEI(string ced, string cond, string nT);
	
	Paciente* retornaPaciente(string);
}; 
