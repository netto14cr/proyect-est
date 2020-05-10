#include "Control.h"
#include "Modelo.h"
#include "lista.h"

Lista li;
Model m;

// Contructor de la clase control
Control::Control()
{
	//postFija = NULL;
}

// Destructor de la clase
Control::~Control()
{
}
// Metodo que control la ejecucion inicial del programa
void Control::inicioPrograma()
{
	printf("\nDigite la expresion infija: \n");
	scanf_s("%s", expresion, 49);
	//cout<<"\n"<<determinaExpresionDigitada(expresion);

	evaluaExpresionPorGrado(determinaExpresionDigitada(expresion), expresion);

}


void Control::evaluaExpresionPorGrado(int gradoExpresion, char expresion[]){
	Nodo* auxliarExpresionPost;
	switch (gradoExpresion)
	{
	case 1:
		cout << "\n CASO I \n";
		auxliarExpresionPost=m.getExpresionPostFijaGradoI(expresion,li);
		cout<<"\nEL RESULTADO ES: "<<li.recorreExpresionPost(auxliarExpresionPost);
		
		break;
	case 2:
		break;
	
	case 3:
		break;

	case 4:
		break;

	default:
		break;
	}

}


// Metodo que evalua la expresion digitada por el usuario y
// returna un numero de acuenrdo al grado de expresion
int Control::determinaExpresionDigitada(char expresion[])
{
	//std::cout << "\nHOLA ESTOY EN DETERMINA EXPRESION CONTROL:CPP\n";
	return li.clasificaGradoExpresion(expresion);
}
