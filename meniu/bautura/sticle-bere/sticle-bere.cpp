#include <iostream>
#include <string>

#include "sticle-bere.h"

using namespace std;

SticleBere::SticleBere(SticleBere& sticleBere) {
  this->pret = sticleBere.pret;
  this->tip = sticleBere.tip;
}

void SticleBere::citeste(istream& in) {
  string str;
  cout << "Doriti berea sa fie cu alcool sau fara? (0 - cu alcool, 1 - fara alcool)\n";
  in >> str;

  if(str == "0") {
    this->tip = CU_ALCOOL;
  } else {
    this->tip = FARA_ALCOOL;
  }
}

void SticleBere::afiseaza(ostream& out) {
  out << "Sticle de bere ";
  switch(this->tip) {
    case CU_ALCOOL:
      out << "cu alcool\n";
    break;
    case FARA_ALCOOL:
      out << "fara alcool\n";
    break;
  }
}

istream& operator >> (istream& in, SticleBere& sticleBere) {
  sticleBere.citeste(in);
  return in;
}

ostream& operator << (ostream& out, SticleBere& sticleBere) {
  sticleBere.afiseaza(out);
  return out;
}
