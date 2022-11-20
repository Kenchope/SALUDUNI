#include "Hora.h"

Hora::Hora(){
	hor = 0;
	min = 0;
}
Hora::Hora(int h, int m) { hor = h; min = m; }
Hora::~Hora(){}
string Hora::toString() { 
	stringstream s;
	s << "Hora: " << hor << ":" << min << ":" << "00" << endl;
	return s.str();
}

void  Hora::setHor(int h) { hor = h; }
void  Hora::setMin(int m) { min = m; }