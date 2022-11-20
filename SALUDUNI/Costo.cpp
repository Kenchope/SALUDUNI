#include "Costo.h"

string Cobro::toString(Transporte* txPtr) {
	stringstream s;
	if (txPtr->getTipoViaje() == "Ida-Vuelta") {
		s << "Total a pagar: " << this->calcularTotalD(txPtr) * 2 << endl;
	}
	else if (txPtr->getTipoViaje() == "Ida") {
		s << "Total a pagar: " << this->calcularTotalD(txPtr) << endl;
	}
	return s.str();
}
//------------------------------
double Cobro::calcularTotalD(Transporte* txPtr) {
	double aux1 = 0.0;
	double dist = txPtr->getDistancia();
	double porc = 0.0;
	do {
		if (dist < 2.0) {
			aux1 = 950;
			dist = 0.0;
		}
		else if (dist == 2.0) {
			aux1 = 1900;
		}
		else if (dist > 2.0 && dist <= 5.0) {
			aux1 = 1900 + (700 * (dist - 2.0));
			dist = 0.0;
		}
		else if (dist > 5.0) {
			aux1 = (1900) + (2100) + 600 * (dist - 5.0);
			dist = 0.0;
		}
	} while (dist != 0.0);
	porc = ((txPtr->getNumPas() * 10) / 100) * aux1;

	return aux1 + porc;
}