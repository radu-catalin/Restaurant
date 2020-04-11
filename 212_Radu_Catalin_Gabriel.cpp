#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Mancare
class Mancare {
  protected:
    double pret;
  public:
    Mancare(double pret = 0): pret(pret) {}
    Mancare(Mancare&);
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(istream&) {}
    virtual void afiseaza(ostream&) {}
};

Mancare::Mancare(Mancare& mancare) {
  this->pret = mancare.pret;
}

double Mancare::get_pret() {
  return this->pret;
}

void Mancare::set_pret(double value) {
  this->pret = value;
}

// Ciorba
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
    friend istream& operator >> (istream&, Ciorba&);
    friend ostream& operator << (ostream&, Ciorba&);

    bool get_tip();
    void set_tip(TipCiorba);

    bool get_smantana();
    void set_smantana(bool);

    bool get_ardei();
    void set_ardei(bool);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

Ciorba::Ciorba(Ciorba& ciorba) {
  this->pret = ciorba.pret;
  this->tip = ciorba.tip;
  this->smantana = ciorba.smantana;
  this->ardei = ciorba.ardei;
}

void Ciorba::citeste(istream& in) {
    string str;

    cout << "Ce tip de ciorba doriti? (0 - burta, 1 - legume, 2 - ciuperci)\n";
    in >> str;
    if(str == "0") {
      this->tip = BURTA;
    } else if(str == "1") {
      this->tip = LEGUME;
    } else if(str == "2") {
      this->tip = CIUPERCI;
    }

    cout << "Ciorba sa aiba smantana? (0 - nu, 1 - da)\n";
    in >> this->smantana;

    cout << "Adaugam si ardei la ciorba? (0 - nu, 1 - da)\n";
    in >> this->ardei;
}

void Ciorba::afiseaza(ostream& out) {
  out << "Ciorba de: ";

  switch(this->tip) {
    case BURTA:
      out << "burta, ";
    break;
    case LEGUME:
      out << "legume, ";
    case CIUPERCI:
      out << "ciuperci, ";
  }

  if(this->smantana) {
    out << "cu smantana si ";
  } else {
    out << "fara smantana si ";
  }

  if(this->ardei) {
    out << "cu ardei.\n";
  } else {
    out << "fara ardei.\n";
  }

}

istream& operator >> (istream& in, Ciorba& ciorba) {
  ciorba.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Ciorba& ciorba) {
  ciorba.afiseaza(out);
  return out;
}

bool Ciorba::get_tip() {
  cout << this->tip << "\n";
  return this->tip;
}

void Ciorba::set_tip(TipCiorba value) {
  this->tip = value;
  cout << this->tip << "\n";
}

bool Ciorba::get_smantana() {
  return this->tip != CIUPERCI ? this->smantana : false;
}

void Ciorba::set_smantana(bool value) {
  this->smantana = this->tip != CIUPERCI ? value : false;
  cout << "Valoarea setata: " << this->smantana << "\n";
}

bool Ciorba::get_ardei() {
  return this->tip != CIUPERCI ? this->ardei : false;
}

void Ciorba::set_ardei(bool value) {
  this->smantana = this->tip != CIUPERCI ? value : false;;
}

// Pui
enum TipPui {
  FRIGARUI,
  TOCANA
};

