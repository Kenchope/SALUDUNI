#include "Taxi.h"

Taxi::Taxi(string pla, string mar, string tV, double dis, int nP) :Transporte(pla, mar, tV, dis), numPas(nP) {}
Taxi::~Taxi() {}
//-------------------------------------------
void Taxi::setNumPas(int nP) { numPas = nP; }
int Taxi::getNumPas() { return numPas; }
//-------------------------------------------
string Taxi::toString() {
	stringstream s;
	s << Transporte::toString();
	s << "Numero de Pasajeros: " << numPas << endl;
	return s.str();
}

bool Taxi::getOcupacion() { return false; }
void Taxi::setOcupacion(bool){}
int Taxi::getCodigo() { return 0; }