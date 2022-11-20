#include "SALUD-UNI.h"

SaludUni::SaludUni() {
	cedJur = "123456789";
	numTel = "2244-6688";
	direccion = "Campus-Omar-Dengo";
	nombre = "Hospital-Universitario";
	//--------------------------------
	conteMed = new ListaMedico();
	contePac = new contPac();
	conteTrans = new ContTrans();
	conteCitas = new ContCita();
}

SaludUni::~SaludUni(){
	if (conteMed != NULL) delete conteMed;
	if (contePac != NULL)delete contePac;
	if (conteTrans != NULL) delete conteTrans;
	if (conteCitas != NULL) delete conteCitas;
}

string SaludUni::toString() {
	stringstream s;
	s << "Cedula:    " << cedJur << endl;
	s << "Telefono:  " << numTel << endl;
	s << "Direccion: " << direccion << endl;
	s << "Nombre:    " << nombre << endl;
	return s.str();
}

ListaMedico* SaludUni::getListaMedico() {
	return conteMed;
}

contPac* SaludUni::getContPac() {
	return contePac;
}

ContTrans* SaludUni::getContTrans() {
	return conteTrans;
}

ContCita* SaludUni::getContCita() {
	return conteCitas;
}