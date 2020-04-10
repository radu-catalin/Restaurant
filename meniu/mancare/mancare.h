#ifndef MANCARE_H
#define MANCARE_H

#include <string>
#include <iostream>

class Mancare {
  protected:
    double pret;
  public:
    Mancare(double pret = 0): pret(pret) {}
    Mancare(Mancare&);
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(std::istream&) {}
    virtual void afiseaza(std::ostream&) {}
};

#endif
