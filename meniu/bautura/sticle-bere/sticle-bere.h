#ifndef STICLE_BERE_H
#define STICLE_BERE_H

#include <string>

#include "../bautura.h"

enum TipSticleBere {
  CU_ALCOOL,
  FARA_ALCOOL
};

class SticleBere: public Bautura {
  protected:
    TipSticleBere tip;
  public:
    SticleBere(double pret = 0, TipSticleBere tip = CU_ALCOOL): Bautura(pret), tip(tip) {}
    SticleBere(SticleBere&);
    friend std::istream& operator >> (std::istream&, SticleBere&);
    friend std::ostream& operator << (std::ostream&, SticleBere&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
