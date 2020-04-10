#ifndef CIORBA_H
#define CIORBA_H

#include <string>

#include "../mancare.h"

enum TipCiorba {
  BURTA,
  LEGUME,
  CIUPERCI
};

class Ciorba: public Mancare {
  protected:
    TipCiorba tip;
    bool smantana;
    bool ardei;
  public:
    Ciorba(double pret = 0, TipCiorba tip = BURTA, bool smantana = false, bool ardei = false): Mancare(pret), tip(tip), smantana(smantana), ardei(ardei) {}
    Ciorba(Ciorba&);
    friend std::istream& operator >> (std::istream&, Ciorba&);
    friend std::ostream& operator << (std::ostream&, Ciorba&);

    bool get_tip();
    void set_tip(TipCiorba);

    bool get_smantana();
    void set_smantana(bool);

    bool get_ardei();
    void set_ardei(bool);
  protected:
    void citeste(std::istream&);
    void afiseaza(std::ostream&);
};

#endif
