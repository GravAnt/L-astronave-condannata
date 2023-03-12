#ifndef CAPACITASINGOLA_H_INCLUDED
#define CAPACITASINGOLA_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Capacita_singola{
public: 										//membri pubblici della classe
    Capacita_singola(); 						//costruttori
    Capacita_singola(string,string,int,int);
    ~Capacita_singola(); 						//distruttore
    void set_luogo_capacita_singola (int); 		//funzione membro che setta il luogo della capacita
    string get_nome () const; 					//restituisce il nome della capacita
    string get_descrizione ()const; 			//restituisce la descrizione della capacita
    int get_luogo (); 							//restituisce il luogo della capacita
    int get_codice ();			 				//restituisce il codice della capacita
    void stampa_capacita_singola(); 			//funzione membro che stampa la singola capacita
    //

private: //membri privati della classe
    int codice;
    string descrizione;
    string nome;
    int luogo_capacita;
};



#endif // CAPACITASINGOLA_H_INCLUDED
