#include <iostream>
#include <string>

#include "ciorba.h"

using namespace std;


Ciorba::Ciorba(Ciorba& ciorba) {
  this->pret = ciorba.pret;
  this->tip = ciorba.tip;
  this->smantana = ciorba.smantana;
  this->ardei = ciorba.ardei;
}

void Ciorba::citeste(istream& in) {
    string str;

    cout << "Ce tip de ciorba doriti? (0 - burta, 1 - legume, 2 - ciuperci)\n";
    in >> str;
    if(str == "0") {
      this->tip = BURTA;
    } else if(str == "1") {
      this->tip = LEGUME;
    } else if(str == "2") {
      this->tip = CIUPERCI;
    }

    cout << "Ciorba sa aiba smantana? (0 - nu, 1 - da)\n";
    in >> this->smantana;

    cout << "Adaugam si ardei la ciorba? (0 - nu, 1 - da)\n";
    in >> this->ardei;
}

void Ciorba::afiseaza(ostream& out) {
  out << "Ciorba de: ";

  switch(this->tip) {
    case BURTA:
      out << "burta, ";
    break;
    case LEGUME:
      out << "legume, ";
    case CIUPERCI:
      out << "ciuperci, ";
  }

  if(this->smantana) {
    out << "cu smantana si ";
  } else {
    out << "fara smantana si ";
  }

  if(this->ardei) {
    out << "cu ardei.\n";
  } else {
    out << "fara ardei.\n";
  }

}

istream& operator >> (istream& in, Ciorba& ciorba) {
  ciorba.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Ciorba& ciorba) {
  ciorba.afiseaza(out);
  return out;
}

bool Ciorba::get_tip() {
  cout << this->tip << "\n";
  return this->tip;
}

void Ciorba::set_tip(TipCiorba value) {
  this->tip = value;
  cout << this->tip << "\n";
}

bool Ciorba::get_smantana() {
  return this->tip != CIUPERCI ? this->smantana : false;
}

void Ciorba::set_smantana(bool value) {
  this->smantana = this->tip != CIUPERCI ? value : false;
  cout << "Valoarea setata: " << this->smantana << "\n";
}

bool Ciorba::get_ardei() {
  return this->tip != CIUPERCI ? this->ardei : false;
}

void Ciorba::set_ardei(bool value) {
  this->smantana = this->tip != CIUPERCI ? value : false;;
}
