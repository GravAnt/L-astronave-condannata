#include "Caserma.h"

Caserma::Caserma(){
    armiDepositate.inserisci("fucile di precisione", "arma da fuoco");
    armiDepositate.inserisci("fucile", "fucile a canna liscia");
    armiDepositate.inserisci("mitragliatrice", "arma da fuoco");
}

void Caserma::mostraArmi(){
	armiDepositate.elenca_Armi();

}
