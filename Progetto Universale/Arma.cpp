#include "Arma.h"
#include <iostream>

Arma::Arma()
{
    descrizione="";
    nome="";
}

Arma::Arma(string n, string d)
{
    nome = n;
    descrizione = d;
}

Arma::~Arma() {}

string Arma::get_descrizione() const
{
    return descrizione;
}

void Arma::set_descrizione(string d)
{
    descrizione = d;
}

string Arma::get_nome() const
{
    return nome;
}

void Arma::set_nome(string n)
{
    nome = n;
}

string Arma::stampa_Arma() const
{
    return get_nome()  + " - " + get_descrizione() + "\n";
}

