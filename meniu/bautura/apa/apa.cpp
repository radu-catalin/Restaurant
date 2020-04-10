#include <iostream>
#include <string>

#include "apa.h"

using namespace std;

Apa::Apa(Apa& apa) {
  this->pret = apa.pret;
  this->tip = apa.tip;
}

void Apa::citeste(istream& in) {
  string str;
  cout << "Doriti apa sa fie plata sau minerala? (0 - plata, 1 - minerala)\n";
  in >> str;

  if(str == "0") {
    this->tip = PLATA;
  } else {
    this->tip = MINERALA;
  }
}

void Apa::afiseaza(ostream& out) {
  out << "Apa ";
  switch(this->tip) {
    case PLATA:
      out << "plata\n";
    break;
    case MINERALA:
      out << "minerala\n";
    break;
  }
}

istream& operator >> (istream& in, Apa& apa) {
  apa.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Apa& apa) {
  apa.afiseaza(out);
  return out;
}
