#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "../client/client.h"


class Masa {
  protected:
    int capacitate;
    std::vector<Client*> clienti;
    static int numarMese;
  public:
    Masa(int capacitate);
    Masa(Masa&);
    int get_numarMese();
    int get_locuriLibere();
    int get_numarClienti();
    Client* get_client(int);
    bool elibereazaMasa();
    bool potIntraToti(std::vector<Client*>);
    int adaugaClienti(std::vector<Client*>);
};

#endif
