#include "Cassaforte.h"


using namespace std;

    Cassaforte::Cassaforte()
    {

        n_oggetti_sequestrati = 0;
        combinazione = 2021;
        aperta = false;
        sequestrati.creapila();
    }

    void Cassaforte::inserisci(int seq)
    {
        sequestrati.inpila(seq);
        n_oggetti_sequestrati++;
        aperta = false;
    }

    int Cassaforte::svuotaCassaforte()
    {
        int i = sequestrati.leggipila();
        sequestrati.fuoripila();
//        set_aperta(true);
        aperta = true;
        return i;
    }

    int Cassaforte::get_n_oggettiSequestrati()
    {
        return n_oggetti_sequestrati;
    }

    int Cassaforte::get_combinazione()
    {
        return combinazione;
    }

    bool Cassaforte::get_aperta()
    {
        return aperta;
    }

    void Cassaforte::set_aperta(bool i)
    {
        aperta = i;
    }

