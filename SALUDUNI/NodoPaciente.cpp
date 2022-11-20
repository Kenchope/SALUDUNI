#include "NodoPaciente.h"

NodoPac::NodoPac() { paciente = NULL; siguiente = NULL; }
NodoPac::NodoPac(Paciente* pac, NodoPac* s) :paciente(pac), siguiente(s) {  }
NodoPac::~NodoPac() { delete paciente; }
//----------------------------
void NodoPac::setPaciente(Paciente* pac) { paciente = pac; }
void NodoPac::setSiguiente(NodoPac* s) { siguiente = s; }
Paciente* NodoPac::getPaciente() { return paciente; }
NodoPac* NodoPac::getSiguiente() { return siguiente; }