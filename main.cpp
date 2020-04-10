#include <iostream>
#include <vector>
#include <string>

#include "meniu/mancare/ciorba/ciorba.h"
#include "meniu/mancare/pui/pui.h"
#include "meniu/mancare/vita/vita.h"

#include "meniu/desert/tort/tort.h"
#include "meniu/desert/inghetata/inghetata.h"

#include "meniu/bautura/apa/apa.h"
#include "meniu/bautura/sticle-bere/sticle-bere.h"
#include "meniu/bautura/sticle-vin/sticle-vin.h"
#include "meniu/bautura/vin-varsat/vin-varsat.h"

#include "client/client.h"
#include "masa/masa.h"

#include "restaurant/restaurant.h"

using namespace std;

int main() {
    // Masa masa(4);
    // vector<Client*> clienti;
    // for(int i = 0; i < 5; i++) {
    //     string id = "masa1_";
    //     clienti.push_back(new Client(id));
    // }
    // cout << masa.potIntraToti(clienti);
    // masa.adaugaClienti(clienti, 0);

    (new Restaurant());
    return 0;
}
