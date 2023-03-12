/**
 * @file Prioricoda.h
 * Definizione della struttura dati "Coda con priorità"
 * @note Realizzazione tramite lista ordinata
 * @author Gravina Antonio
 * @date Anno Accademico 2021/2022
 */

#ifndef _PRIORICODA_H
#define _PRIORICODA_H

#include "ListaOrdinata.h"
#include "Priorielem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class P> class Prioricoda
{
public:

    //definizione di tipo
    typedef Priorielem<P> tipoelem;

    //costruttori
    Prioricoda();
    Prioricoda(const Prioricoda<P>&);

    //distruttore di default

    //operatori di specifica
    void creaprioricoda();
    void inserisci(tipoelem);
    tipoelem min() const;
    void cancellamin();

    //operatori insiemistici
    bool insiemevuoto() const;
    bool appartiene(tipoelem) const;

private:
    ListaOrdinata<tipoelem> prioricoda;
};

template<class P> Prioricoda<P>::Prioricoda()
{
    creaprioricoda();
}

template <class P> Prioricoda<P>::Prioricoda(const Prioricoda<P>& p) //costruttore di copia
{
    creaprioricoda();
    prioricoda = p.prioricoda;
}

template<class P> void Prioricoda<P>::creaprioricoda() //crea la coda con priorità
{
    prioricoda.crealista();
}

template<class P> void Prioricoda<P>::inserisci(tipoelem a) //inserimento
{
    if(!appartiene(a))
        prioricoda.inslista(a);
}

template<class P> Priorielem<P> Prioricoda<P>::min() const //restituisce il minimo della coda
{
    tipoelem m;
    if (!prioricoda.listavuota())  //precondizione coda non vuota
        m = prioricoda.leggilista(prioricoda.primolista());
    return m;
}

template<class P> void Prioricoda<P>::cancellamin() //elimina il minimo dalla coda
{
    if (!prioricoda.listavuota())  //precondizione coda non vuota
    {
        Cella<tipoelem>* indice = prioricoda.primolista();
        prioricoda.canclista(indice);
    }
}

template<class P> bool Prioricoda<P>::insiemevuoto() const //verifica se la coda è vuota
{
    return (prioricoda.listavuota());
}

template<class P> bool Prioricoda<P>::appartiene(tipoelem a) const //verifica se l'elemento appartiene alla coda
{
    bool trovato = false;
    if (!prioricoda.listavuota())
    {
        Cella<tipoelem>* indice = prioricoda.primolista();
        while (!prioricoda.finelista(indice) && !trovato)
        {
            if (prioricoda.leggilista(indice) == a)
                trovato = true;
            else indice = prioricoda.succlista(indice);
        }
    }
    return(trovato);
}

#endif