class Pui: public Mancare {
  protected:
    TipPui tip;
  public:
    Pui(double pret = 0, TipPui tip = FRIGARUI): Mancare(pret), tip(tip) {}
    Pui(Pui&);
    friend istream& operator >> (istream&, Pui&);
    friend ostream& operator << (ostream&, Pui&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

Pui::Pui(Pui& pui) {
  this->pret = pui.pret;
  this->tip = pui.tip;
}

void Pui::citeste(istream& in) {
    string str;
    cout << "Ce tip de pui doriti? (0 - FRIGARUI, 1 - TOCANA)\n";
    in >> str;
    if(str == "0") {
      this->tip = FRIGARUI;
    } else {
      this->tip = TOCANA;
    }
}

void Pui::afiseaza(ostream& out) {
  out << "Pui ";
  switch(this->tip) {
    case FRIGARUI:
      out << "frigarui\n";
    break;
    case TOCANA:
      out << "tocana\n";
    break;
  }
}

istream& operator >> (istream& in, Pui& pui) {
  pui.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Pui& pui) {
  pui.afiseaza(out);
  return out;
}


// Vita
enum TipVita {
  CHATEAUBRIAND,
  STROGANOFF,
  file
};

class Vita: public Mancare {
  protected:
    TipVita tip;
  public:
    Vita(double pret = 0, TipVita tip = CHATEAUBRIAND): Mancare(pret), tip(tip) {}
    Vita(Vita&);
    friend istream& operator >> (istream&, Vita&);
    friend ostream& operator << (ostream&, Vita&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

Vita::Vita(Vita& vita) {
  this->pret = vita.pret;
  this->tip = vita.tip;
}
void Vita::citeste(istream& in) {
    string str;
    cout << "Ce tip de vita doriti? (0 - Chateaubriand, 1 - Stroganoff, 2 - file)\n";
    in >> str;
    if(str == "0") {
      this->tip = CHATEAUBRIAND;
    } else if(str == "1") {
      this->tip = STROGANOFF;
    } else {
      this->tip = file;
    }
}

void Vita::afiseaza(ostream& out) {
  out << "Vita ";
  switch(this->tip) {
    case CHATEAUBRIAND:
      out << "CHATEAUBRIAND\n";
    break;
    case STROGANOFF:
      out << "STROGANOFF\n";
    break;
    case file:
      out << "file\n";
    break;
  }
}

istream& operator >> (istream& in, Vita& vita) {
  vita.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Vita& vita) {
  vita.afiseaza(out);
  return out;
}

// Desert
class Desert {
  protected:
  double pret;
  public:
    Desert(double pret = 0): pret(pret) {}
    Desert(Desert&);
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(istream&) {}
    virtual void afiseaza(ostream&) {}
};

Desert::Desert(Desert& desert) {
  this->pret = desert.pret;
}

double Desert::get_pret() {
  return this->pret;
}

void Desert::set_pret(double value) {
  this->pret = value;
}

// Inghetata
class Inghetata: public Desert {
    protected:
      int numarCupe;
    public:
      Inghetata(double pret = 0, int numarCupe = 3): Desert(pret), numarCupe(numarCupe) {}
      Inghetata(Inghetata&);
      friend istream& operator >> (istream&, Inghetata&);
      friend ostream& operator << (ostream&, Inghetata&);
    protected:
      void citeste(istream&);
      void afiseaza(ostream&);
};

Inghetata::Inghetata(Inghetata& inghetata) {
  this->pret = inghetata.pret;
  this->numarCupe = inghetata.numarCupe;
}

void Inghetata::citeste(istream& in) {
  string str;
  cout << "Cate cupe doriti la ingheta?\n";
  in >> this->numarCupe;

  if (this->numarCupe < 3) {
    this->numarCupe = 3;
  } else if (this->numarCupe > 5) {
    this->numarCupe = 5;
  }
}

void Inghetata::afiseaza(ostream& out) {
    out << "Inghetata cu " << this->numarCupe << " cupe\n";
}

istream& operator >> (istream& in, Inghetata& inghetata) {
  inghetata.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Inghetata& inghetata) {
  inghetata.afiseaza(out);
  return out;
}

// Tort
enum TipTort {
  CIOCOLATA,
  FRUCTE
};

class Tort: public Desert {
  protected:
    TipTort tip;
  public:
    Tort(double pret = 0, TipTort tip = CIOCOLATA): Desert(pret), tip(tip) {}
    Tort(Tort&);
    friend istream& operator >> (istream&, Tort&);
    friend ostream& operator << (ostream&, Tort&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

Tort::Tort(Tort& tort) {
  this->pret = tort.pret;
  this->tip = tort.tip;
}

void Tort::citeste(istream& in) {
  string str;
  cout << "Ce tip de tort doriti? (0 - tort de ciocolata, 1 - tort de fructe)\n";
  in >> str;
  if(str == "0") {
    this->tip = CIOCOLATA;
  } else {
    this->tip = FRUCTE;
  }
}

void Tort::afiseaza(ostream& out) {
    out << "Tort de ";
    switch(this->tip) {
      case CIOCOLATA:
        out << "ciocolata\n";
      break;
      case FRUCTE:
        out << "fructe\n";
      break;
    }
}

istream& operator >> (istream& in, Tort& tort) {
  tort.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Tort& tort) {
  tort.afiseaza(out);
  return out;
}

// Bautura
class Bautura {
  protected:
    double pret;
  public:
    Bautura(double pret = 0): pret(pret) {}
    Bautura(Bautura&);
    // TODO: copy constructor, destructor
    double get_pret();
    void set_pret(double);
  protected:
    virtual void citeste(istream&) {}
    virtual void afiseaza(ostream&) {}
};

Bautura::Bautura(Bautura& bautura) {
  this->pret = bautura.pret;
}

double Bautura::get_pret() {
  return this->pret;
}

void Bautura::set_pret(double value) {
  this->pret = value;
}

// Apa
enum TipApa {
  PLATA,
  MINERALA
};

class Apa: public Bautura {
  protected:
    TipApa tip;
  public:
    Apa(double pret = 0, TipApa tip = PLATA): Bautura(pret), tip(tip) {}
    Apa(Apa&);
    friend istream& operator >> (istream&, Apa&);
    friend ostream& operator << (ostream&, Apa&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

Apa::Apa(Apa& apa) {
  this->pret = apa.pret;
  this->tip = apa.tip;
}

void Apa::citeste(istream& in) {
  string str;
  cout << "Doriti apa sa fie plata sau minerala? (0 - plata, 1 - minerala)\n";
  in >> str;

  if(str == "0") {
    this->tip = PLATA;
  } else {
    this->tip = MINERALA;
  }
}

void Apa::afiseaza(ostream& out) {
  out << "Apa ";
  switch(this->tip) {
    case PLATA:
      out << "plata\n";
    break;
    case MINERALA:
      out << "minerala\n";
    break;
  }
}

istream& operator >> (istream& in, Apa& apa) {
  apa.citeste(in);
  return in;
}

ostream& operator << (ostream& out, Apa& apa) {
  apa.afiseaza(out);
  return out;
}

// SticleBere
enum TipSticleBere {
  CU_ALCOOL,
  FARA_ALCOOL
};

class SticleBere: public Bautura {
  protected:
    TipSticleBere tip;
  public:
    SticleBere(double pret = 0, TipSticleBere tip = CU_ALCOOL): Bautura(pret), tip(tip) {}
    SticleBere(SticleBere&);
    friend istream& operator >> (istream&, SticleBere&);
    friend ostream& operator << (ostream&, SticleBere&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

SticleBere::SticleBere(SticleBere& sticleBere) {
  this->pret = sticleBere.pret;
  this->tip = sticleBere.tip;
}

void SticleBere::citeste(istream& in) {
  string str;
  cout << "Doriti berea sa fie cu alcool sau fara? (0 - cu alcool, 1 - fara alcool)\n";
  in >> str;

  if(str == "0") {
    this->tip = CU_ALCOOL;
  } else {
    this->tip = FARA_ALCOOL;
  }
}

void SticleBere::afiseaza(ostream& out) {
  out << "Sticle de bere ";
  switch(this->tip) {
    case CU_ALCOOL:
      out << "cu alcool\n";
    break;
    case FARA_ALCOOL:
      out << "fara alcool\n";
    break;
  }
}

istream& operator >> (istream& in, SticleBere& sticleBere) {
  sticleBere.citeste(in);
  return in;
}

ostream& operator << (ostream& out, SticleBere& sticleBere) {
  sticleBere.afiseaza(out);
  return out;
}

// SticleVin
enum TipSticleVin {
  BORDEAUX_1996,
  CASTEL_BOLOVANU_2004
};

class SticleVin: public Bautura {
  protected:
    TipSticleVin tip;
  public:
    SticleVin(double pret = 0, TipSticleVin tip = BORDEAUX_1996): Bautura(pret), tip(tip) {}
    SticleVin(SticleVin&);
    friend istream& operator >> (istream&, SticleVin&);
    friend ostream& operator << (ostream&, SticleVin&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

SticleVin::SticleVin(SticleVin& sticleVin) {
  this->pret = sticleVin.pret;
  this->tip = sticleVin.tip;
}

void SticleVin::citeste(istream& in) {
  string str;
  cout << "Ce tip de vin doriti? (0 - Bordeaux 1996, 1 - Castel Bolovanu 2004)\n";
  in >> str;

  if(str == "0") {
    this->tip = BORDEAUX_1996;
  } else {
    this->tip = CASTEL_BOLOVANU_2004;
  }

}

void SticleVin::afiseaza(ostream& out) {
  out << "Sticle de vin ";
  switch(this->tip) {
    case BORDEAUX_1996:
      out << "Bordeaux 1996\n";
    break;
    case CASTEL_BOLOVANU_2004:
      out << "Castel Bolovanu 2004\n";
    break;
  }
}

istream& operator >> (istream& in, SticleVin& sticleVin) {
  sticleVin.citeste(in);
  return in;
}

ostream& operator << (ostream& out, SticleVin& sticleVin) {
  sticleVin.afiseaza(out);
  return out;
}

// VinVarsat
enum TipVinVarsat {
  ROSU,
  ALB
};

class VinVarsat: public Bautura {
  protected:
    TipVinVarsat tip;
  public:
    VinVarsat(double pret = 0, TipVinVarsat tip = ROSU): Bautura(pret), tip(tip) {}
    VinVarsat(VinVarsat&);
    friend istream& operator >> (istream&, VinVarsat&);
    friend ostream& operator << (ostream&, VinVarsat&);
  protected:
    void citeste(istream&);
    void afiseaza(ostream&);
};

VinVarsat::VinVarsat(VinVarsat& vinVarsat) {
  this->pret = vinVarsat.pret;
  this->tip = vinVarsat.tip;
}

void VinVarsat::citeste(istream& in) {
  string str;
  cout << "Ce tip de vin doriti? (0 - rosu, 1 - alb)\n";
  in >> str;

  if(str == "0") {
    this->tip = ROSU;
  } else {
    this->tip = ALB;
  }
}

void VinVarsat::afiseaza(ostream& out) {
  out << "Vin varsat ";
  switch(this->tip) {
    case ROSU:
      out << "rosu\n";
    break;
    case ALB:
      out << "alb\n";
    break;
  }
}

istream& operator >> (istream& in, VinVarsat& vinVarsat) {
  vinVarsat.citeste(in);
  return in;
}

ostream& operator << (ostream& out, VinVarsat& vinVarsat) {
  vinVarsat.afiseaza(out);
  return out;
}



// Meniu
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

// Client
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


// Masa
class Masa {
  protected:
    int capacitate;
    vector<Client*> clienti;
    static int numarMese;
  public:
    Masa(int capacitate);
    Masa(Masa&);
    int get_numarMese();
    int get_locuriLibere();
    int get_numarClienti();
    Client* get_client(int);
    bool elibereazaMasa();
    bool potIntraToti(vector<Client*>);
    int adaugaClienti(vector<Client*>);
};

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

// Restaurant
class Restaurant {
    protected:
        vector<Masa*> mese;
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
        void cautaMasa(vector<Client*>);
};

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

int main() {
    (new Restaurant());
    return 0;
}
