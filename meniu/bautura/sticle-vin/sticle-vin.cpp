#include <iostream>
#include <string>

#include "sticle-vin.h"

using namespace std;

SticleVin::SticleVin(SticleVin& sticleVin) {
  this->pret = sticleVin.pret;
  this->tip = sticleVin.tip;
}

void SticleVin::citeste(istream& in) {
  string str;
  cout << "Ce tip de vin doriti? (0 - Bordeaux 1996, 1 - Castel Bolovanu 2004)\n";
  in >> str;

  if(str == "0") {
    this->tip = BORDEAUX_1996;
  } else {
    this->tip = CASTEL_BOLOVANU_2004;
  }

}

void SticleVin::afiseaza(ostream& out) {
  out << "Sticle de vin ";
  switch(this->tip) {
    case BORDEAUX_1996:
      out << "Bordeaux 1996\n";
    break;
    case CASTEL_BOLOVANU_2004:
      out << "Castel Bolovanu 2004\n";
    break;
  }
}

istream& operator >> (istream& in, SticleVin& sticleVin) {
  sticleVin.citeste(in);
  return in;
}

ostream& operator << (ostream& out, SticleVin& sticleVin) {
  sticleVin.afiseaza(out);
  return out;
}
