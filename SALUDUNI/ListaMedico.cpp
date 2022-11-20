#include "ListaMedico.h"

ListaMedico::ListaMedico() {
	ppio = NULL;
}

ListaMedico::~ListaMedico() {
	NodoMed* pExt = ppio;
	while (ppio != NULL) {
		ppio = pExt->getSiguiente();
		delete pExt;
		pExt = ppio;
	}
	ppio = NULL;
}

bool ListaMedico::isEmpty() {
	if (ppio == NULL)
		return true;
	else
		return false;
}

string ListaMedico::toString() {
	stringstream s;
	NodoMed* pExt = ppio;
	s << "====== Listado de Medicos ======" << endl;
	while (pExt != NULL) {
		s << pExt->getMedico()->toString() << endl;
		pExt = pExt->getSiguiente();
	}
	s << "================================" << endl;
	return s.str();
}

void ListaMedico::agregarMedico(Medico* ptrMed) {
	NodoMed* pExt = ppio;
	NodoMed* nuevo = NULL;

	//Ingresando a primer lugar
	if (pExt == NULL) {
		ppio = new NodoMed(ptrMed, NULL);
	}
	else {
		while (pExt->getSiguiente() != NULL) {
			pExt = pExt->getSiguiente();
		}
		nuevo = new NodoMed(ptrMed, NULL);
		pExt->setSiguiente(nuevo);
	}
}

Medico* ListaMedico::buscarMedicoCedula(string ced) {
	NodoMed* pExt = ppio;
	Medico* ptr = NULL;
	if (pExt->getMedico()->getCedula() == ced) {
		ptr = pExt->getMedico();
		return ptr;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getMedico()->getCedula() == ced) {
				ptr = pExt->getMedico();
				return ptr;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return NULL;
}

string ListaMedico::mostrarMedico(string ced) {
	NodoMed* pExt = ppio;
	stringstream s;

	if (pExt->getMedico()->getCedula() == ced) {
		s << pExt->getMedico()->toString() << endl;
		return s.str();
	}
	else {
		while (pExt != NULL) {
			if (pExt->getMedico()->getCedula() == ced) {
				s << pExt->getMedico()->toString() << endl;
				return s.str();
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return s.str();
}

bool ListaMedico::eliminaConCedula(string ced) {
	NodoMed* pExt = ppio;
	NodoMed* pAnt = NULL;
		
		if (pExt->getMedico()->getCedula() == ced) {
			ppio = pExt->getSiguiente();
			delete pExt;
			return true;
		}
		else {
			while (pExt != NULL) {
				if (pExt->getMedico()->getCedula() == ced) {
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

void ListaMedico::editarMedico(string ced, string esp, string nT) {
	NodoMed* pExt = ppio;

		if (pExt->getMedico()->getCedula() == ced) {  // Caso 1: al principio
			pExt->getMedico()->setEspec(esp);
			pExt->getMedico()->setNumTel(nT);
			return;
		}
		else {
			while (pExt != NULL) {
				if (pExt->getMedico()->getCedula() == ced) {
					pExt->getMedico()->setEspec(esp);
					pExt->getMedico()->setNumTel(nT);
					return;
				}
				else {
					pExt = pExt->getSiguiente();
				}
			}
		}
}