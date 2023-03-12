//(@Integratore: Alex Spina)

#ifndef NODO_GRAFO_H
#define NODO_GRAFO_H

class Nodo_Grafo{
public:
	Nodo_Grafo();
	int getNodo();
	void setNodo(int);
	bool operator ==(Nodo_Grafo);

private:
	int nodo;
};



#endif // NODO_GRAFO_H
