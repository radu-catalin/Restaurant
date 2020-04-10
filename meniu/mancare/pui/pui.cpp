#include <iostream>
#include <string>

#include "pui.h"

using namespace std;


Pui::Pui(Pui& pui) {
  this->pret = pui.pret;
  this->tip = pui.tip;
}

void Pui::citeste(istream& in) {
    string str;
    cout << "Ce tip de pui doriti? (0 - FRIGARUI, 1 - TOCANA)\n";
    in >> str;
    if(str == "0") {
      this->tip = FRIGARUI;
    } else {
      this->tip = TOCANA;
    }
}

void Pui::afiseaza(ostream& out) {
  out << "Pui ";
  switch(this->tip) {
    case FRIGARUI:
      out << "frigarui\n";
    break;
    case TOCANA:
      out << "tocana\n";
    break;
  }
}

istream& operator >> (istream& in, Pui& pui) {
  pui.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Pui& pui) {
  pui.afiseaza(out);
  return out;
}
