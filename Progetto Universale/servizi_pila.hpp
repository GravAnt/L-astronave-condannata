//(@Integratore: Alex Spina)

/*
* Realizzazione dei servizi aggiuntivi per le pile.
* Author: De Rinaldis Andrea
*/

#ifndef SERVIZI_PILA_HPP
#define SERVIZI_PILA_HPP

/*
* Metodo per la stampa della pila
*/
template <class T>
void stampa(Pila<T> &pila) {

	Pila<T>* pilaAppoggio = new Pila<T>();

	while(!pila.pilavuota()) {

		pilaAppoggio->inpila(pila.leggipila());
		std::cout << pilaAppoggio->leggipila() << ", ";
		pila.fuoripila();
	}

	while(!pilaAppoggio->pilavuota()) {

		pila.inpila(pilaAppoggio->leggipila());
		pilaAppoggio->fuoripila();
	}
}

#endif // SERVIZI_PILA_HPP
