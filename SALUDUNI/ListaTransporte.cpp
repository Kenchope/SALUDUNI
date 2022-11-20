#include "ListaTransporte.h"
#include "Costo.h"

ContTrans::ContTrans() { ppio = NULL; }
ContTrans::~ContTrans(){
	NodoTrans* pExt = ppio;
	while (ppio != NULL) {
		ppio = pExt->getSiguiente();
		delete pExt;
		pExt = ppio;
	}
	ppio = NULL;
}

string ContTrans::toString(){
	stringstream s;
	NodoTrans* pExt = ppio;
	s << "LISTADO DE TRANSPORTES" << endl;
	while (pExt != NULL) {
		s << pExt->getTransporte()->toString() << endl;
		pExt = pExt->getSiguiente();
	}
	s << "------------------------" << endl;
	return s.str();
}
string ContTrans::mostrarTaxis(){
	NodoTrans* pExt = ppio;
	stringstream s;
	string tipo = typeid(*pExt->getTransporte()).name();
	Cobro* cob = new Cobro();

	while (pExt != NULL) {
		if (tipo == "class Taxi") {
			s << pExt->getTransporte()->toString() << endl;
			s << cob->calcularTotalD(pExt->getTransporte()) << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}
string ContTrans::mostrarAmbulancias(){
	NodoTrans* pExt = ppio;
	stringstream s;
	string tipo = typeid(*pExt->getTransporte()).name();
	while (pExt != NULL) {
		if (tipo == "class Ambulancia") {
			s << pExt->getTransporte()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}
string ContTrans::mostrarPorPlaca(string pla){
	NodoTrans* pExt = ppio;
	stringstream s;

	if (pExt->getTransporte()->getPlaca() == pla) {
		s << pExt->getTransporte()->toString() << endl;
		return s.str();
	}
	else {
		while (pExt != NULL) {
			if (pExt->getTransporte()->getPlaca() == pla) {
				s << pExt->getTransporte()->toString() << endl;
				return s.str();
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return s.str();
}

void ContTrans::agregaTransporte(Transporte* ptr) {
	NodoTrans* pExt = ppio;
	NodoTrans* nuevo = NULL;
	if (pExt == NULL) {
		ppio = new NodoTrans(NULL, ptr);
	}
	else {
		while (pExt->getSiguiente() != NULL) {
			pExt = pExt->getSiguiente();
		}
		nuevo = new NodoTrans(NULL, ptr);
		pExt->setSiguiente(nuevo);
	}
}

bool ContTrans::eliminaConPlaca(string pla){
	NodoTrans* pExt = ppio;
	NodoTrans* pAnt = NULL;
	if (pExt->getTransporte()->getPlaca() == pla) {
		ppio = pExt->getSiguiente();
		delete pExt;
		return true;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getTransporte()->getPlaca() == pla) {
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

bool ContTrans::isEmpty() {
	if (ppio == NULL)
		return true;
	else {
		return false;
	}
}


void ContTrans::editaAmbulancia(string pla, string mar, bool oc){
	NodoTrans* pExt = ppio;
	if (pExt->getTransporte()->getPlaca() == pla){  
		pExt->getTransporte()->setMarca(mar);
		pExt->getTransporte()->setOcupacion(oc);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getTransporte()->getPlaca() == pla) {
				pExt->getTransporte()->setMarca(mar);
				pExt->getTransporte()->setOcupacion(oc);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}

}
void ContTrans::editaTaxi(string pla, string mar, int nP){
	NodoTrans* pExt = ppio;
	if (pExt->getTransporte()->getPlaca() == pla) {
		pExt->getTransporte()->setMarca(mar);
		pExt->getTransporte()->setNumPas(nP);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getTransporte()->getPlaca() == pla) {
				pExt->getTransporte()->setMarca(mar);
				pExt->getTransporte()->setNumPas(nP);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}

string ContTrans::ambulanciasOcupadas(){
	NodoTrans* pExt = ppio;
	stringstream s;

	while (pExt != NULL) {
		if (pExt->getTransporte()->getOcupacion() == true) {
			s << pExt->getTransporte()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

string ContTrans::mostrarDisponibles() {
	stringstream s;
	NodoTrans* pExt = ppio;
	s << "LISTADO DE TRANSPORTES DISPONIBLES" << endl;
	while (pExt != NULL) {
		if (pExt->getTransporte()->getOcupacion() == false) {
			s << pExt->getTransporte()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	s << "FIN DE LA LISTA..." << endl;
	s << "------------------------" << endl;
	return s.str();
}

double ContTrans::costoTotalTaxis(){
	double aux = 0.0;
	Cobro* cob = new Cobro();
	NodoTrans* pExt = ppio;
	string tipo = typeid(*pExt->getTransporte()).name();


	while (pExt != NULL) {
		if (tipo == "class Taxi") {
			aux += cob->calcularTotalD(pExt->getTransporte());
		}
		pExt = pExt->getSiguiente();
	}
	return aux;
}

Transporte* ContTrans::retornaTransporte(string pla) {
	NodoTrans* pExt = ppio;
	Transporte* ptr = NULL;
	if (pExt->getTransporte()->getPlaca() == pla) {
		ptr = pExt->getTransporte();
		return ptr;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getTransporte()->getPlaca() == pla) {
				ptr = pExt->getTransporte();
				return ptr;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return NULL;
}
