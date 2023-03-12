/**
 * @file Grafo.h
 * Definizione struttura dati Grafo realizzata mediante Matrice di Adiacenza
 * @author Graziano Montanaro.
 * @date Anno Accademico 2018/19.
 * Modificato da Gravina Antonio
 */

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "CellaGrafo.h"
#include "CellaNodo.h"
#include <iostream>
#include "Lista.h"
#define maxNodi 50


template <class tipoElem, class tipoPeso>
class Grafo
{
public:
    class nodo;
    Grafo();
    ~Grafo();
    void creagrafo();
    bool grafovuoto() const;
    void insarco(nodo&,nodo&);
    void cancarco(nodo&,nodo&);
    void insnodo(nodo &);
    void cancnodo(nodo&);
    Lista<nodo> adiacenti(nodo&) const;
    bool esistenodo(nodo&) const;
    bool esistearco(nodo&,nodo&) const;
    void scrivinodo(tipoElem,nodo);
    void scriviarco(tipoPeso,nodo&,nodo&);
    tipoElem legginodo(nodo&) const;
    tipoPeso leggiarco(nodo,nodo) const;


private:

        unsigned int nodiUsati;
        unsigned int primoLibero();
        CellaGrafo<tipoPeso> matrice[maxNodi][maxNodi];
        CellaNodo<tipoElem> nodi[maxNodi];
};


// Definizione del tipo nodo

template <class tipoElem, class tipoPeso>
class Grafo<tipoElem,tipoPeso>::nodo
{
public:
    nodo();
    nodo(const nodo&);
    ~nodo();
    int getNodo();
    void scrivinodo(int n);
    bool  operator == ( const nodo& );
    bool  operator != ( const nodo& );


private:
    int valore;
};



template <class tipoElem, class tipoPeso>
Grafo<tipoElem , tipoPeso>::Grafo()
{
    nodiUsati = 0;
    for(int i=0;i<maxNodi;i++)
    {
        nodi[i].setPresente(false);
        for(int j=0;i<maxNodi;i++)
            matrice[i][j].setUsato(false);
    }
}

template <class tipoElem, class tipoPeso>
Grafo<tipoElem , tipoPeso>::~Grafo()
{

}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem , tipoPeso>::grafovuoto() const
{
    return nodiUsati == 0;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem, tipoPeso>::esistenodo(nodo &n) const
{
    if(n.getNodo()>=0 && n.getNodo()<nodiUsati)
        return nodi[n.getNodo()].getPresente();
    else
        return false;
}

template <class tipoElem, class tipoPeso>
tipoPeso Grafo<tipoElem , tipoPeso>::leggiarco(nodo n1, nodo n2) const
{
    if(esistearco(n1,n2))
        return matrice[n1.getNodo()][n2.getNodo()].getPeso();


}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::insnodo(nodo & n)
{
    if(!esistenodo(n))
    {
        if(nodiUsati<maxNodi)
        {
            unsigned int  i = primoLibero();
            nodi[i].setPresente(true);
            nodi[i].setArchi(0);
            n.scrivinodo(i);
            nodiUsati++;
        }
    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::cancnodo(nodo& n)
{
    if(esistenodo(n))
    {
        nodo* temp = new nodo;
        for(int i=0;i<nodiUsati;i++)
        {
            temp->scrivinodo(i);
            if(esistearco(*temp,n))
                cancarco(*temp,n);
            if(esistearco(n,*temp))
                cancarco(n,*temp);
        }
        nodi[n.getNodo()].setPresente(false);
        nodiUsati--;
    }

}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::insarco(nodo &n1, nodo &n2)
{
    if(!esistearco(n1,n2))
    {
        matrice[n1.getNodo()][n2.getNodo()].setUsato(true);
        nodi[n1.getNodo()].setArchi(nodi[n1.getNodo()].getArchi()+1);
        nodi[n2.getNodo()].setArchi(nodi[n2.getNodo()].getArchi()+1);
    }


}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::cancarco(nodo& n1, nodo& n2)
{
    if(esistearco(n1,n2))
    {
        matrice[n1.getNodo()][n2.getNodo()].setUsato(false);
        nodi[n1.getNodo()].setArchi(nodi[n2.getNodo()].getArchi() -1);
        nodi[n2.getNodo()].setArchi(nodi[n2.getNodo()].getArchi() -1);

    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::scrivinodo(tipoElem e, nodo n)
{
    if(esistenodo(n))
    {
        nodi[n.getNodo()].setEtichetta(e);
    }

}

template <class tipoElem, class tipoPeso>
tipoElem Grafo<tipoElem , tipoPeso>::legginodo(nodo& n) const
{
    if(esistenodo(n))
    {
        return nodi[n.getNodo()].getEtichetta();
    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::scriviarco(tipoPeso p,nodo& n1, nodo& n2)
{
    if(!esistearco(n1,n2))
    {
        matrice[n1.getNodo()][n2.getNodo()].setPeso(p);
    }

}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem , tipoPeso>::esistearco(nodo& n1, nodo& n2) const
{
    if(esistenodo(n1) && esistenodo(n2))
            return matrice[n1.getNodo()][n2.getNodo()].getUsato();

}


template <class tipoElem, class tipoPeso>
Lista<typename Grafo<tipoElem,tipoPeso>::nodo> Grafo<tipoElem , tipoPeso>::adiacenti(nodo& n) const
{
    Lista<nodo> l;
    typename Lista<nodo>::posizione p = l.primolista();
    for(int i=0;i<nodiUsati;i++)
    {
        if(matrice[n.getNodo()][i].getUsato())
        {
            nodo* temp = new nodo();
            temp->scrivinodo(i);
            l.inslista(*temp,p);
        }
    }
    // Nodi di cui n è coda
    /*for(int i=0;i<nodiUsati;i++)
    {
        if(matrice[i][n].getUsato())
            if(!matrice[n][i].getUsato())
            l.inslista(i,p);
    }*/
    return l;
}

template <class tipoElem, class tipoPeso>
unsigned int Grafo<tipoElem,tipoPeso>::primoLibero()
{
     nodo i;
     i.scrivinodo(-1);
    bool libero=false;
    while(!libero)
    {
        i.scrivinodo(i.getNodo()+1);
        if(nodi[i.getNodo()].getPresente()==false)
            libero = true;
    }
    return i.getNodo();
}

//Operatori NODO

template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::nodo()
{
   valore = -1;
}



template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::nodo(const nodo& n)
{
   valore = n.valore;
}



template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::~nodo()
{

}


template <class tipoElem, class tipoPeso>
int Grafo<tipoElem,tipoPeso>::nodo::getNodo()
{
    return valore;
}


template <class tipoElem, class tipoPeso>
void Grafo<tipoElem,tipoPeso>::nodo::scrivinodo(int n)
{
    valore = n;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::nodo:: operator == ( const nodo& n)
{
    return valore == n.valore;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::nodo:: operator != ( const nodo& n)
{
    return valore != n.valore;
}


#endif // GRAFO_H_INCLUDED
