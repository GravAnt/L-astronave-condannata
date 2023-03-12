#include "Cucina.h"

using namespace std;//
//Lista<string> Palestra::listaSchede; //Lista contenente i nomi delle schede
//Dizionario<string,Scheda> Palestra::schede;
//Coda<int> fila;8
 Lista<string>* CibiFrigo;
Lista<string>* CibiPreparazione;
 Cella<string>* posizione;
Cucina ::Cucina() {
    AggiungiCibo();
}

 void Cucina::AggiungiCibo() {
    //Cibifrigo=new Lista<string>;
CibiFrigo=new Lista<string>;
CibiPreparazione=new Lista<string>;


// inserimento cibi frigorifero
 posizione=CibiFrigo->primolista();
CibiFrigo->inslista("Carote",posizione);
 posizione=CibiFrigo->primolista();
CibiFrigo->inslista("Formaggio",posizione);
 posizione=CibiFrigo->primolista();
CibiFrigo->inslista("Macedonia",posizione);
 posizione=CibiFrigo->primolista();
CibiFrigo->inslista("Pomodori",posizione);
//


// inserimento cibi bimby
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("cipolline_in_agrodolce",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("insalata_russa",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("pure'",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("lasagne",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("marmellata",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("risotto",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("muffin",posizione);
 posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("cappuccino",posizione);
posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("pesto",posizione);
posizione=CibiPreparazione->primolista();
CibiPreparazione->inslista("nutella",posizione);
}

int Cucina::usaFrigo()
{
    string i="";
    //string risp="";
    int fine=0;

    if (CibiFrigo->listavuota()) {
        cout << "Nel frigorifero non e' rimasto piu' nulla. Prova a cercare altrove.";
        return 0;
    } else {

        cout << "Hai appena aperto il frigo\n" <<endl;
        cout << "Nel frigorifero ci sono i seguenti cibi:\n" <<endl;

        posizione=CibiFrigo->primolista();

        while (!CibiFrigo->finelista(posizione)) {
            cout << "- "+CibiFrigo->leggilista(posizione) +";"<<endl;
            posizione=CibiFrigo->succlista(posizione);
        }
        cout << "Che cibo vorresti mangiare ? \n" <<endl;
        getline(cin, i);

        posizione=CibiFrigo->primolista();
        while (!CibiFrigo->finelista(posizione) && fine==0) {
            if (i==CibiFrigo->leggilista(posizione)) {
                    fine=1;
                    CibiFrigo->canclista(posizione);
            } else {
                posizione=CibiFrigo->succlista(posizione);
            }
        }
        if (fine==1) {
            cout << "Hai appena mangiato il seguente cibo : ";
            cout << i;
            cout << "\n" <<endl;
            return 1;

        } else {
            cout << "Questo cibo non e' presente nel frigorifero.";
            return 0;
        }
    }
}

void Cucina::guardaTelevisione() {
    cout << "Hai acceso la tv. Stai guardando il canale SPACE TV" << endl;
    cout << "Scrivi 'Spegni' per spegnere la tv e tornare al tuo dovere" <<endl;
    string risposta="";
    do {
         getline(cin, risposta);
    } while(risposta!="Spegni");

    cout << "Hai spento la tv." <<endl;


}

void Cucina::preparaCibo() {
    cout << "Quale Piatto vuoi preparare ?\n" << endl;
    posizione=CibiPreparazione->primolista();
    int i=1;
    string c="";
    while (!CibiPreparazione->finelista(posizione)) {
            cout << i;
        cout <<  " - " + CibiPreparazione->leggilista(posizione) +";" << endl;
        posizione=CibiPreparazione->succlista(posizione);
        i++;
    }

    cout << "Risposta : " <<endl;
    getline(cin, c);

    if (atoi(c.c_str()) >= 1 && atoi(c.c_str()) <= 10) {
    int kk=1;
    int fine=0;
    posizione=CibiPreparazione->primolista();
            do {

                    if (atoi(c.c_str())==kk) {
                        fine =1;
                    } else {
                    kk++;
                    posizione=CibiPreparazione->succlista(posizione);
                    }
            } while(!CibiPreparazione->finelista(posizione) && fine==0);

    string temp=CibiPreparazione->leggilista(posizione);
    posizione=CibiFrigo->primolista();
    CibiFrigo->inslista(temp,posizione);
    cout << "Hai appena preparato e messo in frigo il seguente piatto : ";
    cout << temp << endl;

    } else {
        cout << "Piatto non disponibile";
    }

}


