#include "Contapassi.h"

contapassi::contapassi()
{
    numer_cont=0;
}

contapassi::~contapassi()
{
    // (inizio integrazione Spina)
    while(!traccia_passi.pilavuota())
        traccia_passi.fuoripila();

    while(!calcola.pilavuota())
        calcola.fuoripila();
    // (fine integrazione Spina)
}

void contapassi::ins_distanza(int lunghezza)
{
    calcola.inpila(lunghezza);
}

void contapassi::ins_contapassi(string luogo_attuale,string luogo_precedente)
{
    string stringaconcatenata_passi;
    stringaconcatenata_passi=("Sei andato da: " + luogo_precedente + " -> "+luogo_attuale);
    numer_cont++;//contatore inserimenti
    traccia_passi.inpila(stringaconcatenata_passi);
}

void contapassi::StampaPassi()
{
    int stampa,somma=0;

    // (inizio integrazione Spina)
    Pila<string> aus_traccia_passi;
    Pila<int> aus_calcola;
    // (fine integrazione Spina)

    string risp;                 // MODIFICA D'AVERSA
    do{
        cout<<"** Ti sei spostato "<<numer_cont<<" volta/e dall'ultima richiesta di inizio del conteggio."<<endl; // (integrazione Spina)
        if(numer_cont!=0){           //MODIFICA D'AVERSA

            interfaccia.scrivi_parziale("** Digita il numero delle ultime mosse da visionare -> ");
            cin>>stampa;//stampa è il numero di visualizzazioni richieste
            interfaccia.a_capo();
            if(stampa<=0) {

                interfaccia.scrivi("    #####################ERRORE##########################");
                interfaccia.scrivi("    ## Il valore deve essere positivo e maggiore di 0. ##");
                interfaccia.scrivi("    #####################################################");
                interfaccia.a_capo();
            }
       }
    }while(stampa<=0 && numer_cont != 0); // (integrazione Spina)

    if(numer_cont!=0){          //MODIFICA D'AVERSA

        if (stampa>numer_cont) {

            interfaccia.scrivi("    #################################################");
            interfaccia.scrivi("    ###       Le visualizzazioni richieste        ###");
            interfaccia.scrivi("    ###  sono superiori al numero di inserimenti. ###");
            interfaccia.scrivi("    ###  La vostra richiesta verra' ricalcolata   ###");
            interfaccia.scrivi("    ###       sulla base degli spostamenti        ###");
            interfaccia.scrivi("    ###        precedentemente effettuati.        ###");
            interfaccia.scrivi("    #################################################");
            interfaccia.a_capo();
            interfaccia.scrivi_parziale("> Ricalcolo");
            //SLEEP(900);
            interfaccia.scrivi_parziale(".");
            //SLEEP(850);
            interfaccia.scrivi_parziale(".");
            //SLEEP(800);
            interfaccia.scrivi_parziale(".");
            //SLEEP(750);
            interfaccia.scrivi_parziale(".");
            //SLEEP(750);
            interfaccia.a_capo();

            stampa=numer_cont;
            cout<<"Gli spostamenti effettuati: "<<stampa<<" spostamenti";
            interfaccia.a_capo();
            interfaccia.a_capo();
        }

        for(int n=0;n<stampa;n++) {

            if((traccia_passi.pilavuota()) && (calcola.pilavuota())) {

                cout<<"Non ci sono stati inserimenti.";
                interfaccia.a_capo();

            } else {

                metri=calcola.leggipila();
                cout<<traccia_passi.leggipila()<<" per "<<metri<<" metri.";
                interfaccia.a_capo();

                //INIZIO MODIFICA D'AVERSA
                aus_calcola.inpila(calcola.leggipila());
                aus_traccia_passi.inpila(traccia_passi.leggipila());

                traccia_passi.fuoripila();
                calcola.fuoripila();
                //FINE MODICA D'AVERSA
            }

            somma=metri+somma;
        }

         //INIZIO MODIFICA D'AVERSA
        while(!aus_calcola.pilavuota()) {

            calcola.inpila(aus_calcola.leggipila());
            traccia_passi.inpila(aus_traccia_passi.leggipila());

            aus_traccia_passi.fuoripila();
            aus_calcola.fuoripila();
        }
         //FINE MODICA D'AVERSA

        interfaccia.a_capo();
        cout<<"i metri dei passi richiesti: "<<somma;
        interfaccia.a_capo();
        int complessivo=somma*3;
        cout<<"lo sforzo complessivo richiesto e' stato di: "<<complessivo<<" Kcal.";
        interfaccia.a_capo();
        interfaccia.a_capo();

        //INIZIO MODIFICA D'AVERSA
        cout<<"vuoi azzerare il calcolo della distanza/sforzo?";
        cout<< "[S/N]"<<endl;
        cin>> risp;
        ;
        if(risp=="s"){

            //svuota le pile
            // traccia_passi.svuota();
            //calcola.svuota();
            numer_cont=0;
            cout<< "Azzerato correttamente!\n";
        }
    }

    cout<<"SPOSTAMENTI EFFETTUATI : "<< numer_cont<<endl;
    //FINE MODICA D'AVERSA
}
