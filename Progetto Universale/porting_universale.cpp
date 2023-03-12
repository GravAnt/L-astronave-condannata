/* @Samuele Pesce
    File .cpp che implementa le funzioni per permettere allo stesso progetto di funzionare sia su macchine Windows che su Linux. ( Non testato su macchine Apple ).
*/
#include "porting_universale.h"

#if defined(_WIN32) || defined(_WIN64)
    void CLEARSCREEN() { system("cls"); }
    void SLEEP(int X) { Sleep(X); }
#endif // defined

#if defined(__unix__)
    void CLEARSCREEN() { system("clear"); }
    void SLEEP(int X) { sleep(X/1000); }
#endif // defined

