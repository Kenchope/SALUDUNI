// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include "NodoMedico.h"

class ListaMedico {
private:
	NodoMed* ppio;
public:
	ListaMedico();
	virtual ~ListaMedico();
	//-------------------------
	bool isEmpty();
	string toString();
	//-------------------------
	void agregarMedico(Medico*);
	Medico* buscarMedicoCedula(string);
	string mostrarMedico(string);
	bool eliminaConCedula(string ced);
	//-------------------------
	void editarMedico(string, string, string);
};