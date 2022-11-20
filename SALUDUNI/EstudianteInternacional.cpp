#include"EstudianteInternacional.h"

EstInt::EstInt(string nomU, string ID, string cod, string niv, string nT, string nac, string cond) :Estudiante(nomU, ID, cod, niv, nT), nacionalidad(nac), condMigrat(cond) {}

EstInt::~EstInt() {}

void EstInt::setNac(string nac) { nacionalidad = nac; }

void EstInt::setCond(string cond) { condMigrat = cond; }

string EstInt::getNac() { return nacionalidad; }

string EstInt::getCond() { return condMigrat; }

string EstInt::toString() {
	stringstream s;
	s << Estudiante::toString() << endl;
	s << "Nacionalidad: " << nacionalidad << endl;
	s << "Condicion: " << condMigrat << endl;
	return s.str();
}
