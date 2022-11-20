#include"NodoMedico.h"

NodoMed::NodoMed() {
	medPtr = NULL;
	sig = NULL;
}

NodoMed::NodoMed(Medico* med, NodoMed* s) {
	medPtr = med;
	sig = s;
}

NodoMed::~NodoMed() {
	delete medPtr;
}
//---------------------
Medico* NodoMed::getMedico() {
	return medPtr;
}

NodoMed* NodoMed::getSiguiente() {
	return sig;
}
//---------------------
void NodoMed::setMedico(Medico* med) { medPtr = med; }

void NodoMed::setSiguiente(NodoMed* s) { sig = s; }