#include <iostream>
#include <string>

#include "vin-varsat.h"

using namespace std;

VinVarsat::VinVarsat(VinVarsat& vinVarsat) {
  this->pret = vinVarsat.pret;
  this->tip = vinVarsat.tip;
}

void VinVarsat::citeste(istream& in) {
  string str;
  cout << "Ce tip de vin doriti? (0 - rosu, 1 - alb)\n";
  in >> str;

  if(str == "0") {
    this->tip = ROSU;
  } else {
    this->tip = alb;
  }
}

void VinVarsat::afiseaza(ostream& out) {
  out << "Vin varsat ";
  switch(this->tip) {
    case ROSU:
      out << "rosu\n";
    break;
    case alb:
      out << "alb\n";
    break;
  }
}

istream& operator >> (istream& in, VinVarsat& vinVarsat) {
  vinVarsat.citeste(in);
  return in;
}

ostream& operator << (ostream& out, VinVarsat& vinVarsat) {
  vinVarsat.afiseaza(out);
  return out;
}
