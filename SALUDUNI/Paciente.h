// Estudiantes:
// - Kenny Wanchope Rodríguez id: 402610953
// - Santiago Solís Bolaños id: 118830321

#pragma once
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Paciente {
protected:
	string nombreUniversidad;
	string identificacion;
	int contCitas;
public:
	Paciente();
	Paciente(string, string);
	virtual ~Paciente();
	//------------------------
	void setNomUni(string);
	void setID(string);
	void setContCitas(int);
	//------------------------
	string getNomUni();
	string getID();
	int getContCitas();
	//-------Paciente---------
	virtual string toString();
	virtual void editaPaciente();
	//-------Profesor---------
	virtual string getTitulo();
	virtual void setTitulo();
	virtual int getAnnios();
	virtual void setAnnios(int aL);
	virtual int getCalif();
	virtual void setCalif(int);
	virtual string getCodPla();
	virtual void setCodPla(string codP);
	//-------Estudiante------
	virtual void setCodCar(string cod);
	virtual string getCodCar();
	virtual string getNumTel();
	virtual void setNumTel(string nT);
	virtual void setNivCursado(string niv);
	virtual string getUltNivCur();
	virtual void setEstado(string est);
	virtual string getEstado();
	virtual string getCond();
	virtual void setCond(string cond);
	virtual void setNac(string nac);
	virtual string getNac();
	

	

	

	

	

	
};