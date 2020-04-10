#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>

#include "../client/client.h"
#include "../masa/masa.h"
#include "../meniu/meniu.h"


class Restaurant {
    protected:
        std::vector<Masa*> mese;
        Meniu* meniu = new Meniu();
    public:
        Restaurant();
        Restaurant(Restaurant&) {}
    private:
        void meniuPrincipal();
        void optiunea1(); // clienti noi
        void optiunea2(); // un client vrea sa comande
        void optiunea3(); // clientii de la o masa cer nota
        void optiunea4(); // Inchide restaurantul
        void inapoi();
        void cautaMasa(std::vector<Client*>);
};


#endif
