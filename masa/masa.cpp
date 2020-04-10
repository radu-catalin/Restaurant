#include <iostream>
#include <string>

#include "masa.h"

using namespace std;

int Masa::numarMese = 0;

Masa::Masa(int capacitate = 1): capacitate(capacitate) {
  numarMese++;
}

Masa::Masa(Masa& masa) {
  numarMese++;
  this->capacitate = masa.capacitate;
}

int Masa::get_numarMese() {
  return numarMese;
}

int Masa::get_locuriLibere() {
  const int value = this->capacitate - this->clienti.size();
  return  value > 0 ? value : 0;
}

int Masa::get_numarClienti() {
  return this->clienti.size();
}

Client* Masa::get_client(int pozitie) {
  return this->clienti[pozitie];
}

bool Masa::elibereazaMasa() {
  this->clienti.clear();
  return !this->clienti.size();
}

bool Masa::potIntraToti(vector<Client*> clienti) {
  return clienti.size() <= (this->capacitate - this->clienti.size());
}

int Masa::adaugaClienti(vector<Client*> clienti) {
  if(!this->potIntraToti(clienti)) {
    return -1;
  }

  for(int i = 0; i < clienti.size(); i++) {
    this->clienti.push_back(clienti[i]);
  }

  return this->capacitate - this->clienti.size();
}
