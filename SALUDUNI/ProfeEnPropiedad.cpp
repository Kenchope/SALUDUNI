#include "ProfeEnPropiedad.h"

ProfProp::ProfProp(string nomU, string ID, string tit, int aL, string codP) :Profesor(nomU, ID, tit, aL), codPlaza(codP) {}

ProfProp::~ProfProp() {}

string ProfProp::getCodPla() { return codPlaza; }

void ProfProp::setCodPla(string codP) { codPlaza = codP; }

string ProfProp::toString() {
	stringstream s;
	s << "-----------------------------------" << endl;
	s << Profesor::toString() << endl;
	s << "Codigo Plaza: " << codPlaza << endl;
	s << "-----------------------------------" << endl;
	return s.str();
}