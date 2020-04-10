#include <iostream>
#include <stdlib.h>
#include <string>

#include "restaurant.h"

using namespace std;

Restaurant::Restaurant() {
  int n;

  cout << "Cate mese sunt in restaurant?\n";
  cout << "n = ";
  cin >> n;

  cout << "-----\n";
  cout << "Numar locuri pentru fiecare masa:\n";
  for(int i = 0; i < n; i++) {
    int capacitate;
    cout << "Masa " << i + 1 << " = ";
    cin >> capacitate;
    Masa* masa = new Masa(capacitate);

    this->mese.push_back(masa);
  }
  this->meniuPrincipal();
}

void Restaurant::meniuPrincipal() {
  system("cls");
  cout << "Alege o optiune:\n\n";
  cout << "1. Clienti noi\n";
  cout << "2. Un client vrea sa comande\n";
  cout << "3. Clientii de la o masa cer nota\n";
  cout << "4. Inchide restaurant\n";

  int opt;
  cin >> opt;

  switch(opt) {
    case 1:
      this->optiunea1();
    break;
    case 2:
      this->optiunea2();
    break;
    case 3:
      this->optiunea3();
    break;
    case 4:
      this->optiunea4();
    break;
  }
}

void Restaurant::optiunea1() {
  system("cls");
  int n;
  cout << "Introdu numarul de clienti:\n";
  cout << "n = ";
  cin >> n;
  vector<Client*> clienti;
  for(int i = 0; i < n; i++) {
    clienti.push_back(new Client());
  }

  this->cautaMasa(clienti);
  this->inapoi();
}

void Restaurant::optiunea2() {
  int opt;
  // string afisare;
  double suma = 0;


  for (int i = 0; i < this->mese.size(); i++) {
    int numarClienti = this->mese[i]->get_numarClienti();
    cout << "masa " << i << ": [";
    for (int j = 0; j < numarClienti; j++) {
        cout << "client ";
        cout << this->mese[i]->get_client(j)->get_id();
        if (j < numarClienti - 1) {
          cout << ", ";
        }
    }
    cout << "]\n";
  }
  cout << "\nIntrodu numarul clientului care vrea sa comande (0, 1, ...)\n";
  cin >> opt;

  bool gasit = false;
  Client* client;
  for(int i = 0; i < this->mese.size(); i++) {
    int numarClienti = this->mese[i]->get_numarClienti();
    for(int j = 0; j < numarClienti; j++) {
      if(opt == this->mese[i]->get_client(j)->get_id()) {
        gasit = true;
        client = this->mese[i]->get_client(j);
        break;
      }
    }

    if(gasit) {
      break;
    }
  }
  system("cls");

  cout << "Doriti ciorba? (0 - nu, 1 - da)\n";
  cin >> opt;

  if(opt == 1) {
     suma += this->meniu->get_pretCiorba();
  }

  system("cls");
  cout << "Doriti fel principal pui sau vita? (0 - nu doresc fel principal, 1 - pui, 2 - vita)\n";
  cin >> opt;

  switch(opt) {
    case 1:
      suma += this->meniu->get_pretPui();
    break;
    case 2:
      suma += this->meniu->get_pretVita();
    break;
  }

  system("cls");
  cout << "Ce bautura doriti sa va aduc? (0 - nu doresc nimic de baut, 1 - apa, 2 - sticle de bere, 3 - sticle de vin, 4 - vin varsat\n";
  cin >> opt;

  switch(opt) {
    case 1:
      suma += this->meniu->get_pretApa();
    break;
    case 2:
      suma += this->meniu->get_pretSticleBere();
    break;
    case 3:
      suma += this->meniu->get_pretSticleVin();
    break;
    case 4:
      suma += this->meniu->get_pretVinVarsat();
    break;
  }

  system("cls");
  cout << "Ce desert doriti sa va aduc? (0 - nu dorec desert, 1 - tort, 2 - inghetata)\n";
  cin >> opt;

  switch(opt) {
    case 1:
      suma += this->meniu->get_pretTort();
    break;
    case 2:
      suma += this->meniu->get_pretInghetata();
    break;
  }

  client->set_suma(suma);

  this->inapoi();
}

void Restaurant::optiunea3() {
  int opt;
  system("cls");

  cout << "Care masa cere nota?\n";
  for (int i = 0; i < this->mese.size(); i++) {
    if (this->mese[i]->get_numarClienti()) {
      cout << "masa " << i << "\n";
    }
  }
  cin >> opt;

  system("cls");

  int numarClienti = this->mese[opt]->get_numarClienti();
  for(int j = 0; j < numarClienti; j++) {
    cout << "Clientul " << this->mese[opt]->get_client(j)->get_id() << " are de platit " << this->mese[opt]->get_client(j)->get_suma() << "\n";
  }

  if (this->mese[opt]->elibereazaMasa()) {
    cout << "Masa este libera\n";
  }

  this->inapoi();
}

void Restaurant::optiunea4() {
  system("cls");
  int opt;

  if (Client::get_numarClienti()) {
    cout << "In restaurant se mai afla si alti clienti, esti sigur ca vrei sa-l inchizi? (0 - nu, 1 - da)\n";
    cin >> opt;

    if(opt == 0) {
      this->inapoi();
    }
  }

}

void Restaurant::cautaMasa(vector<Client*> clienti) {
  for(int i = 0; i < this->mese.size(); i++) {
    if(mese[i]->potIntraToti(clienti)) {
      mese[i]->adaugaClienti(clienti);
      cout << "Masa " << i << " a fost ocupata\n";
      break;
    } else if(i == this->mese.size() - 1) {
      cout << "Toate mesele sunt ocupate\n";
    }
  }
}

void Restaurant::inapoi() {
  string opt;
  cout << "Apasa orice tasta urmata de enter pentru a te intoarce in meniul principala\n";
  cin >> opt;
  this->meniuPrincipal();
}
