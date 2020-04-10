#ifndef VITA_H
#define VITA_H

#include <string>

#include "../mancare.h"

enum TipVita {
  CHATEAUBRIAND,
  STROGANOFF,
  file
};

class Vita: public Mancare {
  protected:
    TipVita tip;
  public:
    Vita(double pret = 0, TipVita tip = CHATEAUBRIAND): Mancare(pret), tip(tip) {}
    Vita(Vita&);
    friend std::istream& operator >> (std::istream&, Vita&);
    friend std::ostream& operator << (std::ostream&, Vita&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
