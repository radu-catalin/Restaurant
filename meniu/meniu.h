#ifndef MENIU_H
#define MENIU_H

#include "mancare/ciorba/ciorba.h"
#include "mancare/pui/pui.h"
#include "mancare/vita/vita.h"

#include "desert/tort/tort.h"
#include "desert/inghetata/inghetata.h"

#include "bautura/apa/apa.h"
#include "bautura/sticle-bere/sticle-bere.h"
#include "bautura/sticle-vin/sticle-vin.h"
#include "bautura/vin-varsat/vin-varsat.h"

class Meniu {
    public:
      Meniu() {}
      Meniu(Meniu&) {}
      double get_pretCiorba();
      double get_pretPui();
      double get_pretVita();

      double get_pretApa();
      double get_pretSticleBere();
      double get_pretSticleVin();
      double get_pretVinVarsat();

      double get_pretTort();
      double get_pretInghetata();
};

#endif