#include <cstdlib>
#include <iostream>
#include "Mappa.h"
#include "Astro.h"
#include "porting_universale.h"
using namespace std;

int main(int argc, char *argv[])
{
    #ifdef stoVenendoEseguitoSuMacchinaWindows
        system("title Adventure with Simunav");     //imposto header della finestra dos                                                                         --\
       // system("mode con line=100");              //imposto la larghezza della finestra dos - Togliere commento se si vuole una schermata più lunga che larga --| Modifica di Samuele Pesce
         cout<<"[ E' stata rilevata una macchina su S.O Windows ]"<<endl;
    #endif // defined

    #ifdef stoVenendoEseguitoSuMacchinaLinux
        cout<<"[ E' stata rilevata una macchina su S.O Linux ]"<<endl;
        std::cout << "\033]0;" << "Adventure with Simunav" << "\007"; // Permette di inserire il titolo all'applicazione su Linux -- Modifica di Samuele Pesce
    #endif // stoVenendoEseguitoSuMacchinaLinux

    fstream crono("Cronologia.odb",fstream::in); //apro il file su cui è presente la cronologia

    ifstream f("Mappa.nav",ios::in);	 //apro il file su cui ho rappresentato la mappa
    if (f.good()) 						 //se il file di input è stato aperto correttamente
    {
        Mappa M(f,crono); //istanzio la mappa
        Astro partita = Astro();
        partita.ciak(M,f);


    }
    else cout<<"Errore apertura file \"Mappa.nav\""<<endl; //altrimenti stampa messaggio di errore

	f.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}






// I comandi che mi interessano sono:   INVENTARIO - DEPOSITA - CONTROLLA - RITIRA
