#include "Cita.h"

Cita::Cita(Medico* med, Paciente* pac, Transporte* tra, Fecha* fec, Hora* hor, string cod):codigo(cod) , fecPtr(fec), horPtr(hor) {
	clonaMedico(med);
	clonaPaciente(pac);
	if(tra != NULL)
		clonaTransporte(tra);
}
Cita::~Cita(){}
string Cita::toString(){
	stringstream s;
	s << "INFORMACION DE LA CITA" << endl;
	s << "Codigo: " << codigo << endl;
	s << fecPtr->toString() << endl;
	s << horPtr->toString() << endl;
	s << "----------------------" << endl;
	s << "Informacion del medico: " << endl;
	s << "Doctor: " << medPtr->getNombre() << " " << medPtr->getApellido() << endl;
	s << "Cedula: " << medPtr->getCedula() << endl;
	s << "Especialidad: " << medPtr->getEspec() << endl;
	s << "----------------------" << endl;
	s << "Informacion del paciente: " << endl;
	s << "Cedula/Pasaporte: " << pacPtr->getID() << endl;
	s << "Universidad: " << pacPtr->getNomUni() << endl;
	s << "----------------------" << endl;
	if (traPtr != NULL) {
		s << "Informacion del transporte: " << endl;
		s << traPtr->toString() << endl;
	}
	else
		s << "----------------------" << endl;

	return s.str();
}
//----------------
void Cita::setMed(Medico* med) { medPtr = med; }
void Cita::setPac(Paciente* pac) { pacPtr = pac; }
void Cita::setTra(Transporte* tra) { traPtr = tra; }
void Cita::setFec(Fecha* fec) { fecPtr = fec; }
void Cita::setHora(Hora* hor) { horPtr = hor; }
void Cita::setCodigo(string cod) { codigo = cod;}
//-----------------
Medico* Cita::getMed() { return medPtr; }
Paciente* Cita::getPac() { return pacPtr; }
Transporte* Cita::getTra() { return traPtr; }
Fecha* Cita::getFec() { return fecPtr; }
Hora* Cita::getHor() { return horPtr; }
string Cita::getCodigo() { return codigo; }

void Cita::clonaPaciente(Paciente* paci) {
	string nomU, id, tit, codP, cod, niv, nT, est, nac, cond;
	int aL, cal;
	string tipo = typeid(*paci).name();

	if (tipo == "class EstInt") {
		nomU = paci->getNomUni();
		id = paci->getID();
		cod = paci->getCodCar();
		niv = paci->getUltNivCur();
		nT = paci->getNumTel();
		nac = paci->getNac();
		cond = paci->getCond();
		pacPtr = new EstInt(nomU, id, cod, niv, nT, nac, cond);
	}
	else if (tipo == "class EstNac") {
		nomU = paci->getNomUni();
		id = paci->getID();
		cod = paci->getCodCar();
		niv = paci->getUltNivCur();
		nT = paci->getNumTel();
		est = paci->getEstado();
		pacPtr = new EstNac(nomU, id, cod, niv, nT, est);
	}
	else if (tipo == "class ProfInte") {
		nomU = paci->getNomUni();
		id = paci->getID();
		tit = paci->getTitulo();
		aL = paci->getAnnios();
		cal = paci->getCalif();
		pacPtr = new ProfInte(nomU, id, tit, aL, cal);
	} 
	else if (tipo == "class ProfProp") {
		nomU = paci->getNomUni();
		id = paci->getID();
		tit = paci->getTitulo();
		aL = paci->getAnnios();
		codP = paci->getCodPla();
		pacPtr = new ProfProp(nomU, id, tit, aL, codP);
	}
}
void Cita::clonaMedico(Medico* medi) {
	string ced, nom, nT, ape, esp;
	ced = medi->getCedula();
	nom = medi->getNombre();
	nT = medi->getNumTel();
	ape = medi->getApellido();
	esp = medi->getEspec();
	medPtr = new Medico(ced, nom, nT, ape, esp);
}
void Cita::clonaTransporte(Transporte* tran) {
	string pla, mar, tV;
	double dis;
	int nP;
	int cod;
	char ocu;
	string tipo = typeid(*tran).name();

	if (tipo == "class Taxi") {
		pla = tran->getPlaca();
		mar = tran->getMarca();
		tV = tran->getTipoViaje();
		dis = tran->getDistancia();
		nP = tran->getNumPas();
		traPtr = new Taxi(pla, mar, tV, dis, nP);
	}
	else if (tipo == "class Ambulancia") {
		pla = tran->getPlaca();
		mar = tran->getMarca();
		tV = tran->getTipoViaje();
		dis = tran->getDistancia();
		ocu = tran->getOcupacion();
		cod = tran->getCodigo();
		traPtr = new Ambulancia(pla, mar, tV, dis, cod, ocu);
	}

}