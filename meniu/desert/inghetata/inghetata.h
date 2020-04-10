#ifndef INGHETATA_H
#define INGHETATA_H

#include <string>

#include "../desert.h"

class Inghetata: public Desert {
    protected:
      int numarCupe;
    public:
      Inghetata(double pret = 0, int numarCupe = 3): Desert(pret), numarCupe(numarCupe) {}
      Inghetata(Inghetata&);
      friend std::istream& operator >> (std::istream&, Inghetata&);
      friend std::ostream& operator << (std::ostream&, Inghetata&);
    protected:
      void citeste(std::istream&);
      void afiseaza(std::ostream&);
};

#endif
