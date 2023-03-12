#ifndef LISTA_H_
#define LISTA_H_
#include "Cella_L_DP.h"

#include <iostream>
using namespace std;

template<class L>
class Lista {
public:
    typedef Cella<L>* posizione;
    typedef L tipoelem;

	Lista(); //costruttore
	Lista(const Lista<L>&); //costruttore di copia
	~Lista(); //distruttore
	//operatori

    void crealista();
    bool listavuota() const;
    bool finelista(posizione) const;
    posizione primolista() const;
    posizione succlista(posizione) const;
    posizione preclista(posizione) const;
    tipoelem leggilista(posizione) const;
    void scrivilista(tipoelem, posizione);
    void inslista(tipoelem, posizione&);
    void canclista(posizione &);

private:
    posizione lista;
};


template <class L>
Lista<L>::Lista() { crealista(); }

template <class L>
Lista<L>::Lista(const Lista& b) {

    crealista();
    typename Lista<L>::posizione ind = primolista(),ind2 = b.primolista();
    while (!b.finelista(ind2))
    {
        inslista(b.leggilista(ind2),ind);
        ind = succlista(ind);
        ind2 = b.succlista(ind2);
    }
}

template <class L>
Lista<L>::~Lista() {
    posizione p = primolista();
    while(p->leggisucc() != nullptr)
    {
        posizione temp = p;
        p=p->leggisucc();
        delete temp;
    }
}

template <class L>
void Lista<L>::crealista() {
    lista = new Cella<L>;
    lista->scrivisucc(nullptr);
    lista->scriviprec(nullptr);
}

template <class L>
bool Lista<L>::listavuota() const {
    return (lista->leggiprec() == nullptr && lista->leggisucc() == nullptr);
}

template <class L>
bool Lista<L>::finelista(posizione pos) const {
    return (pos->leggisucc() == nullptr);
}

template <class L>
typename Lista<L>::posizione Lista<L>::primolista() const {
    return lista;
}

template <class L>
typename Lista<L>::posizione Lista<L>::succlista(posizione pos) const {
    if (lista->leggisucc() != nullptr)
        return (pos->leggisucc());
    else
        return pos;
}

template <class L>
typename Lista<L>::posizione Lista<L>::preclista(posizione pos) const {
    typename Lista<L>::posizione temp = primolista();
    if(pos == temp)
        temp = nullptr;
    else
    {
        while(succlista(temp) != pos)
            temp = succlista(temp);
    }
    return temp;
}

template <class L>
L Lista<L>::leggilista(posizione pos) const {
    return (pos->leggicella());
}

template <class L>
void Lista<L>::scrivilista(tipoelem elem, posizione pos) {
    pos->scrivicella(elem);
}

template <class L>
void Lista<L>::inslista(tipoelem elem, posizione &pos) {
    typename Lista<L>::posizione temp;
    temp = new Cella<L>;
    temp->scrivicella(elem);
    temp->scrivisucc(pos);
    temp->scriviprec(pos->leggiprec());


    if (pos == primolista())
        lista = temp;
    else
        preclista(pos)->scrivisucc(temp);
    pos = temp;
}

template <class L>
void Lista<L>::canclista(posizione & pos) {


    posizione temp;
    temp = pos;

    if(pos == primolista()){
        if(pos->leggisucc() != nullptr) {
            lista = pos->leggisucc();
            lista->scriviprec(nullptr);
        }
    } else {
        preclista(pos)->scrivisucc(pos->leggisucc());
        //succlista(pos)->scriviprec(preclista(pos));//modifiche di Matteo Baso
        succlista(pos)->scriviprec(pos->leggiprec());//modifiche di Matteo Baso
    }

    pos = pos->leggisucc();
    delete temp;
}
#endif // LISTA_H_

