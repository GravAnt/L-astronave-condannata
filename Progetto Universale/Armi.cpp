#include "Armi.h"

Armi::Armi()
{
    n_Armi= 0;   //prima era n_armi = 1
}

void Armi::inserisci(string n, string d)
{

        pos = posizioneFisicaDaLogica(l_Armi, n_Armi );     //prima n_armi -1
        l_Armi.inslista(Arma(n, d),pos);
        n_Armi++;

}

int Armi::get_n_Armi()
{
    return n_Armi;
}

string Armi::get_Arma(int i)
{
    pos = posizioneFisicaDaLogica(l_Armi, i);
    return l_Armi.leggilista(pos).stampa_Arma();
}

string Armi::get_nome_Arma(int i)
{
    pos = posizioneFisicaDaLogica(l_Armi, i);
    return l_Armi.leggilista(pos).get_nome();
}

string Armi::get_descrizione_Arma(int i)
{
    pos = posizioneFisicaDaLogica(l_Armi, i);
    return l_Armi.leggilista(pos).get_descrizione();
}

void Armi::elenca_Armi()
{
    int i;

    for (i = 0 ; i < get_n_Armi() ; i++)    // prima stava i < get_n_Armi() -1
    {
        cout << get_Arma(i);
    }
}
