#include "mancare.h"

Mancare::Mancare(Mancare& mancare) {
  this->pret = mancare.pret;
}

double Mancare::get_pret() {
  return this->pret;
}

void Mancare::set_pret(double value) {
  this->pret = value;
}