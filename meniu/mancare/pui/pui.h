#ifndef PUI_H
#define PUI_H

#include <string>

#include "../mancare.h"

enum TipPui {
  FRIGARUI,
  TOCANA
};

class Pui: public Mancare {
  protected:
    TipPui tip;
  public:
    Pui(double pret = 0, TipPui tip = FRIGARUI): Mancare(pret), tip(tip) {}
    Pui(Pui&);
    friend std::istream& operator >> (std::istream&, Pui&);
    friend std::ostream& operator << (std::ostream&, Pui&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
