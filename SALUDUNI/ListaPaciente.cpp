#include "ListaPaciente.h"

contPac::contPac() { ppio = NULL; }
contPac::~contPac(){
	NodoPac* pExt = ppio;
	while (ppio != NULL) {
		ppio = pExt->getSiguiente();
		delete pExt;
		pExt = ppio;
	}
	ppio = NULL;
}

string contPac::toString(){
	stringstream s;
	NodoPac* pExt = ppio;
	s << "Listado de Pacientes: " << endl;
	while (pExt != NULL) {
		s << pExt->getPaciente()->toString() << endl;
		pExt = pExt->getSiguiente();
	}
	s << "----------------------" << endl; 
	return s.str();
}

bool contPac::isEmpty() {
	if (ppio == NULL)
		return true;
	else
		return false;
}

NodoPac* contPac::getPpio() {
	return ppio;
}


void contPac::agregaPaciente(Paciente* ptr){
	NodoPac* pExt = ppio;
	NodoPac* nuevo = NULL;
	if (pExt == NULL) {
		ppio = new NodoPac(ptr, NULL);
	}
	else {
		while (pExt->getSiguiente() != NULL) {
			pExt = pExt->getSiguiente();
		}
		nuevo = new NodoPac(ptr, NULL);
		pExt->setSiguiente(nuevo);
	}
}

bool contPac::eliminaConID(string ced){
	NodoPac* pExt = ppio;
	NodoPac* pAnt = NULL;

	if (pExt->getPaciente()->getID() == ced) {
		ppio = pExt->getSiguiente();
		delete pExt;
		return true;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
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

string contPac::mostrarConID(string ced) {
	NodoPac* pExt = ppio;
	stringstream s;

	if (pExt->getPaciente()->getID() == ced) {
		s << pExt->getPaciente()->toString() << endl;
		return s.str();
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				s << pExt->getPaciente()->toString() << endl;
				return s.str();
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return s.str();
}


string contPac::listaExiliados(){
	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();
	stringstream s;

	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
			if (pExt->getPaciente()->getCond() == "Exiliado") {
				s << pExt->getPaciente()->toString() << endl;
			}
			pExt = pExt->getSiguiente();
	}
	return s.str();
}

string contPac::mejorCalificacionInterinos(){

	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();
	stringstream s;
	NodoPac* prf1 = NULL;
	NodoPac* prf2 = NULL;
	NodoPac* prf3 = NULL;
	int calMayor = 0;

	//--------------------------------------------------------------
	//Conseguir el primer profesor
	if (pExt != NULL) {
		while (pExt != NULL) {
			tipo = typeid(*pExt->getPaciente()).name();
			if (tipo == "class ProfInte") {
				if (pExt->getPaciente()->getCalif() > calMayor) {
					prf1 = pExt;
					calMayor = pExt->getPaciente()->getCalif();
				}
			}
			pExt = pExt->getSiguiente();
		}
		
	}
	
	//Conseguir segundo profesor
	pExt = ppio;
	calMayor = 0;
	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class ProfInte" && pExt != prf1) {
			if (pExt->getPaciente()->getCalif() > calMayor) {
				prf2 = pExt;
				calMayor = pExt->getPaciente()->getCalif();
			}
		}
		pExt = pExt->getSiguiente();
	}

	//Conseguir tercer profesor

	pExt = ppio;
	calMayor = 0;
	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class ProfInte" && pExt != prf1 && pExt != prf2) {
			if (pExt->getPaciente()->getCalif() > calMayor) {
				prf3 = pExt;
				calMayor = pExt->getPaciente()->getCalif();
			}
		}
		pExt = pExt->getSiguiente();
	}
	//--------------------------------------------------------------------
	s << "Profesores Interinos con las mejores calificaciones: " << endl;
	s << prf1->getPaciente()->toString() << endl;
	s << "---------------------------------------" << endl;
	s << prf2->getPaciente()->toString() << endl;
	s << "---------------------------------------" << endl;
	s << prf3->getPaciente()->toString() << endl;
	s << "--------- FIN DE LA LISTA ----------" << endl;

	return s.str();
}

string contPac::mostrarProInt() {
	stringstream s;
	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();

	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class ProfInte") {
			s << pExt->getPaciente()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

string contPac::mostrarProEnProp() {
	stringstream s;
	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();

	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class ProfProp") {
			s << pExt->getPaciente()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

string contPac::mostrarEstNac() {
	stringstream s;
	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();

	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class EstNac") {
			s << pExt->getPaciente()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

string contPac::mostrarEstInt() {
	stringstream s;
	NodoPac* pExt = ppio;
	string tipo = typeid(*pExt->getPaciente()).name();

	while (pExt != NULL) {
		tipo = typeid(*pExt->getPaciente()).name();
		if (tipo == "class EstInt") {
			s << pExt->getPaciente()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return s.str();
}

//-----------------------------------------------------------------------------
void contPac::editaPI(string ced, int aL, int cal) {
	NodoPac* pExt = ppio;
	if (pExt->getPaciente()->getID() == ced) {
		pExt->getPaciente()->setAnnios(aL);
		pExt->getPaciente()->setCalif(cal);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				pExt->getPaciente()->setAnnios(aL);
				pExt->getPaciente()->setCalif(cal);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}
void contPac::editaPP(string ced, int aL, string cP) {
	NodoPac* pExt = ppio;
	
	if (pExt->getPaciente()->getID() == ced) {
		pExt->getPaciente()->setAnnios(aL);
		pExt->getPaciente()->setCodPla(cP);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				pExt->getPaciente()->setAnnios(aL);
				pExt->getPaciente()->setCodPla(cP);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}
void contPac::editaEN(string ced, string est, string nT) {
	NodoPac* pExt = ppio;
	if (pExt->getPaciente()->getID() == ced) {
		pExt->getPaciente()->setEstado(est);
		pExt->getPaciente()->setNumTel(nT);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				pExt->getPaciente()->setEstado(est);
				pExt->getPaciente()->setNumTel(nT);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}
void contPac::editaEI(string ced, string cond, string nT) {
	NodoPac* pExt = ppio;
	if (pExt->getPaciente()->getID() == ced) {
		pExt->getPaciente()->setCond(cond);
		pExt->getPaciente()->setNumTel(nT);
		return;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				pExt->getPaciente()->setCond(cond);
				pExt->getPaciente()->setNumTel(nT);
				return;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
}

Paciente* contPac::retornaPaciente(string ced) {
	NodoPac* pExt = ppio;
	Paciente* ptr = NULL;
	if (pExt->getPaciente()->getID() == ced) {
		ptr = pExt->getPaciente();
		return ptr;
	}
	else {
		while (pExt != NULL) {
			if (pExt->getPaciente()->getID() == ced) {
				ptr = pExt->getPaciente();
				return ptr;
			}
			else {
				pExt = pExt->getSiguiente();
			}
		}
	}
	return NULL;
	return NULL;
}

