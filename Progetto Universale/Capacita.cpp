#include "Capacita.h"

Capacita::Capacita (){
    capacita.crealista();
    fine_capacita = 1;
};

//inserimento in Lista
void Capacita::inserisci(string n,string d,int c,int l){
    if (fine_capacita<MAXCAPACITA){
        Cella<Capacita_singola>* temp = capacita.primolista();
        while(!capacita.finelista(temp)) //MODIFICA TOMAI
        {
            temp=capacita.succlista(temp);
        }
        //FINE
        Capacita_singola cap(n,d,c,l);
        capacita.inslista(cap, temp);
        fine_capacita++;
    }
}

int Capacita::get_n_capacita(){
    return fine_capacita;
}

void Capacita::get_capacita(Cella<Capacita_singola>* i){
    capacita.leggilista(i).stampa_capacita_singola();
}

//MODIFICA luogo capacità presente in lista
void Capacita::set_luogo_capacita(string nome, int luogo){
    Cella<Capacita_singola>* indice = capacita.primolista();
    while(!capacita.finelista(indice)){
        if(capacita.leggilista(indice).get_nome()==nome){
            Capacita_singola cap(get_nome_capacita(indice),get_descrizione_capacita(indice),get_codice_capacita(indice),luogo);
            capacita.canclista(indice);
            indice = capacita.primolista();
            capacita.inslista(cap, indice);
        }
        indice = capacita.succlista(indice);
    }
}

//Lettura nome capacita in LISTA
string Capacita::get_nome_capacita(Cella<Capacita_singola>* i){
    return capacita.leggilista(i).get_nome();
}

//Lettura luogo capacità in LISTA
int Capacita::get_luogo_capacita (Cella<Capacita_singola>* i){
    return capacita.leggilista(i).get_luogo();
}

//Lettura descrizione capacita in LISTA
string Capacita::get_descrizione_capacita(Cella<Capacita_singola>* i){
    return capacita.leggilista(i).get_descrizione();
}

//Lettura codice capacita in LISTA
int Capacita::get_codice_capacita(Cella<Capacita_singola>* i){
    return capacita.leggilista(i).get_codice();
}

//Stampa elenco capacita con LISTA
void Capacita::elenca_capacita () {
    Cella<Capacita_singola>* indice = capacita.primolista();
    while (!capacita.finelista(indice)){
        if (capacita.leggilista(indice).get_luogo() == 0)
            get_capacita(indice);
        indice = capacita.succlista(indice);
    }
}

void Capacita::svuota() {
    capacita.~Lista();
    fine_capacita=0;
}

//Lista capacita con LISTA
Lista<Capacita_singola> Capacita::get_lista_capacita(){
    return capacita;
}
