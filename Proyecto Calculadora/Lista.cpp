

#include "lista.h"

// Metodo que crea la lista
Lista::Lista()
{
	inicio = NULL;
}

// Destructor de lista llama al metodo que borra datos de la lista
Lista::~Lista()
{
	eliminarLista();
}
// Metodo que inserta un elemento nuevo a la pila 
Nodo* Lista::push(char simbolo, Nodo* pila)
{

	Nodo* nuevo = NULL;
	nuevo = (Nodo*)malloc(sizeof(Nodo)); // Creacion de nuevo nodo tipo struct en C
	
	// Condisional que verifica si el primer elemento existe , sino agrega el primer elemnto como inicial
	if (nuevo != NULL) {
		nuevo->simbolo = simbolo;   // Declaramos el puntero siguente nulo
		nuevo->sig = pila;     // Apuntamos el nuevo valor a la pila
		pila = nuevo;// Se pone la pila a apuntar al nuevo nodo
	}
	return pila;
}


// Metodo que inserta un elemento al final de la lista
Nodo* Lista::insertarNodoFinalLista(char simbolo, Nodo* lista)
{
	Nodo* nuevo=NULL; // Nodo nuevo con los valores a agregar
	Nodo* auxNodo = NULL; // Nodo de copia para reccorer la lista del inicial al final

	nuevo = (Nodo*)malloc(sizeof(Nodo)); // Creacion de nuevo nodo tipo struct en C

	// Condisional que verifica si el primer elemento existe , sino agrega el primer elemnto como inicial
	if (nuevo != NULL) {
		nuevo->simbolo = simbolo;   // Declaramos el puntero siguente nulo
		nuevo->sig = NULL;     // Apuntamos el nodo siguiente a NULL

		// Verificamos si la lista es vacia y agregamos el nodo nuevo
		if (lista == NULL)
			lista = nuevo;
		// Falso si la lista ya tiene elementos entonces recorreremos la lista
		// para agregar el nuevo elemento
		else {

			// Guardamos el respaldo de la lista en un nodo auxiliar para no perder 
			// o modificar los de la lista original
			auxNodo = lista;

			// Recorremos el contenido del nodo auxiliar hasta llegar al final 
			while (auxNodo->sig != NULL)
				auxNodo = auxNodo->sig;
			// Con esto al llegar al final de la lista nos aseguramos que el proximo elemento 
			// que necesitamos insertar ira al final de la lista.
			auxNodo->sig = nuevo;
		}

	}
	return lista;
}


// Metodo que saca elementos de la pila
Nodo* Lista::pop(char* valor, Nodo* pila)
{
	Nodo* auxNodo = NULL;
	char auxCaracter;
	// Verificamos si la pila esta vacio o no tiene valores 
	if (pila == NULL) {
		printf("Pila es vacia!");
	}
	// Falso si si la pila tiene valores  
	else{
		// Aux nodo guardara la copia de la pila
		auxNodo = pila;
		// Se le asigna el valor que esta en el nodo auxiliar
		auxCaracter = auxNodo->simbolo;
		// ponemos a la pila a apuntar al nodo siguiente del auxiliar
		pila = auxNodo->sig;

		*valor = auxCaracter;

		free(auxNodo);


	}


}

// Metodo para mostrar los elementos de la lista 
void Lista::mostrarExpresionPostFija(Nodo* lista)
{
	Nodo* auxNodo=NULL;
	// Se le pasa la informacion de la lista al nodo auxliar
	auxNodo = lista;
	// Se recorre el nodo auxiliar hasa que sea difente de null
	while (auxNodo!=NULL) {
		// Se muestra el contenido de los caracteres del nodo auxilir
		printf("%c ", auxNodo->simbolo);
		// se mueve la informacion avanzando al nodo siguiente recoriendo este
		auxNodo = auxNodo->sig;
	}
}


