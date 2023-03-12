#ifndef ARMA_H
#define	ARMA_H
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

class Arma
{

public:
    Arma();
    Arma(string nome,string descrizione);
    ~Arma();

    string get_nome() const;
    void set_nome(string);

    string get_descrizione () const;
    void set_descrizione (string);

    string stampa_Arma() const;

private:

    string nome;
    string descrizione;

};


#endif	/* ARMA_H */
