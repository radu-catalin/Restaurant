#ifndef APA_H
#define APA_H

#include "../bautura.h"

enum TipApa {
  PLATA,
  MINERALA
};

class Apa: public Bautura {
  protected:
    TipApa tip;
  public:
    Apa(double pret = 0, TipApa tip = PLATA): Bautura(pret), tip(tip) {}
    Apa(Apa&);
    friend std::istream& operator >> (std::istream&, Apa&);
    friend std::ostream& operator << (std::ostream&, Apa&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
