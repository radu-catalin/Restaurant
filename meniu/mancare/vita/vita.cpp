#include <string>

#include "vita.h"

using namespace std;


Vita::Vita(Vita& vita) {
  this->pret = vita.pret;
  this->tip = vita.tip;
}
void Vita::citeste(istream& in) {
    string str;
    cout << "Ce tip de vita doriti? (0 - Chateaubriand, 1 - Stroganoff, 2 - file)\n";
    in >> str;
    if(str == "0") {
      this->tip = CHATEAUBRIAND;
    } else if(str == "1") {
      this->tip = STROGANOFF;
    } else {
      this->tip = file;
    }
}

void Vita::afiseaza(ostream& out) {
  out << "Vita ";
  switch(this->tip) {
    case CHATEAUBRIAND:
      out << "CHATEAUBRIAND\n";
    break;
    case STROGANOFF:
      out << "STROGANOFF\n";
    break;
    case file:
      out << "file\n";
    break;
  }
}

istream& operator >> (istream& in, Vita& vita) {
  vita.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Vita& vita) {
  vita.afiseaza(out);
  return out;
}