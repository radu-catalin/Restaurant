#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {
    protected:
        int _id;
        double suma = 0;
        static int numarClienti;
    public:
        Client();
        Client(Client&);
        void set_suma(double);
        double get_suma();
        int get_id();
        static int get_numarClienti();
};

#endif
