//Inizio modifiche Lentini Giovanni
#include "scontrino.h"

scontrino::scontrino() {}

scontrino::~scontrino() {}

float scontrino::get_prezzo(){ return prezzo; }

string scontrino::get_articolo(){ return articolo; }


void scontrino::set_prezzo(float p){ prezzo = p; }

void scontrino::set_articolo(string a){ articolo = a;}
// Fine modifiche Lentini Giovanni