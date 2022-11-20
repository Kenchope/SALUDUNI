#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) { dia = d; mes = m; ann = a; }
Fecha::Fecha() { dia = 0; mes = 0; ann = 0; }
Fecha::~Fecha(){}
//-------------------------
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return ann; }
//-------------------------
string Fecha::toString(){
	stringstream s;

	s << "Fecha: " << dia << "/" << mes << "/" << ann << endl;
	return s.str();
}

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnn(int a) { ann = a; }