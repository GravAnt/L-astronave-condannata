#ifndef CUCINA_H_INCLUDED
#define CUCINA_H_INCLUDED
#include "Lista.h"
#include <Windows.h>
#include <sstream>
#include <string>
#include <iostream>

class Cucina
{
public:
    Cucina();
    int usaFrigo();
    void AggiungiCibo();
    void guardaTelevisione();
    void preparaCibo();


private:
     Lista<string>* CibiFrigo;
     Lista<string>* CibiPreparazione;

};


#endif // CUCINA_H_INCLUDED
