#include "Control.h"
#include "Modelo.h"
#include "lista.h"
#include "Interfaz.h"

Lista li;
Model m;
Interfaz inter;

// Contructor de la clase control
Control::Control()
{
	expresion[49] = ' ';
}

// Destructor de la clase
Control::~Control()
{
	expresion[49] = ' ';
}
// Metodo que control la ejecucion inicial del programa
void Control::inicioPrograma()
{

	//inter.dibujaCalculadora();


	printf("\nDigite la expresion infija: \n");

	while (true){
		printf("\n\n--- ");
		scanf_s("%s", expresion, 49);
		evaluaExpresionPorGrado(determinaExpresionDigitada(expresion), expresion);
	}

}


void Control::evaluaExpresionPorGrado(int gradoExpresion, char expresion[]){
	Nodo* auxliarExpresionPost,* ax;
	system("cls");
	switch (gradoExpresion)
	{
	case 1:
		printf("\n %%%%%%%%%%%%%%	C A S O   G R A D O  I  %%%%%%%%%% \n");
		auxliarExpresionPost=m.getExpresionPostFijaGradoI(expresion,li);
		printf("\n\nEL RESULTADO ES: %0.2f", m.getResultadoOperacion(expresion, li));
		break;
	case 2:
		printf("\n %%%%%%%%%%%%%%	C A S O   G R A D O  II  %%%%%%%%%% \n");
		auxliarExpresionPost = m.getExpresionPostFijaGradoI(expresion, li);
		printf("\n\nEL RESULTADO ES: %0.2f",m.getResultadoOperacionII(expresion, li));
		break;
	
	case 3:
		printf("\n %%%%%%%%%%%%%%	C A S O   G R A D O  III  %%%%%%%%%% \n");
		auxliarExpresionPost=m.getExpresionPostFijaGradoIII(expresion, li);
		ax = auxliarExpresionPost;
		printf("\nEXPRESION III POST\n");
		while (ax) {
			printf(" %c", ax->simbolo);
			ax = ax->sig;
		}
		printf("\n\nEL RESULTADO ES:  %0.2f", m.getResultadoOperacionIII(expresion, li));

		break;

	case 4:
		printf("\n %%%%%%%%%%%%%%	C A S O   G R A D O  IV  %%%%%%%%%% \n");
		auxliarExpresionPost = m.getExpresionPostFijaGradoIII(expresion, li);
		ax = auxliarExpresionPost;
		printf("\nEXPRESION IV POST\n");
		while (ax) {
			printf(" %c", ax->simbolo);
			ax = ax->sig;
		}

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
