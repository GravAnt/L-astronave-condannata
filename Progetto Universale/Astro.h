#ifndef ASTRO_H
#define ASTRO_H

/* 100 - 140
 ##  AVVENTURA: L'ASTRONAVE CONDANNATA   ##
 ## di Enrico Colombini e Chiara Tovena  ##
 ## (C) 1985 DINOSOFT E JACKSON EDITRICE ##
 - versione in linguaggio C di Stefano Ferilli -
 */
#include "Gioco.h"
#include "DescData.h"
#include "Lista.h"
#include "Oggetti.h"
#include <ctime>
#define MAX_LIBRI 100
#define TEMPO 50

#include "Portafoglio.h"    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
#include "CartadiCredito.h" //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
#include "servizioLista.h"
#include "Lista.h" //implementato da Lentini Giovanni
#include "Pila.h" //implementato da Lentini Giovanni
#include "scontrino.h" //implementato da Lentini Giovanni

#include "fabbrica.h" //MODIFICA PIERLUIGI BEMPORTATO



class Astro: public Gioco
{
public:
    Astro();
    virtual ~Astro();
    int getParete();
    int getCabina();
    void setParete(int);
    void setCabina(int);
    void aggiorna_specifiche(); //biblioteca

private:

    //inizio moficifhe biblioteca scatigna
    int scadenze[10]={TEMPO,TEMPO,TEMPO,TEMPO,TEMPO,TEMPO,TEMPO,TEMPO,TEMPO,TEMPO};
    int i;
    Lista<int> libriInPrestito;
    //fine modifiche biblioteca bibioteca

    int parete_stagna_aperta; // parete_stagna_aperta BOOLEAN!
    int cabina_aperta;

    //Inizio modifiche Zagaria -- aggiunta inizializzazione lista oggetti
    Lista<Oggetti> lisOggetti;
    //fine modifiche

    //MODIFICA D-R(D'Orsi):Negozio + Banca
    bool soldi_presi_armadietto; // per far prendere i soldi una sola volta
    bool gia_prelevato;

//inizio modifiche Giovanni Lentini
 scontrino ricevuta;
        Lista<scontrino> acquisti;
        typename Lista<scontrino>::posizione punt=0;
        Pila<int> lotteria;
        int num_biglietti=0;




    //metodi
    void init_specifiche();
    void introduzione();
    void tempo_specifiche();
    // modifica Angelo Petronelli
    bool esegui_specifiche(int,Mappa&);
    // fine modifica
    bool prendi_specifiche();
    bool preso_specifiche();
    bool aperto;
    bool lascia_specifiche();
    void save_specifiche(ofstream &);
    void load_specifiche(ifstream &);
    void epitaffio();
    void passato();
    void futuro();
    void presente();
    void setmappapassato(bool);
    bool mappaaperta();
    void encomio();
    void azione_10();
    void azione_11();
    void azione_12();
    void azione_13();
    void azione_14();
    void azione_15();
    void azione_16();
    void azione_17();
    void azione_18();
    void azione_19();
    void azione_20();
    void azione_21();
    void azione_22();
    void azione_23();
    void azione_24();
    void azione_25();
    void azione_26();
    void azione_27();
    void azione_28();
    void azione_29();
    void azione_30();
    void azione_31();
    void azione_32();
    void azione_33();
    void azione_34();
    void azione_35();
    void azione_36();
    // modifica Angelo Petronelli
    void azione_37(Mappa&);
    void azione_38(Mappa&);
    // fine modifica

    //Modifica PMF(ufficio)
    void azione_44();
    void azione_45();
    //Modifica PMF: fin qui.

    void azione_50();//Modifica PMF(per storia)

    //MODIFICA D-R(fabio):Negozio + Banca: nuove azioni per negozio e banca
    void azione_51(); // parla mercante
    void azione_52(); // compra oggetto
    void azione_53(); // saluta mercante
    void azione_54(); // controlla portafogli
    void azione_55(); // parla impiegato
    void azione_56(); // deposita denaro
    void azione_57(); // saluta impiegato
    void azione_58(); // controlla conto
    void azione_59(); // preleva denaro
    void azione_60(); // apri cassetta
    void azione_61(); // ritira oggetto

