#include "Paciente.h"

Paciente::Paciente() {
	nombreUniversidad = "";
	identificacion = "";
	contCitas = 0;
}

Paciente::Paciente(string nomUni, string id) {
	nombreUniversidad = nomUni;
	identificacion = id;
}

Paciente::~Paciente() {

}
//------------------------
void Paciente::setNomUni(string nomUni) {
	nombreUniversidad = nomUni;
}

void Paciente::setID(string id) {
	identificacion = id;
}
void Paciente::setContCitas(int c) {
	this->contCitas = c;
}
//------------------------
string Paciente::getNomUni() {
	return nombreUniversidad;
}

string Paciente::getID() {
	return identificacion;
}
int Paciente::getContCitas() {
	return this->contCitas;
}
//------------------------
string Paciente::toString() {
	stringstream s;
	s << "Identificacion: " << identificacion << endl;
	s << "Pertenece a: " << nombreUniversidad << endl;
	return s.str();
}

void Paciente::editaPaciente(){}
string Paciente::getTitulo() { return ""; }
void Paciente::setTitulo(){}
int Paciente::getAnnios() { return 0; }
void Paciente::setAnnios(int aL){}
int Paciente::getCalif(){ return 0; }
void Paciente::setCalif(int){}
string Paciente::getCodPla(){ return ""; }
void Paciente::setCodPla(string codP){}
void Paciente::setCodCar(string cod){}
string Paciente::getCodCar(){ return ""; }
string Paciente::getNumTel(){ return ""; }
void Paciente::setNumTel(string nT){}
void Paciente::setNivCursado(string niv){}
string Paciente::getUltNivCur(){ return ""; }
void Paciente::setEstado(string est){}
string Paciente::getEstado(){ return ""; }
string Paciente::getCond(){ return ""; }
void Paciente::setCond(string cond){}
void Paciente::setNac(string nac){}
string Paciente::getNac(){ return ""; }
