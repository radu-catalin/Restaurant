#ifndef BAUTURA_H
#define BAUTURA_H

#include <string>
#include <iostream>


class Bautura {
  protected:
    double pret;
  public:
    Bautura(double pret = 0): pret(pret) {}
    Bautura(Bautura&);
    // TODO: copy constructor, destructor
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(std::istream&) {}
    virtual void afiseaza(std::ostream&) {}
};

#endif