// Funcion que verifica si existen la misma cantidad de parentesis de apertura como 
// de cierre y devuvle true de ser cierto o false de no cumplirse.
bool Lista::verificarParentesisBalanceados(char expresion[])
{
	Nodo* auxNodo = NULL;
	int longitudExpresion,i;
	char valorDato;

	auxNodo=(Nodo*)malloc(sizeof(Nodo)); // Creamos y definimos el nuevo nodo auxiliar
	// obtenemos el tamaño de la expresion pasada
	longitudExpresion = strlen(expresion);

	for (i = 0; i < longitudExpresion; i++) {
		// Verificamos si el caracter es igual a un parentesis de apertura
		if (expresion[i] == '(')
			// Gaurdamos el valor en el nodo auxiliar
			auxNodo = push(expresion[i], auxNodo);
		// Verificamos si el caracter es igual a un parentesis de cerrar
		if (expresion[i] == ')')
			// Eliminamos el valor que habiamos ingresado
			auxNodo = pop(&valorDato, auxNodo);
	}

	// Verificamos el resultado de la pila si se encuntra vacia es que los 
	// parentessi encontrados en la expresion eran correctos y la expresion
	// estaba balanceada correctamente, se retorna respuesta verdadera
	if (auxNodo == NULL)
		return true;

	// Si pila auxiliar no es vacia se retrona false
	return false;
}


// Funcion que verifica si el caracter sea un operador (+ , -, *, ^) 
// y devuelve true de ser correcto o false de no serlo.
bool Lista::verificaElementoOperador(char simbolo)
{
	// Se verifica si el simbolo pasado es un operador y se devuelve un respuesta verdadera
	switch (simbolo)
	{
	case '-': return true; break;
	case '+': return true; break;
	case '/': return true; break;
	case '*': return true; break;
	case '^': return true; break;
	// Se lo contrario la respuesta sera falsa
	default: return false; break;
	}
}

// Metodo que retorna la prioridad de un elemento seleccionado
// este clasifica la importancia en una escala de operandos
int Lista::obtenerPrioridadElementos(char simbolo)
{
	// Segun clasificacion para evaluar una expresion infija
	// matematicamente segun la importancia a resolver en operaciones

	// verifica si es unoperador de suma o resta (mas o menos)
	if (simbolo == '+' || simbolo == '-')
		return 1;
	// Falso si es multiplicacion o division
	else if (simbolo == '*' || simbolo == '/')
		return 2;
	// Falso si es un exponente
	else if (simbolo == '^')
		return 3;
	// Falso si el simbolo es un parentesis de apertura
	else if (simbolo == '(')
		return 0;

}


// Metodo que se encarga de evaluar la expresion ingresada por el usuario
Nodo* Lista::evaluaExpresionIngresada(char expresion[])
{
	Nodo* auxNodo = NULL;
	Nodo* expresionPostFija = NULL;
	char valorDato;
	int i, longitudExpresion;
	// Creamos y definimos el nuevo nodo auxiliar
	auxNodo = (Nodo*)malloc(sizeof(Nodo)); 
	// Creamos y definimos el nuevo nodo de expresion postFija
	expresionPostFija = (Nodo*)malloc(sizeof(Nodo)); 

	// Recorremos en un ciclo for el tamaño de la expresion para 
	// evaluar los valores que esta contiene
	for (i = 0; i < longitudExpresion; i++) {
		// Verificamos el caracter en la epxresion segun el codigo de la tabla ASCII

		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if (expresion[i] >= 48 && expresion[i] <= 57) {
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
		}
		// Falso verificamos si el caracter es una letra
		// Falso Si el caracter es una letra en mayuscula
		else if (expresion[i] >= 65 && expresion[i] <= 90)
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
		// Falso Si el caracter es una letra en minuscula
		else if (expresion[i] >= 97 && expresion[i] <= 122)
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
		else if (expresion[i] == '(')
			auxNodo = push(expresion[i], auxNodo);
		else {
			// Verificamos que el elemento de la expresion sea un operador
			if (verificaElementoOperador(expresion[i])) {
				// Verificamos que la lista auxiliar este vacia
				if (auxNodo == NULL)
					auxNodo = push(expresion[i], auxNodo);
				// Falso si el nodo auxiliar contiene un elemento
				else {
					// Se recorre el nodo auxiliar para verificar que los elementos sean menores
					// en prioridad
					while (auxNodo != NULL) {
						if ()
					}
				}
			}
		}
	}
	

}



