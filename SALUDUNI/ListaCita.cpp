#include "ListaCita.h"

ContCita::ContCita() { ppio = NULL; }

ContCita::~ContCita(){
	NodoCita* pExt = ppio;
	while (ppio != NULL) {
		ppio = pExt->getSiguiente();
		delete pExt;
		pExt = ppio;
	}
	ppio = NULL;
}

string ContCita::toString(){
	NodoCita* pExt = ppio;
	stringstream s;
	s << "Listado de Citas" << endl;
	while (pExt != NULL) {
		s << pExt->getCita()->toString() << endl;
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

//---------------------

void ContCita::agregaCita(Cita* ptr){
	NodoCita* pExt = ppio;
	NodoCita* nuevo = NULL;

	if (pExt == NULL) {
		ppio = new NodoCita(ptr, NULL);
	}
	else {
		while (pExt->getSiguiente() != NULL) {
			pExt = pExt->getSiguiente();
		}
		nuevo = new NodoCita(ptr, NULL);
		pExt->setSiguiente(nuevo);
	}
}
bool ContCita::eliminaCita(string cod){
	NodoCita* pExt = ppio;
	NodoCita* pAnt = NULL;


	if (pExt->getCita()->getCodigo() == cod) {
		ppio = pExt->getSiguiente();
		delete pExt;
		return true;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getCita()->getCodigo() == cod) {
				pAnt->setSiguiente(pExt->getSiguiente());
				delete pExt;
				return true;
			}
			else {
				pAnt = pExt;
				pExt = pExt->getSiguiente();
			}
		}
		return false;
	}
}
string ContCita::muestraCita(string cod){
	NodoCita* pExt = ppio;
	stringstream s;

	if (pExt->getCita()->getCodigo() == cod) {
		s << pExt->getCita()->toString() << endl;
		return s.str();
	}
	else {
		while (pExt != NULL) {
			if (pExt->getCita()->getCodigo() == cod) {
				s << pExt->getCita()->toString() << endl;
				return s.str();
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return s.str();
}
void ContCita::editaCita(string cod, int d, int m, int a, int h, int mi){
	NodoCita* pExt = ppio;

	if (pExt->getCita()->getCodigo() == cod) {  
		pExt->getCita()->getFec()->setDia(d);
		pExt->getCita()->getFec()->setMes(m);
		pExt->getCita()->getFec()->setAnn(a);
		//-----------------------------------
		pExt->getCita()->getHor()->setHor(h);
		pExt->getCita()->getHor()->setMin(m);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getCita()->getCodigo() == cod) {
				pExt->getCita()->getFec()->setDia(d);
				pExt->getCita()->getFec()->setMes(m);
				pExt->getCita()->getFec()->setAnn(a);
				//-----------------------------------
				pExt->getCita()->getHor()->setHor(h);
				pExt->getCita()->getHor()->setMin(m);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}
Cita* ContCita::retornaCita(string cod)	{
	NodoCita* pExt = ppio;
	Cita* ptr = NULL;
	if (pExt->getCita()->getCodigo() == cod) {
		ptr = pExt->getCita();
		return ptr;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getCita()->getCodigo() == cod) {
				ptr = pExt->getCita();
				return ptr;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return NULL;
}
//--------------------
string ContCita::citaPorPaciente(string ced){
	NodoCita* pExt = ppio;
	stringstream s;
	while (pExt != NULL) {
		if (pExt->getCita()->getPac()->getID() == ced) {
			s << pExt->getCita()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}
Paciente* ContCita::cuentaCitas(contPac* ptrL){
	Paciente* ptrP = NULL;
	NodoCita* pExt = ppio;
	NodoPac* pExtP = ptrL->getPpio();
	int cont = 0;
	int contAnt = 0;
	while (pExtP != NULL) {
		while (pExt != NULL) {
			if (pExt->getCita()->getPac()->getID() == pExtP->getPaciente()->getID()) {
				cont++;
			}
			pExt = pExt->getSiguiente();
			
		}
		if (contAnt < cont) {
			contAnt = cont;
			ptrP = pExtP->getPaciente();
		}
		pExtP->getPaciente()->setContCitas(cont);
		cont = 0;
		pExtP = pExtP->getSiguiente();
		pExt = ppio;
	}
	return ptrP;
}

Fecha* ContCita::FechaConMasPacientes(){
	Fecha* ptrF = NULL;
	NodoCita* pExt = ppio;
	NodoCita* pAux = ppio->getSiguiente();
	int cont = 0;
	int contAnt = 0;
	while (pAux != NULL) {
		while (pExt != NULL) {
			if (pExt->getCita()->getFec()->getDia() == pAux->getCita()->getFec()->getDia()
				&& pExt->getCita()->getFec()->getMes() == pAux->getCita()->getFec()->getMes()
				&& pExt->getCita()->getFec()->getAnio() == pAux->getCita()->getFec()->getAnio()) {
				cont++;
			}
			pExt = pExt->getSiguiente();

		}
		if (contAnt < cont) {
			contAnt = cont;
			ptrF = pAux->getCita()->getFec();
		}
		cont = 0;
		pAux = pAux->getSiguiente();
		pExt = ppio;
	}
	return ptrF;
}

int ContCita::cantTaxi() {
	NodoCita* pExt = ppio;
	int aux1 = 0;
	string tipo = typeid(*pExt->getCita()->getTra()).name();

	while (pExt != NULL) {
		string tipo = typeid(*pExt->getCita()->getTra()).name();
		if (tipo == "class Taxi") {
			aux1++;
			pExt = pExt->getSiguiente();
		}
	}
	return aux1;
}

int ContCita::cantAmb() {
	NodoCita* pExt = ppio;
	int aux1 = 0;
	string tipo = typeid(*pExt->getCita()->getTra()).name();

	while (pExt != NULL) {
		string tipo = typeid(*pExt->getCita()->getTra()).name();
		if (tipo == "class Ambulancia") {
			aux1++;
			pExt = pExt->getSiguiente();
		}
	}
	return aux1;
}

