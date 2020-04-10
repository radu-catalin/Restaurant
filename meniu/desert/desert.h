#ifndef DESERT_H
#define DESERT_H

#include <string>

class Desert {
  protected:
  double pret;
  public:
    Desert(double pret = 0): pret(pret) {}
    Desert(Desert&);
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(std::istream&) {}
    virtual void afiseaza(std::ostream&) {}
};

#endif