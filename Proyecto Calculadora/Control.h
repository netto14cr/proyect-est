#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <math.h>
#include <stdlib.h>



class Control{

public:

	Control();
	virtual ~Control();
	void inicioPrograma();

private:
	char expresion[50];
	int determinaExpresionDigitada(char expresion[]);
	void evaluaExpresionPorGrado(int gradoExpresion, char expresion[]);
};





#endif // !CONTROL_H

