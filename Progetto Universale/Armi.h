#ifndef ARMI_H
#define	ARMI_H


#include <iostream>
#include <string>
#include <stdlib.h>
#include "Lista.h"
#include "servizioLista.h"
#include "Arma.h"

using namespace std;

class Armi
{
public:
    Armi ();

    void inserisci (string nome, string desc);
    int get_n_Armi();

    string get_Arma(int);
    string get_nome_Arma(int);
    string get_descrizione_Arma(int);

    void elenca_Armi();

private:

    Lista<Arma> l_Armi;
    int n_Armi;
    Lista<Arma>::posizione pos;
};


#endif	/* Armi_H */

