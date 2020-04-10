#include <iostream>

#include "inghetata.h"

using namespace std;

Inghetata::Inghetata(Inghetata& inghetata) {
  this->pret = inghetata.pret;
  this->numarCupe = inghetata.numarCupe;
}

void Inghetata::citeste(istream& in) {
  string str;
  cout << "Cate cupe doriti la ingheta?\n";
  in >> this->numarCupe;

  if (this->numarCupe < 3) {
    this->numarCupe = 3;
  } else if (this->numarCupe > 5) {
    this->numarCupe = 5;
  }
}

void Inghetata::afiseaza(ostream& out) {
    out << "Inghetata cu " << this->numarCupe << " cupe\n";
}

istream& operator >> (istream& in, Inghetata& inghetata) {
  inghetata.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Inghetata& inghetata) {
  inghetata.afiseaza(out);
  return out;
}
