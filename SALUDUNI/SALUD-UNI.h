// Estudiantes:
// - Kenny Wanchope Rodr�guez id: 402610953
// - Santiago Sol�s Bola�os id: 118830321

#pragma once
#include "ListaCita.h"
#include "Costo.h"
class SaludUni {
private:
	string cedJur;
	string numTel;
	string direccion;
	string nombre;
	//--------------------
	ListaMedico* conteMed;
	contPac* contePac;
	ContTrans* conteTrans;
	//-------------------
	ContCita* conteCitas;
public:
	SaludUni();
	virtual ~SaludUni();
	string toString();
	//--------------------
	ListaMedico* getListaMedico();
	contPac* getContPac();
	ContTrans* getContTrans();
	ContCita* getContCita();

};