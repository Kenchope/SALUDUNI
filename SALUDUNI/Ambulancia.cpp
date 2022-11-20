#include "Ambulancia.h"

Ambulancia::Ambulancia(string pla, string mar, string tV, double dis, int cod, bool ocp) :Transporte(pla, mar, tV, dis), codigo(cod), ocupacion(ocp) {}
Ambulancia::~Ambulancia() {}
void Ambulancia::setCodigo(int cod) { codigo = cod; }
void Ambulancia::setOcupacion(bool ocp) { ocupacion = ocp; }
int Ambulancia::getCodigo() { return codigo; }
bool Ambulancia::getOcupacion() { return ocupacion; }
string Ambulancia::toString() {
	stringstream s;
	s << Transporte::toString();
	s << "Codigo: " << codigo << endl;
	s << "Ocupacion: ";
	if (getOcupacion() == true)
		s << "OCUPADO." << endl;
	else
		s << "DISPONIBLE." << endl;
	s << "========================" << endl;
	return s.str();
}

int Ambulancia::getNumPas() { return -1; }
void Ambulancia::setNumPas(int){}