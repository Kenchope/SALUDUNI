#include "NodoCita.h"

NodoCita::NodoCita() { sig = NULL; citPt = NULL; }
NodoCita::NodoCita(Cita* c, NodoCita* s) { citPt = c; sig = s; }
NodoCita::~NodoCita() { delete citPt; }
//--------------------------
void NodoCita::setSiguiente(NodoCita* s) { sig = s; }
void NodoCita::setCita(Cita* c){ citPt = c; }
//--------------------------
Cita* NodoCita::getCita() { return citPt; }
NodoCita* NodoCita::getSiguiente() { return sig; }