    //MODIFICA D-R(Colturi):Luoghi a Pagemento
    void azione_62(Mappa&, int); // Entra in Luogo a Pagamento
    void azione_63(Mappa&);		 // Leggi Insegna Luminosa

    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    void azione_66();	  // Controlla Carta di Credito

    //Modifiche Francesco Cosma - Premi

    void azione_68();
    //START DAMONE
    // modifica Francesco De Giorgio
    void cerca();
    //END DAMONE
    //INIZIO MODIFICHE MICHELE ALBANO
    void azione_67(); //Azione Salute
    void azione_69(); //Azione usa terminale nel Pronto Soccorso
    //FINE MODIFICHE MICHELE ALBANO

    //INIZIO MODIFICHE GIOVANNI CASTELLANA
    void azione_70(); //Azione per confessarti nel confessionale
    void azione_71(); //Azione per sederti sulla panchina
    void azione_72(); //Azione di supporto all'azione 71
    void azione_73();
    void azione_74(); //Azione per pregare
    //FINE MODIFICHE GIOVANNI CASTELLANA

    // modifiche Gallone

    void azione_75(); //appetito-fame-Fame
    void azione_76(); //acquista-compra
    void azione_77(); //mangia
    void azione_78(); //controlla contenuto tasca
    void azione_79(); //controlla zaino frigo

    //fine modifiche Gallone

    void azione_80();	//Modifica DELLA FOLGORE GRAZIA - Guarda automobile

    //Modifiche Galeandro da Progetto Bellanova
    void azione_82();//Guarda Ufficio Postale
    void azione_83();//Apri Pacco
    void azione_84();//Leggi Lettera
    //Fine Modifiche Galeandro


    //INIZIO modifiche Moschetti
    void azione_85();//Siediti per riposarti
    void azione_86();//Leggi i libri presenti nell'aula
    void azione_87();//Fare delle ricerche al computer
    void azione_88();//Seguire la lezione
    void azione_89();//Accendi il proiettore
    void azione_90();//Spegni il proiettore
    //FINE modifiche Moschetti

    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    void azione_91();//uso del computer nell'archivio
    void azione_92();//lettura file 12
    void azione_93();//lettura file 13
    void azione_94();//lettura file 15
    void azione_95();//lettura file 21
    void azione_96();//ingresso nel museo
    //FINE MODIFICHE DEL GIUDICE ANGELO

    //INIZIO MODIFICHE BASILE ANTONIO
    void azione_97(); //lettura del registro
    void azione_98(); //guarda lavagna gioco dell'impiccato
    void azione_100(); //parla con il preside
    void azione_101(); //parla con la maestra Clara
    void azione_102(); //parla con la maestra Mara
    void azione_103(); //guarda cartina Galattica
    void azione_104(); //guarda cartina Geografica
    //FINE MODIFICHE BASILE ANTONIO

    //INIZIO MODIFICHE VACCA GIANLUCA
    void inizializza_Jukebox(); //permette di inizializzare il jukebox. Separato per ordinare il codice.
    void azione_105(); //usa proiettore rotto
    void azione_106(); //guarda schermo auditorium
    void azione_107(); //guarda dalla finestra dell'auditorium
    void azione_108(); //Usa il microfono spento nell'auditorium
    void azione_109(); //Usa il Jukebox nell'auditorium
    void azione_110(); //Guarda gli strumenti musicali
    void azione_111(); //Suona uno strumento musicale
    void azione_112(); //Interagisci col pannello delle luci
    void azione_113(); //Interagisci con la scacchiera
    //FINE MODIFICHE VACCA GIANLUCA

    //INIZIO modifiche SALVATORE VESTITA
    void azione_114();//Siediti sulla panchina
    void azione_115();//Usa biglietteria
    void azione_116();//leggi giornale
    void azione_117();//Sali sul treno
    void azione_118(); // Azione relativa al teletrasporto verso e dall'astronave aliena, gestita rispetto al luogo_attuale
    void azione_119(); //Azione puramente descrittiva, che spinge il giocatore ad uscire all'esterno per utilizzare la pietra canalizzatrice.
    //FINE modifiche SALVATORE VESTITA

