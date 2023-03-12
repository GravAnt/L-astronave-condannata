//(@Integratore: Alex Spina)

#include "Nodo_Grafo.h"
Nodo_Grafo::Nodo_Grafo(){
	nodo=-1;
}
int Nodo_Grafo::getNodo(){
	return nodo;
}
void Nodo_Grafo::setNodo(int n){
	nodo=n;
}
bool Nodo_Grafo::operator ==(Nodo_Grafo x)
{
    return( this->nodo==x.nodo);
}

