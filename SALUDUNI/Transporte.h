// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Transporte {
protected:
	string placa;
	string marca;
	string tipoViaje;
	double distancia;
public:
	//Constructor-Destructor
	Transporte(string, string, string, double);
	Transporte();
	virtual ~Transporte();
	//Set
	void setPlaca(string);
	void setMarca(string);
	void setTipoViaje(string);
	void setDistancia(double);
	//Get
	string getPlaca();
	string getMarca();
	string getTipoViaje();
	double getDistancia();
	//VIRTUAL 
	virtual string toString() = 0;
	virtual bool getOcupacion() = 0;
	virtual void setOcupacion(bool) = 0;
	virtual int getNumPas() = 0;
	virtual void setNumPas(int) = 0;
	virtual int getCodigo() = 0;
};