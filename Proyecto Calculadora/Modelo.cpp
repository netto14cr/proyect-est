#include "Modelo.h"



Model::~Model()
{
}

Nodo* Model::getExpresionPostFijaGradoI(char expresion[], Lista lista)
{
	return lista.getExpresionGradoIPost(expresion);
}

Nodo* Model::getExpresionPostFijaGradoIII(char expresion[], Lista lista)
{
	return lista.getExpresionGradoIIIPost(expresion);
}



float Model::getResultadoOperacion(char expresion[], Lista lista)
{
	return  lista.getResultadoExpresionGradoIPost(expresion);
}



float Model::getResultadoOperacionII(char expresion[], Lista lista)
{
	return  lista.getResultadoExpresionGradoIIPost(expresion);
}


float Model::getResultadoOperacionIII(char expresion[], Lista lista)
{
	return  lista.getResultadoExpresionGradoIIIPost(expresion);
}