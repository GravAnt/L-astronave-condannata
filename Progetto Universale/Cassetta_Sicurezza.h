#ifndef CASSETTA_SICUREZZA_H_INCLUDED
#define CASSETTA_SICUREZZA_H_INCLUDED

#include "Oggetto.h"
#include "Interfaccia.h"
#include "Oggetti.h"

//Rimozione della struct con un solo campo

class Cassetta{
public:
    Cassetta();

    void deposita_oggetto(int, Interfaccia&, Oggetti&);
    void mostra_contenuto(Interfaccia&);
    void ritira_oggetto(int, Interfaccia&, Oggetti&);

protected:
	const int maxInt = 10;	        //--|
    Oggetto* comparti;		        //--+Modifica Samuele Pesce
    int contenuto=0;
};

#endif // CASSETTA_SICUREZZA_H_INCLUDED
