#ifndef CASERMA_H_INCLUDED
#define CASERMA_H_INCLUDED

#include <iostream>

using namespace std;
#include <string>
#include "Lista.h"
#include "Armi.h"

class Caserma {

public:
	Caserma();
	void mostraArmi();

private:

    Armi armiDepositate;
};

#endif // CASERMA_H_INCLUDED
