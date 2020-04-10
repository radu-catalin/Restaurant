#include <iostream>

#include "meniu.h"


using namespace std;


double Meniu::get_pretCiorba() {
    Ciorba ciorba;
    cin >> ciorba;
    ciorba.set_pret(10);
    return ciorba.get_pret();
}

double Meniu::get_pretPui() {
    Pui pui;
    cin >> pui;
    pui.set_pret(15);
    return pui.get_pret();
}

double Meniu::get_pretVita() {
    Vita vita;
    cin >> vita;
    vita.set_pret(18);
    return vita.get_pret();
}

double Meniu::get_pretApa() {
    Apa apa;
    cin >> apa;
    apa.set_pret(5);
    return apa.get_pret();
}

double Meniu::get_pretSticleBere() {
    SticleBere sticleBere;
    cin >> sticleBere;
    sticleBere.set_pret(21);
    return sticleBere.get_pret();
}

double Meniu::get_pretSticleVin() {
    SticleVin sticleVin;
    cin >> sticleVin;
    sticleVin.set_pret(31);
    return sticleVin.get_pret();
}

double Meniu::get_pretVinVarsat() {
    VinVarsat vinVarsat;
    cin >> vinVarsat;
    vinVarsat.set_pret(12);
    return vinVarsat.get_pret();
}

double Meniu::get_pretTort() {
    Tort tort;
    cin >> tort;
    tort.set_pret(12);
    return tort.get_pret();
}

double Meniu::get_pretInghetata() {
    Inghetata inghetata;
    cin >> inghetata;
    inghetata.set_pret(10);
    return inghetata.get_pret();
}
