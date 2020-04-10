#include <iostream>

#include "tort.h"

using namespace std;

Tort::Tort(Tort& tort) {
  this->pret = tort.pret;
  this->tip = tort.tip;
}

void Tort::citeste(istream& in) {
  string str;
  cout << "Ce tip de tort doriti? (0 - tort de ciocolata, 1 - tort de fructe)\n";
  in >> str;
  if(str == "0") {
    this->tip = CIOCOLATA;
  } else {
    this->tip = FRUCTE;
  }
}

void Tort::afiseaza(ostream& out) {
    out << "Tort de ";
    switch(this->tip) {
      case CIOCOLATA:
        out << "ciocolata\n";
      break;
      case FRUCTE:
        out << "fructe\n";
      break;
    }
}

istream& operator >> (istream& in, Tort& tort) {
  tort.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Tort& tort) {
  tort.afiseaza(out);
  return out;
}
