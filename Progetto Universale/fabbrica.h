#ifndef FABBRICA_H
#define FABBRICA_H

using namespace std;

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>

#include "Coda.h"

class Fabbrica
{

public:
    Fabbrica();
    virtual ~Fabbrica();
    float scelta(int);

protected:
    void crea_costruzioni();
    void costruisci(Coda<string>, int);

};
#endif
