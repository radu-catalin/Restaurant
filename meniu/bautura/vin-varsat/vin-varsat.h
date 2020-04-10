#ifndef VIN_VARSAT_H
#define VIN_VARSAT_H

#include <string>

#include "../bautura.h"

enum TipVinVarsat {
  ROSU,
  alb
};

class VinVarsat: public Bautura {
  protected:
    TipVinVarsat tip;
  public:
    VinVarsat(double pret = 0, TipVinVarsat tip = ROSU): Bautura(pret), tip(tip) {}
    VinVarsat(VinVarsat&);
    friend std::istream& operator >> (std::istream&, VinVarsat&);
    friend std::ostream& operator << (std::ostream&, VinVarsat&);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif