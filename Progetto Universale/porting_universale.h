/* @Samuele Pesce
    File .h per permettere allo stesso progetto di funzionare sia su macchine Windows che su Linux. ( Non testato su macchine Apple ).
*/
#ifndef PORTING_UNIVERSALE_H
#define PORTING_UNIVERSALE_H

    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        #define stoVenendoEseguitoSuMacchinaWindows
    #endif // defined


    #if defined(__unix__)
        #include <unistd.h>
        #include <iostream>
        #define stoVenendoEseguitoSuMacchinaLinux
    #endif // defined

    void CLEARSCREEN();
    void SLEEP(int);

#endif // PORTING_UNIVERSALE_h

