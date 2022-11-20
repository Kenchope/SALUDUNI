// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#include <iostream>
#include <sstream>
using namespace std;


class Medico {
private:
	string cedula;
	string nombre;
	string numTelefono;
	string apellido;
	string especialidad;
public:
	Medico();
	Medico(string, string, string, string, string);
	virtual ~Medico();

	void setCedula(string);
	void setNombre(string);
	void setApellido(string);
	void setNumTel(string);
	void setEspec(string);

	string getCedula();
	string getNombre();
	string getApellido();
	string getNumTel();
	string getEspec();

	string toString();
};