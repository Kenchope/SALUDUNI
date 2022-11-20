#include "Profesor.h"

Profesor::Profesor(string nomU, string ID, string tit, int aL) :Paciente(nomU, ID), titulo(tit), anniosLab(aL) {}

Profesor::~Profesor() {}

void Profesor::setTitulo(string tit) { titulo = tit; }

void Profesor::setAnnios(int aL) { anniosLab = aL; }

string Profesor::getTitulo() { return titulo; }

int Profesor::getAnnios() { return anniosLab; }

string Profesor::toString() {
	stringstream s;

	s << "-------------------------------------" << endl;
	s << Paciente::toString() << endl;
	s << "Titulo: " << titulo << endl;
	s << "Annios Laborados: " << anniosLab << endl;
	s << "-------------------------------------" << endl;
	return s.str();
}

int Profesor::getCalif() { return 0; }