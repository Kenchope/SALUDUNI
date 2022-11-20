#include "Transporte.h"

Transporte::Transporte(string pla, string mar, string tV, double dis) :placa(pla), marca(mar), tipoViaje(tV), distancia(dis) {}
Transporte::Transporte() { placa = ""; marca = ""; tipoViaje = ""; distancia = 0.0; }
Transporte::~Transporte() {}
//Set
void Transporte::setPlaca(string pla) { placa = pla; }
void Transporte::setMarca(string mar) { marca = mar; }
void Transporte::setTipoViaje(string tV) { tipoViaje = tV; }
void Transporte::setDistancia(double dis) { distancia = dis; }
//Get
string Transporte::getPlaca() { return placa; }
string Transporte::getMarca() { return marca; }
string Transporte::getTipoViaje() { return tipoViaje; }
double Transporte::getDistancia() { return distancia; }
//Mostrar
string Transporte::toString() {
	stringstream s;
	s << "Placa:         " << placa << endl;
	s << "Marca:         " << marca << endl;
	s << "Tipo de Viaje: " << tipoViaje << endl;
	s << "Distancia:     " << distancia << endl;
	return s.str();

}
