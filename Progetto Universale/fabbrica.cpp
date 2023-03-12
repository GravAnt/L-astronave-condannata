#include "fabbrica.h"

    Coda<string> collana;
    Coda<string> tavolo;
    Coda<string> porta;
    Coda<string> computer;
    Coda<string> missile;

Fabbrica::Fabbrica()//costruttore in cui viene richiamata la funzione crea_costruzioni
{
    crea_costruzioni();
}

Fabbrica::~Fabbrica(){}

void Fabbrica::crea_costruzioni()//funzione che crea le code necessarie alle costruzioni
{
    //costruizione coda collana
    collana.creacoda();
    collana.incoda("Collana");//nome coda
    collana.incoda("filo");
    collana.incoda("perline");
    collana.incoda("gancio");

    //costruizione coda tavolo
    tavolo.creacoda();
    tavolo.incoda("Tavolo");//nome coda
    tavolo.incoda("piano in legno");
    tavolo.incoda("gambe");
    tavolo.incoda("giuntura");
    tavolo.incoda("viti");

    //costruizione coda porta
    porta.creacoda();
    porta.incoda("Porta in metallo");//nome coda
    porta.incoda("telaio");
    porta.incoda("pannello in metallo");
    porta.incoda("cerniera");
    porta.incoda("serratura");
    porta.incoda("maniglia");

    //costruizione coda computer
    computer.creacoda();
    computer.incoda("Computer");//nome coda
    computer.incoda("scheda madre");
    computer.incoda("processore");
    computer.incoda("scheda video");
    computer.incoda("ventola");
    computer.incoda("case");
    computer.incoda("periferiche");

    //costruizione coda missile
    missile.creacoda();
    missile.incoda("Missile");//nome coda
    missile.incoda("motore");
    missile.incoda("tubo di scarico");
    missile.incoda("sensore infrarossi");
    missile.incoda("giroscopio");
    missile.incoda("sistema di volo");
    missile.incoda("detonatore");
    missile.incoda("carica esplosiva");
    missile.incoda("scocca");
    missile.incoda("giunture");
    missile.incoda("alette");


}

void Fabbrica::costruisci(Coda<string> costruzione, int n)//funzione che permette di costruire l'elemento selezionato
{

    string s="";//variabile in cui verrà inserito l'input
    string oggetto = costruzione.leggicoda();//stringa in cui viene inserito il nome della coda
    costruzione.fuoricoda();//eliminazione dell'elemento in testa, ovvero il nome
    Coda<string> c = costruzione;//coda ausiliaria per la stampa


    cout<<"\n\n\t\t\t\t\t\t\tHai scelto di costruire '"<<oggetto<<"'!\n\n";
    string stampa[n-1];
    int v[n-1],j ,i;

    //creazione del vettore che verrà stampato
    for(j=0; j<n-1; j++)
    {
        stampa[j]=c.leggicoda();
        c.fuoricoda();
    }

    //creazione di un vettore ausiliare contenente interi randomici da 0 a n-1
    srand(time(0));
    for(i=0;i<n-1;i++) {
        v[i]=rand()%(n-1);
        for(int j=0;j<i;j++) {
       		if(v[i]==v[j]) {
                i--;
            }
         }
       }

    i=0;//indice dell'elemento del vettore che verrà aggiornato per cancellare la stringa esatta, quando selezionata
    cin.ignore();

    //ciclo che controlla l'inserimento del pezzo esatto fino alla fine della coda
    while(!costruzione.codavuota())
    {
        //stampa del vettore con indice random
        for(j=0; j<n-1; j++)
        {
            cout << "\n\t\t\t\t\t\t-" << stampa[v[j]];
        }

        cout << "\n\n\t\t\t\t\t\tInserisci il pezzo necessario in questo momento: ";

        getline (cin, s);


        if(s == costruzione.leggicoda())//se la stringa inserita è uguale all'elemento di testa della coda vai avanti
        {
            costruzione.fuoricoda();

            cout << "\n\n\t\t\t\t\t\tOTTIMO IL PEZZO ERA ESATTO\n\n";
            stampa[i]= "";//svuota elemento del vettore
            i++;
        }
        else//altrimenti stampa l'errore e ripeti
        {
            cout << "\n\n\t\t\t\t\t\tOPS! NON ERA IL MOMENTO ESATTO PER AGGIUNGERE QUEL PEZZO!\n\n";
        }

    }
    cout<<"\n\n\t\t\t\t\t\t\tHAI COSTRUITO: "<<oggetto;
}

//funzione che prende in input la scelta dell'utente e seleziona la coda
//restituisce il guadagno per aggiornare il portafoglio in Astro.cpp
float Fabbrica::scelta(int s)
{
    float guadagno = 0;
    switch(s)
    {
        case 1:

            Fabbrica::costruisci(collana, 4);
            guadagno = 2;

            return guadagno;

        break;

        case 2:

            Fabbrica::costruisci(tavolo, 5);
            guadagno = 10;

            return guadagno;

        break;

        case 3:

            Fabbrica::costruisci(porta, 6);
            guadagno = 20;

            return guadagno;

        break;

        case 4:

            Fabbrica::costruisci(computer, 7);
            guadagno = 50;

            return guadagno;

        break;

        case 5:

            Fabbrica::costruisci(missile, 11);
            guadagno = 100;

            return guadagno;

        break;

        default:
            return guadagno;
        break;
    }

}


