#include "NodoTransporte.h"

NodoTrans::NodoTrans() { siguiente = NULL; ptrTra = NULL; }

NodoTrans::NodoTrans(NodoTrans* s, Transporte* ptr):siguiente(s),ptrTra(ptr) {}

NodoTrans::~NodoTrans() { delete ptrTra; }

void NodoTrans::setSiguiente(NodoTrans* s) { siguiente = s; }

void NodoTrans::setTransporte(Transporte* tra) { ptrTra = tra; }

NodoTrans* NodoTrans::getSiguiente() { return siguiente; }

Transporte* NodoTrans::getTransporte() { return ptrTra; }