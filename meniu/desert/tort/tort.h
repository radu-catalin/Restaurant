#ifndef TORT_H
#define TORT_H

#include <string>

#include "../desert.h"

enum TipTort {
  CIOCOLATA,
  FRUCTE
};

class Tort: public Desert {
  protected:
    TipTort tip;
  public:
    Tort(double pret = 0, TipTort tip = CIOCOLATA): Desert(pret), tip(tip) {}
    Tort(Tort&);
    friend std::istream& operator >> (std::istream&, Tort&);
    friend std::ostream& operator << (std::ostream&, Tort&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
