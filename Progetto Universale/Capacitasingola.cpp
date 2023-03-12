#include "Capacitasingola.h"

Capacita_singola::Capacita_singola(){ //costruttore
    codice=0;
    luogo_capacita=0;
}

Capacita_singola::Capacita_singola(string n,string d,int c,int l){ //costruttore
    nome=n;
    descrizione=d;
    codice=c;
    luogo_capacita=l;
}

Capacita_singola::~Capacita_singola() {} //distruttore

void Capacita_singola::set_luogo_capacita_singola(int luogo) //funzione che setta il luogo
{
    luogo_capacita=luogo;
}

string Capacita_singola::get_nome ()const //restituisce il nome
{
    return nome;
}
string Capacita_singola::get_descrizione ()const //restituisce la descrizione
{
    return descrizione;
}

int Capacita_singola::get_luogo () //restituisce il luogo
{
    return luogo_capacita;
}

int Capacita_singola::get_codice() //restituisce il codice
{
    return codice;
}

void Capacita_singola::stampa_capacita_singola () //stampa a video la capacita
{
    cout<<"-" << get_nome () <<": " << get_descrizione () << endl;
}