// Metodo que se encarga de insertar valores a la lista
int Lista::insertarValor(int valorAgregar)
{
	Nodo* nuevo;

	// Excepcion por no poder crear el nodo
	try
	{
		nuevo = (Nodo*)malloc(sizeof(Nodo));
	}
	catch (std::bad_alloc exception)
	{
		return -1;
	}
	nuevo->sig = NULL;   // Declaramos el puntero siguente nulo
	nuevo->ant = NULL;// Declaramos el puntero anterior  nulo
	nuevo->valor = valorAgregar;     // Guardamos el valor en el nodo
	



	// Condisional que verifica si el primer elemento existe , sino agrega el primer elemnto como inicial
	if (inicio == NULL)
		inicio = nuevo;



	else {     // Condisional falso si existe un elemento en la lista


		// Mediante una variable aux se recorre la lista y agregamos el elemento al final
		Nodo* aux = inicio;
		while (aux->sig != nullptr)
			aux = aux->sig;
		aux->sig = nuevo;   // El último nodo lo ponermos a apuntar al nuevo nodo.
		nuevo->ant = aux;
	}

}


// Metodo que retorna un nodo evaluando una expresion pasada
float Lista::evaluaExpresionPostFija(char expresion[])
{
	NodoFloat* pila = NULL;
	int tamExpresion, i;
	char valorAux;
	float operando1, operando2, resultado;

	// convierte el valor de la expresion pasada
	tamExpresion = strlen(expresion);
	
	for (i = 0; i < tamExpresion; i++) {
		
		if ((expresion[i] >= 48) && (expresion[i] <= 57)) {
			valorAux = expresion[i];
			//converite el valor y lo pasa tipo numerico flotante
			pila = pushFloat(atof(&valorAux), pila);
		}
		else {
			pila = popFloat(&operando2, pila);
			pila = popFloat(&operando1, pila);

			resultado = operacion(operando1, operando2, expresion[i]);

			pila = pushFloat(resultado, pila);
		}
	}
	return pila->valorF;
}





// Metodo que recorre los valores de la lista y los elimina
void Lista::eliminarLista()
{
	Nodo* aux;
	while (inicio != nullptr) {
		aux = inicio;
		inicio = inicio->sig;
		delete aux;
	}
}



// Funcion para insertar en la pila
NodoFloat* Lista::pushFloat(float valor, NodoFloat* pila)
{
	NodoFloat* nodoNuevo;

	nodoNuevo = (NodoFloat*)malloc(sizeof(NodoFloat));

	if (nodoNuevo != NULL) {
		nodoNuevo->valorF = valor;
		nodoNuevo->sig = pila;

		pila = nodoNuevo;
	}

	return pila;
}


// Funcion para sacar elementos de la pila
NodoFloat* Lista::popFloat(float* valor, NodoFloat* pila)
{

	NodoFloat* auxNodo;
	float datoAux;

	// Se verifica que la pila no cuente con valores
	if (pila == NULL) {
		printf("Pila es vacia!");
	}
	else {
		auxNodo = pila;
		datoAux = auxNodo->valorF;
		pila = auxNodo->sig;
		*valor = datoAux;
		free(auxNodo);
	}
	return pila;

}


// Realiza la operacion con los dos datos tipo flotantes y el operador de la operacion a realizar
float Lista::operacion(float operando1, float operando2, char operador)
{

	switch (operador)
	{
	case '-':
		return operando1 - operando2;
		break;

	case '+':
		return operando1 + operando2;
		break;

	case '/':
		return operando1 / operando2;
		break;

	case '*':
		return operando1 * operando2;
		break;

	case '^':
		return pow(operando1, operando2);
		break;
	}
}
