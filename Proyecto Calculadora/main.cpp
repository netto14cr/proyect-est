

#include "lista.h"
int main()
{
	Lista li;
	char expresion[50];
	printf("\nDigite la expresion postfija: \n");
	scanf_s("%s", expresion, 49);
	//std::cin >> expresion;

	printf("\nExpresion digitada: %s", expresion);
	printf("\n\n");
	printf("\nEl resultado es: %.2f", li.evaluaExpresionPostFija (expresion));
	printf("\n\n");
	system("pause");

	Lista li;
	li.push();


}

