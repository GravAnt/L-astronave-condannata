//(@Integratore: Alex Spina)

/*
* Realizzazione dei servizi aggiuntivi per gli insiemi.
* Author: De Rinaldis Andrea
*/

#ifndef SERVIZI_INSIEME_HPP
#define SERVIZI_INSIEME_HPP

/*
* Metodo per lo svuotamento dell'insieme
*/
template <class T>
void svuota (Insieme<T> *insieme) {

    // definizione di un insieme vuoto
    Insieme<T> insiemeVuoto;

    // svuotamento del'insieme tramite l'operatore
    // di intersezione: l'intersezione di un
    // insieme non vuoto con un insieme vuoto
    // restituisce un insieme vuoto
    insieme->intersezione(insiemeVuoto);
}

#endif // SERVIZI_INSIEME_HPP