    //INIZIO modifiche DAVIDE MANTELLINI
    void azione_120(); //Usa la panca
    void azione_121(); //Usa tapis
    void azione_122(); //Leggi terminale informativo
    void azione_123(); //Usa schede
    void azione_124();
    //FINE modifiche DAVIDE MANTELLINI

    //INIZIO MODIFICHE CICALA GIACOMO
    void azione_125(); //Usa macchinetta
    //FINE MODIFICHE CICALA GIACOMO

    //inizio moficifhe biblioteca scatigna
    void libro();
    void azione_126(); // Lettura etichetta
    void azione_127(); // Apertura vetrina
    void azione_128(); // Chiusura vetrina
    void azione_129(); // Leggi libri
    void scadenza();

    //fine modifiche biblioteca scatigna

    //INIZIO modifiche PALAGIANO MARCELLO
    void azione_130(); //guarda banco da lavoro
    void azione_131(); //guarda ricambio astronave
    void azione_132(); //guarda pila di batterie
    void azione_133(); //guarda batterie scariche
    void azione_134(); //guarda chiave inglese
    void azione_135(); //guarda diario
    void azione_136(); //leggi diario
    void azione_137(); //guarda cartello
    void azione_138(); //guarda computer
    void azione_139(); //parla meccanico
    //FINE modifiche PALAGIANO MARCELLO

    //INIZIO MODIFICHE FLAVIO COLLOCOLA
    void azione_140(); //Consegna documento
    void azione_141(); //Ritira documento
    //FINE MODIFICHE FLAVIO COLLOCOLA
//inizio modifiche Lentini Giovanni
     void azione_146(); //leggi-guarda-vedi orari
     void azione_142(); //gioca lotteria
     void azione_143(); //compra-acquista-prendi sale
     void azione_144(); //compra-acquista-prendi sigarette
     void azione_145(); //buonus-usa elaboratore(bonus)
    //fine modifiche Lentini Giovanni

    // (inizio modifiche SPINA)
	void azione_147(); // stampa info su sforzo del personaggio
    //(fine modifiche SPINA)

    //INIZIO MODIFICHE PIERLUIGI BEMPORTATO
    void azione_148();//parla con fabbricante
    //FINE MODIFICHE PIERLUIGI BEMPORTATO

     //inizio modifiche Bagordo Simone
     void azione_149();
     //fine modifiche Bagordo Simone

	//Implementazione di Samuele Pesce dal progetto di Roberto Carlucci.
	void azione_150();
	void azione_151();
	void azione_152();
	//Fine modifica Samuele Pesce

	//inizio modifiche Davide Rano
	void azione_153();
	void azione_154();
	void azione_155();
	void azione_156();
	//fine modifiche Davide Rano

    //inizio modifiche Bottiglione Margareth
    void azione_157(); //analisi diabete e colesterolo
    //fine modifiche Bottiglione Margareth

    //INIZIO modifiche De Florio Cristina
    void azione_158(Mappa &);
    //FINE modifiche De Florio Cristina

    //inizio modifiche Costantini Andrea
    void azione_159(); //mangia barretta energetica
    void azione_160(); //mangia pizza
    void azione_161();  //apri frigorifero
    void azione_162(); // guarda televisione
    void azione_163(); // preparazione cibi
    void azione_164(); //mangia mela
   //fine modifiche Costantini Andrea

   //inizio modifiche Baso Matteo
   void azione_165(); // comando "oggetti"
   //fine modifiche Baso Matteo

   //inizio modifiche Gravina Antonio
   void azione_166(); // elenca capacità
   void azione_167(); // elimina capacità
   void azione_168(); // guarda motorino
   void azione_169(); // leggi foglio
   void azione_170(); // guarda poster
   void azione_171(); //parla vagabondo
   //fine modifiche Gravina Antonio

};

#endif
