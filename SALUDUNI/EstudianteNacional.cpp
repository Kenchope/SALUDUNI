#include "EstudianteNacional.h"

EstNac::EstNac(string nomU, string ID, string cod, string niv, string nT, string est) :Estudiante(nomU, ID, cod, niv, nT), estado(est) {}

EstNac::~EstNac() {}

void EstNac::setEstado(string est) { estado = est; }

string EstNac::getEstado() { return estado; }

string EstNac::toString() {
	stringstream s;

	s << Estudiante::toString() << endl;
	s << "Estado: " << estado << endl;

	return s.str();
}