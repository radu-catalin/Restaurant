#include "bautura.h"

using namespace std;


Bautura::Bautura(Bautura& bautura) {
  this->pret = bautura.pret;
}

double Bautura::get_pret() {
  return this->pret;
}

void Bautura::set_pret(double value) {
  this->pret = value;
}