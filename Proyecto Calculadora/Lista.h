#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
using std::cout;


struct Nodo {

	char simbolo;
	int valor;
	Nodo* sig;
	Nodo* ant;

};

struct NodoFloat {
	float valorF;
	NodoFloat* sig;
};


class Lista {

public:

	Lista();
	~Lista();


	

	Nodo* push(char simbolo, Nodo* pila);
	Nodo* insertarNodoFinalLista(char simbolo, Nodo* lista);
	Nodo* pop(char* valor, Nodo* pila);
	void mostrarExpresionPostFija(Nodo* lista);

	bool verificarParentesisBalanceados(char expresion[]);
	bool verificaElementoOperador(char simbolo);
	int obtenerPrioridadElementos(char simbolo);
	Nodo* evaluaExpresionIngresada(char expresion[]);

	int insertarValor(int valor);
	float evaluaExpresionPostFija(char expresion[]);


private:

	Nodo* inicio;
	NodoFloat* pila;
	void eliminarLista();
	NodoFloat* pushFloat(float valor, NodoFloat* pila);
	NodoFloat* popFloat(float* valor, NodoFloat* pila);
	float operacion(float operador1, float operador2, char operador);


};


#endif // !LISTA_H


