#include <iostream>
#include <string>

#include "client.h"

using namespace std;

int Client::numarClienti = 0;

Client::Client() {
  this->_id = numarClienti++;
  cout << "Clientul " << this->_id << " a fost citit\n";
}

Client::Client(Client& client) {
    this->_id = numarClienti++;
    this->suma = client.suma;
}

void Client::set_suma(double value) {
  this->suma = value;
}

double Client::get_suma() {
  return this->suma;
}

int Client::get_id() {
  return this->_id;
}

int Client::get_numarClienti() {
  return numarClienti;
}
