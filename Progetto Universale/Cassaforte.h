#ifndef CASSAFORTE_H
#define	CASSAFORTE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pila.h"
#include "Oggetti.h"

using namespace std;

class Cassaforte
{
    public:

    Cassaforte();
    void inserisci(int);
    int svuotaCassaforte();

    int get_n_oggettiSequestrati();
    int get_combinazione();
    bool get_aperta();
    void set_aperta(bool);

private:

    int n_oggetti_sequestrati;
    int combinazione;
    bool aperta;

    Pila<int> sequestrati;

};

#endif	/* CASSAFORTE_H */
