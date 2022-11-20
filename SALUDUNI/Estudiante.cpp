#include "Estudiante.h"

Estudiante::Estudiante(string nomU, string ID, string cod, string nivC, string nT) :Paciente(nomU, ID), codCarrera(cod), ultNivCursado(nivC), numTel(nT) {}
Estudiante::~Estudiante() {}

void Estudiante::setCodCar(string cod) {
	codCarrera = cod;
}

void Estudiante::setNivCursado(string niv) {
	ultNivCursado = niv;
}

void Estudiante::setNumTel(string nT) {
	numTel = nT;
}

string Estudiante::getCodCar() { return codCarrera; }
string Estudiante::getUltNivCur() { return ultNivCursado; }
string Estudiante::getNumTel() { return numTel; }

string Estudiante::toString() {
	stringstream s;
	s << Paciente::toString() << endl;
	s << "Codigo de Carrera: " << codCarrera << endl;
	s << "Ultimo Nivel Cursado: " << ultNivCursado << endl;
	s << "Numero de Telefono: " << numTel << endl;
	return s.str();
}

