#ifndef MODEL_H
#define MODEL_H
#include "Lista.h"

class Model{


public:
	Model(){}
	virtual ~Model();
	Nodo * getExpresionPostFijaGradoI(char expresion[], Lista li);
	Nodo* getExpresionPostFijaGradoIII(char expresion[], Lista li);
	float getResultadoOperacion(char expresion[], Lista lista);
	float getResultadoOperacionII(char expresion[], Lista lista);
	float getResultadoOperacionIII(char expresion[], Lista lista);

private:


};



#endif // !MODELO_H

