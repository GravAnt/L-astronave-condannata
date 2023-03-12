/*
Template: Cella per Lista con Doppi Puntatori
Autore: A. Annese

Modificata da: Leandra Palemburgi
*/
#ifndef CELLA_L_DP_H_
#define CELLA_L_DP_H_

template<class T>
class Cella
{
public:
	typedef T tipoelem;
    Cella();
	~Cella();

    void scrivicella(tipoelem);
    tipoelem leggicella() const;
    void scrivisucc(Cella<T>*);
    Cella<T>* leggisucc() const;
    void scriviprec(Cella<T>*);
    Cella<T>* leggiprec() const;

private:
    tipoelem elemento;
    Cella<T>* succ;
    Cella<T>* prec;
};

template<class T>
Cella<T>::Cella()
{
    prec = nullptr;
	succ = nullptr;
}

template<class T>
Cella<T>::~Cella()
{
    //dtor
}

template<class T>
void Cella<T>::scrivicella(tipoelem label)
{
    elemento = label;
}

template<class T>
T Cella<T>::leggicella() const
{
    return elemento;
}


template<class T>
void Cella<T>::scrivisucc(Cella<T>* c)
{
    succ = c;
}

template<class T>
Cella<T>* Cella<T>::leggisucc() const
{
    return succ;
}

template<class T>
void Cella<T>::scriviprec(Cella<T>* a)
{
    prec = a;
}

template<class T>
Cella<T>* Cella<T>::leggiprec() const
{
    return prec;
}

#endif //CELLA_L_DP_H_
