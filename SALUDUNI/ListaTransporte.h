// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "NodoTransporte.h"

class ContTrans {
private:
	NodoTrans* ppio;
public:
	ContTrans();
	virtual ~ContTrans();
	
	string toString();
	string mostrarTaxis();
	string mostrarAmbulancias();
	string mostrarPorPlaca(string);

	void agregaTransporte(Transporte*);
	bool eliminaConPlaca(string);
	bool isEmpty();

	void editaAmbulancia(string pla, string mar, bool oc);
	void editaTaxi(string pla, string mar, int nP);

	string ambulanciasOcupadas();
	string mostrarDisponibles();
	double costoTotalTaxis();

	Transporte* retornaTransporte(string);
};