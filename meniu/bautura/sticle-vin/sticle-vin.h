#ifndef STICLE_VIN_H
#define STICLE_VIN_H

#include <string>
#include "../bautura.h"

enum TipSticleVin {
  BORDEAUX_1996,
  CASTEL_BOLOVANU_2004
};

class SticleVin: public Bautura {
  protected:
    TipSticleVin tip;
  public:
    SticleVin(double pret = 0, TipSticleVin tip = BORDEAUX_1996): Bautura(pret), tip(tip) {}
    SticleVin(SticleVin&);
    friend std::istream& operator >> (std::istream&, SticleVin&);
    friend std::ostream& operator << (std::ostream&, SticleVin&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
