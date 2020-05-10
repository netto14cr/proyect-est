#ifndef MODEL_H
#define MODEL_H
#include "Lista.h"

class Model{


public:
	Model(){}
	virtual ~Model();
	Nodo * getExpresionPostFijaGradoI(char expresion[], Lista li);

private:


};



#endif // !MODELO_H

