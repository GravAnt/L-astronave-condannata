#ifndef CAPACITA_H_INCLUDED
#define CAPACITA_H_INCLUDED

#define MAXCAPACITA 15

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Capacitasingola.h"
#include "Lista.h"
using namespace std;

class Capacita {
public:

    //Operatori LISTA
    Capacita ();
    void inserisci (string,string,int,int); 					//inserisce la capacita all'interno della lista
    int get_n_capacita (); 										//restituisce il numero delle capacita all'interno della lista
    void get_capacita (Cella<Capacita_singola>*); 				//restituisce una capacita specifica
    void set_luogo_capacita(string,int);	//setta il nuovo luogo della capacita (uniche possibilita: 0 o -99)
    void elenca_capacita (); 									//elenca le capacita
    string get_nome_capacita (Cella<Capacita_singola>*);   //restituisce il nome
    int get_luogo_capacita (Cella<Capacita_singola>*);     //restituisce il luogo
    string get_descrizione_capacita(Cella<Capacita_singola>*);  //restituisce la descrizione
    Lista<Capacita_singola> get_lista_capacita();               //restituisce la capacita
    int get_codice_capacita(Cella<Capacita_singola>*);          //restituisce il codice
    void svuota ();                                             //svuota elenco capacita

    bool appartenenza (string);


private:
    Lista<Capacita_singola> capacita;
    int fine_capacita; //numero di capacita totali
};


#endif // CAPACITA_H_INCLUDED
