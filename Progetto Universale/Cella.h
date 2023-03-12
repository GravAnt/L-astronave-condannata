#ifndef CELLA_H_INCLUDED
#define CELLA_H_INCLUDED

template<class T> class Cella{
	public:
    typedef T tipoelem;
    typedef Cella<T>* posizione;
	Cella();
	tipoelem leggiCella() const;
	void scriviCella(tipoelem);
	posizione getsucc()const;
	void setsucc(posizione);
	bool operator == (Cella);
private:
	tipoelem etichetta;
	posizione suc;
};

template<class T> Cella<T>::Cella(){}

template<class T> typename Cella<T>::tipoelem Cella<T>::leggiCella()const{
	return etichetta;
}
template<class T> void Cella<T>::scriviCella(tipoelem e){
	etichetta=e;
}
template<class T> typename Cella<T>::posizione Cella<T>::getsucc()const{
	return suc;
}
template <class T> void Cella<T>::setsucc(posizione c){
	suc=c;
}

template <class T> bool Cella<T>::operator ==(Cella cella){
	return(leggiCella()==cella.leggiCella());
}


#endif // CELLAA_H_INCLUDED
