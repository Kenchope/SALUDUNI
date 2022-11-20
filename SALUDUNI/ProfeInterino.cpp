#include "ProfeInterino.h"

ProfInte::ProfInte(string nomU, string ID, string tit, int aL, int cal) :Profesor(nomU, ID, tit, aL), calificacion(cal) {}

ProfInte::~ProfInte() {}

void ProfInte::setCalif(int cal) { calificacion = cal; }

int ProfInte::getCalif() { return calificacion; }

string ProfInte::toString() {
	stringstream s;
	s << "----------------------------" << endl;
	s << Profesor::toString() << endl;
	s << "Calificacion: " << calificacion << endl;
	s << "----------------------------" << endl;
	return s.str();
}