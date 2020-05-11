#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
//using std::cout;


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

	
	void mostrarExpresionPostFija(Nodo* lista);

	bool verificarParentesisBalanceados(char expresion[]);
	int verificaElementoOperador(char simbolo);
	int obtenerPrioridadElementos(char simbolo);
	float recorreExpresionPost(Nodo* expresionPost);
	int insertarValor(int valor);
	float evaluaExpresionPostFija(char expresion[]);


	// -------    M E T O D O S  C A L C U L A D O R A  U S A D O S    ------------
	int clasificaGradoExpresion(char expresion[]);
	Nodo* push(char simbolo, Nodo* pila);
	Nodo* insertarNodoFinalLista(char simbolo, Nodo* lista);
	Nodo* pop(char* valor, Nodo* pila);
	Nodo* craerLista(Nodo*);

	// G R A D O  I
	Nodo* getExpresionGradoIPost(char expresion[]);
	float getResultadoExpresionGradoIPost(char expresion[]);
	// G R A D O  I I 
	float getResultadoExpresionGradoIIPost(char expresion[]);
	// G R A D O  I I I
	Nodo* getExpresionGradoIIIPost(char expresion[]);
	float getResultadoExpresionGradoIIIPost(char expresion[]);

private:

	Nodo* inicio;
	NodoFloat* pila;
	void eliminarLista();
	NodoFloat* pushFloat(float valor, NodoFloat* pila);
	NodoFloat* popFloat(float* valor, NodoFloat* pila);
	float operacion(float operador1, float operador2, char operador);
	float resultadoExpresion;
	void setResultado(float result) { resultadoExpresion = result;}
	int determinaGrado(Nodo*);
	int contSuma, contResta,contDivision,contMult, gradoExpresion;
	bool elevado, parentesis;
};


#endif // !LISTA_H


