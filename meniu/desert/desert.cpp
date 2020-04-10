#include "desert.h"

Desert::Desert(Desert& desert) {
  this->pret = desert.pret;
}

double Desert::get_pret() {
  return this->pret;
}

void Desert::set_pret(double value) {
  this->pret = value;
}
