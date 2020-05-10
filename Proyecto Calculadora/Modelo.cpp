#include "Modelo.h"



Model::~Model()
{
}

Nodo* Model::getExpresionPostFijaGradoI(char expresion[], Lista lista)
{
	return lista.getExpresionGradoIPost(expresion);
}
