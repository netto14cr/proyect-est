

#include "lista.h"
int main()
{
	Lista li;
	char expresion[50];
	Nodo* postFija=NULL;
	//int opcion;


	//printf("\nDigite la expresion postfija: \n");
	//scanf_s("%s", expresion, 49);
	////std::cin >> expresion;
	//printf("\nExpresion digitada: %s", expresion);
	//printf("\n\n");
	//printf("\nEl resultado es: %.2f", li.evaluaExpresionPostFija (expresion));
	//printf("\n\n");


	printf("\nDigite la expresion infija: \n");
	scanf_s("%s", expresion, 49);

	if (li.verificarParentesisBalanceados(expresion)) {
		postFija = li.evaluaExpresionIngresada(expresion);
		li.mostrarExpresionPostFija(postFija);
	}
	else {
		printf("\nExpresion no balanceada \n");
	}
	printf("\n\nEl resultado es: %.2f", li.evaluaExpresionPostFija(expresion));
	printf("\n\n");
	system("pause");

	


}

