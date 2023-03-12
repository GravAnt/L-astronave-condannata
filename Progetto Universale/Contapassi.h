#ifndef CONTAPASSI_H_INCLUDED
#define CONTAPASSI_H_INCLUDED

#include<string>
#include<iostream>
#include <sstream>


#include "Pila.h"
#include "Mappa.h"
#include "Interfaccia.h"
#include "Grafo.h"
#include "Via.h"

using namespace std;

class contapassi
{
    public:
        contapassi();
        ~contapassi();

        void ins_distanza(int);
        void ins_contapassi(string,string);
        void StampaPassi();

    private:
        Pila<string> traccia_passi;
        Pila<int> calcola;

        string inserimenti;
        int numer_cont;
        int metri;
        Mappa M;
        Interfaccia interfaccia;
};

#endif // CONTAPASSI_H_INCLUDED
