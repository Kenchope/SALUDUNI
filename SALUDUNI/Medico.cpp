#include "Medico.h"

Medico::Medico() {
	cedula = "";
	nombre = "";
	numTelefono = "";
	apellido = "";
	especialidad = "";
}

Medico::Medico(string ced, string nom, string nT, string ape, string esp) {
	cedula = ced;
	nombre = nom;
	numTelefono = nT;
	apellido = ape;
	especialidad = esp;
}

Medico::~Medico() {}

//---------------------------------------------


void Medico::setCedula(string ced) { cedula = ced; }

void Medico::setNombre(string nom) { nombre = nom; }

void Medico::setApellido(string ape) { apellido = ape; }

void Medico::setNumTel(string nT) { numTelefono = nT; }

void Medico::setEspec(string esp) { especialidad = esp; }

//---------------------------------------------


string Medico::getCedula() { return cedula; }

string Medico::getNombre() { return nombre; }

string Medico::getApellido() { return apellido; }

string Medico::getNumTel() { return numTelefono; }

string Medico::getEspec() { return especialidad; }

//---------------------------------------------

string Medico::toString() {
	stringstream s;

	s << "------INFORMACION DEL MEDICO------" << endl;
	s << " Nombre: " << nombre << endl;
	s << " Apellido: " << apellido << endl;
	s << " Cedula: " << cedula << endl;
	s << " Numero de Telefono: " << numTelefono << endl;
	s << " Especialidad: " << especialidad << endl;
	s << "---------------------------------" << endl;

	return s.str();
}