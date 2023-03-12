// Fine modifiche Lentini Giovanni
#ifndef SCONTRINO_H
#define SCONTRINO_H
#include <string>
#include <iostream>
using namespace std;

class scontrino
{
    public:
         scontrino();
         ~scontrino();
    float get_prezzo();
    string get_articolo();
    void set_prezzo(float);
    void set_articolo(string);

    private:

      float prezzo;
      string articolo;
};

#endif // SCONTRINO_H

// Fine modifiche Lentini Giovanni
