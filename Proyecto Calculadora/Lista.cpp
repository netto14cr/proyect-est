

#include "lista.h"

// Metodo que crea la lista
Lista::Lista()
{
	inicio = NULL;
	contSuma=0,contResta=0,contDivision=0,
	contMult=0,gradoExpresion = 0;
	parentesis = false, elevado = false;
}

// Destructor de lista llama al metodo que borra datos de la lista
Lista::~Lista()
{
	eliminarLista();
}



// Metodo que clasifica el grado de expresion digitada por el usuario
int Lista::clasificaGradoExpresion(char expresion[])
{
	//std::cout << "\nHOLA ESTOY EN LISTA:CPP\n";
	Nodo* auxNodo;
	char valorDato = ' ';
	int i, longitudExpresion;
	// Creamos y definimos el nuevo nodo auxiliar
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL;
	longitudExpresion = strlen(expresion);
	


	for ( i = 0; i < longitudExpresion; i++) {

		// Verifica si la epxresion en el caracter recorrido 
		// es un numero
		if ((expresion[i] >= 48 && expresion[i] <= 57)) {}
		//Falso si no es un numero

		// Falso no es un numero entonces se procede a clasificar su tipo
		else {
			// Si la expresion es un parentesis entonces el grado se clasifica en 3 o 4
			if ((expresion[i] == '(')) {
				parentesis = true;
			}
			// Falso si no es un operando o un parentesis de apertura
			else {
				// Verificamos que el elemento de la expresion sea un operador
				if (verificaElementoOperador(expresion[i])) {
					auxNodo = push(expresion[i], auxNodo);
					if (expresion[i] == '^')
						elevado=true;
					
				}
			}
		}
	}
	
	return determinaGrado(auxNodo);
}


int Lista::determinaGrado(Nodo* pilaOperandos) {
	int grado; grado = 0;
	Nodo* auxNodo = NULL;
	auxNodo = pilaOperandos;
	int cont = 0;
	//cout << "\n MOSTRANDO LA PILA GUARDADA\n";
	while (auxNodo != NULL) {
		//cout << " " << auxNodo->simbolo;
		auxNodo = auxNodo->sig;
		cont++;
	}
	if (elevado)
		 grado = 4;
	else if (parentesis)
		 grado = 3;
	else if (cont >= 2)
		 grado = 2;
	else if (cont == 1)
	 	 grado = 1;
	
	eliminarLista();
	return grado;
}




// Metodo que inserta un elemento nuevo a la pila 
Nodo* Lista::push(char simb, Nodo* pila)
{
	Nodo* nuevo; 
	nuevo = (Nodo*)malloc(sizeof(Nodo)); // Creacion de nuevo nodo tipo struct en C
	
	
	// Condisional que verifica si el primer elemento existe , sino agrega el primer elemnto como inicial
	if (nuevo != NULL) {
		nuevo->simbolo = simb;   // Declaramos el puntero siguente nulo
		nuevo->sig = pila;     // Apuntamos el nuevo valor a la pila

		pila = nuevo;// Se pone la pila a apuntar al nuevo nodo
	}
	//std::cout << "---ENTRA PARENTESIS ---- " << pila->simbolo << "\n";
	return pila;
}


// Metodo que inserta un elemento al final de la lista
Nodo* Lista::insertarNodoFinalLista(char simb, Nodo* lista)
{

	//cout << "\nPIDO ::::::::::::: " << simb;
	Nodo* nuevo; // Nodo nuevo con los valores a agregar
	Nodo* auxNodo= NULL; // Nodo de copia para reccorer la lista del inicial al final

	nuevo = (Nodo*)malloc(sizeof(Nodo)); // Creacion de nuevo nodo tipo struct en C
	//auxNodo = (Nodo*)malloc(sizeof(Nodo));


	// Condisional que verifica si el primer elemento existe , sino agrega el primer elemnto como inicial
	if (nuevo != NULL) {
		nuevo->simbolo=simb;   // Declaramos el puntero siguente nulo
		nuevo->sig = NULL;     // Apuntamos el nodo siguiente a NULL
		//cout << "  = AGREGA\n";

		

		// Verificamos si la lista es vacia y agregamos el nodo nuevo
		if (lista == NULL) {
			lista = nuevo;
		}
		// Falso si la lista ya tiene elementos entonces recorreremos la lista
		// para agregar el nuevo elemento
		else {

			// Guardamos el respaldo de la lista en un nodo auxiliar para no perder 
			// o modificar los de la lista original
			auxNodo = lista;


			// Recorremos el contenido del nodo auxiliar hasta llegar al final 
			while (auxNodo->sig!= NULL) {
				//cout << " < " << auxNodo->simbolo << " >\n";
				auxNodo = auxNodo->sig;
			}
			// Con esto al llegar al final de la lista nos aseguramos que el proximo elemento 
			// que necesitamos insertar ira al final de la lista.
			auxNodo->sig = nuevo;
		}

	}
	return lista;
}





// Metodo que saca elementos de la pila
Nodo* Lista::pop(char *valor, Nodo* pila)
{
	Nodo* auxNodo=NULL;
	char auxCaracter=' ';

	
	
	// Verificamos si la pila esta vacio o no tiene valores 
	if (pila == NULL) {
		printf("Pila es vacia xdxd!");
	}
	// Falso si si la pila tiene valores  
	else{
		// Aux nodo guardara la copia de la pila
		auxNodo = pila;
		// Se le asigna el valor que esta en el nodo auxiliar
		auxCaracter = auxNodo->simbolo;
		// ponemos a la pila a apuntar al nodo siguiente del auxiliar
		pila = auxNodo->sig;
		// Se pasa el valor que estamos liberando de la pila
		*valor = auxCaracter;
		// Libera los valores del nodo auxiliar
		
		free(auxNodo);
	}
	return pila;
}
// Metodo que pertite crear una lista
Nodo* Lista::craerLista(Nodo * nodoNuevo)
{
	return nodoNuevo=NULL;
}

// Metodo para mostrar los elementos de la lista 
void Lista::mostrarExpresionPostFija(Nodo* lista)
{
	Nodo* auxNodo=NULL;
	// Se le pasa la informacion de la lista al nodo auxliar
	auxNodo = lista;
	//printf("\n%%%%%%%	POSTFIJA	%%%%%%%\n");

	// Se recorre el nodo auxiliar hasa que sea difente de null
	while (auxNodo!=NULL) {
		// Se muestra el contenido de los caracteres del nodo auxilir
		printf("%c ", auxNodo->simbolo);
		printf("| ");
		//std::cout << "%%%%%% " << auxNodo->simbolo << "\n";
		// se mueve la informacion avanzando al nodo siguiente recoriendo este
		auxNodo = auxNodo->sig;
	}
}


// Funcion que verifica si existen la misma cantidad de parentesis de apertura como 
// de cierre y devuvle true de ser cierto o false de no cumplirse.
bool Lista::verificarParentesisBalanceados(char expresion[])
{
	Nodo* auxNodo;
	int longitudExpresion,i=0;
	char valorDato;
	valorDato = ' ';
	auxNodo = NULL; // Creamos y definimos el nuevo nodo auxiliar
	// obtenemos el tamaño de la expresion pasada
	longitudExpresion = strlen(expresion);

	for (i = 0; i <longitudExpresion; i++) {
		// Verificamos si el caracter es igual a un parentesis de apertura
		if (expresion[i] =='(') {
			auxNodo = push(expresion[i], auxNodo);// Guardamos el valor en el nodo auxiliar
			
		}
		// Verificamos si el caracter es igual a un parentesis de cerrar
		 if (expresion[i]==')') {
			auxNodo = pop(&valorDato, auxNodo);// Eliminamos el valor que habiamos ingresado
			
		}
	}

	// Verificamos el resultado de la pila si se encuntra vacia es que los 
	// parentessi encontrados en la expresion eran correctos y la expresion
	// estaba balanceada correctamente, se retorna respuesta verdadera
	if (auxNodo == NULL) {
		return true;
	}
	
	// Si pila auxiliar no es vacia se retrona false
	return false;
}

// (6+4)*2/8^(7-4)


// Funcion que verifica si el caracter sea un operador (+ , -, *, ^) 
// y devuelve true de ser correcto o false de no serlo.
int Lista::verificaElementoOperador(char simbolo)
{
	// Se verifica si el simbolo pasado es un operador y se devuelve un respuesta verdadera
	switch (simbolo)
	{
	case '-': return 1; break;
	case '+': return 1; break;
	case '/': return 1; break;
	case '*': return 1; break;
	case '^': return 1; break;
	// Se lo contrario la respuesta sera falsa
	default: return 0; break;
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
	if (simbolo == '*' || simbolo == '/')
		return 2;
	// Falso si es un exponente
	if (simbolo == '^')
		return 3;
	// Falso si el simbolo es un parentesis de apertura
	 if (simbolo == '(')
		return 0;

return 0;
}

// ------------------------------------ G R A D O   I Y II  ----------------------------------------------------------

Nodo* Lista::getExpresionGradoIPost(char expresion[]) {
	Nodo* auxNodo, *expresionPostFija;
	char valorDato = ' ';
	int i=0, longitudExpresion=0;
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL, expresionPostFija = NULL;
	longitudExpresion = strlen(expresion);
	float resultado = 0;
	char exp1[50]=" ", exp2[50]= " ", operando=' ';
	bool ex1=false, ex2=false;
	int cont=0;
	
	// Mediante un ciclo for se recorre todos los valores contenidos en la expresion
	for (i = 0; i < longitudExpresion; i++) {
		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if ((expresion[i] >= 48 && expresion[i] <= 57)) 
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);

		// Falso si no es un numero entonces es un operador
		else {

			if (auxNodo == NULL) {
				auxNodo = push(expresion[i], auxNodo);
			}
			// Falso si el nodo auxiliar contiene un elemento
			else {
				Nodo* recooreAuxiliar=NULL;
				recooreAuxiliar = auxNodo;
				while (recooreAuxiliar->sig!= NULL) {
					recooreAuxiliar = recooreAuxiliar->sig;}
				recooreAuxiliar = push(expresion[i], auxNodo);
				auxNodo = recooreAuxiliar;
			}
		}

	}

	// Verificamos que no haya quedado un valor en nodo auxiliar y de ser asi 
	// es sacado del nodo axuliar y agregado a la expresion postfija
	while (auxNodo != NULL) {
		auxNodo = pop(&valorDato, auxNodo);
		//cout << "\n QUEDO: " << valorDato;
		expresionPostFija = insertarNodoFinalLista(valorDato, expresionPostFija);
	}

	return expresionPostFija;
}



float Lista::getResultadoExpresionGradoIPost(char expresion[]) {
	Nodo* auxNodo;
	char valorDato = ' ';
	int i = 0, longitudExpresion = 0;
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL;
	longitudExpresion = strlen(expresion);
	float resultado = 0;
	char exp1[50] = " ", exp2[50] = " ", operando = ' ';
	bool ex1 = false, ex2 = false;
	int cont = 0;

	// Mediante un ciclo for se recorre todos los valores contenidos en la expresion
	for (i = 0; i < longitudExpresion; i++) {
		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if ((expresion[i] >= 48 && expresion[i] <= 57)) {
			if (!ex1) {	exp1[cont] = expresion[i]; cont++; }
			else if (!ex2) { exp2[cont] = expresion[i]; cont++; }
		}

		// Falso si no es un numero entonces es un operador
		else {
			if (auxNodo == NULL) {
				auxNodo = push(expresion[i], auxNodo);
				ex1 = true; cont = 0; operando = expresion[i];
			}
		}

		
	}

	// Verificamos que no haya quedado un valor en nodo auxiliar y de ser asi 
	// es sacado del nodo axuliar y agregado para realizar el calculo del resultado
	while (auxNodo != NULL) {
		auxNodo = pop(&valorDato, auxNodo);
		resultado = operacion(atoi(exp1), atoi(exp2), valorDato);
	}

	return resultado;
}
// -------------------------------  F I N   G R A D O   I  ------------------------------


// -------------------------------	 G R A D O   I I		------------------------------
float Lista::getResultadoExpresionGradoIIPost(char expresion[]) {
	Nodo* auxNodo, * expresionPostFija;
	char valorDato = ' ';
	int i = 0, longitudExpresion = 0;
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL, expresionPostFija=NULL;
	longitudExpresion = strlen(expresion);
	float resultado = 0;
	char exp1[50] = " ", exp2[50] = " ", operando = ' ';
	bool ex1 = false, ex2 = false;
	int cont = 0;
	bool negativa; negativa = false;

	// Mediante un ciclo for se recorre todos los valores contenidos en la expresion
	for (i = 0; i < longitudExpresion; i++) {
		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if ((expresion[i] >= 48 && expresion[i] <= 57)) {
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
			if (!ex1) { exp1[cont] = expresion[i]; cont++; }
			else if (!ex2) { exp2[cont] = expresion[i]; cont++; }
		}

		// Falso si no es un numero entonces es un operador
		else {
			if (expresionPostFija == NULL) {
				negativa = true;
				exp1[cont] = expresion[i]; cont++;
			}
			else if (auxNodo == NULL) {
				auxNodo = push(expresion[i], auxNodo);
				ex1 = true; cont = 0; operando = expresion[i];
			}
			else if (auxNodo != NULL) {
				exp2[cont] = expresion[i]; cont++;
			}
		}

	}

	// Verificamos que no haya quedado un valor en nodo auxiliar y de ser asi 
	// es sacado del nodo axuliar y agregado para realizar el calculo del resultado
	while (auxNodo != NULL) {
		auxNodo = pop(&valorDato, auxNodo);
		resultado = operacion(atoi(exp1), atoi(exp2), valorDato);
	}

	return resultado;
}
// ------------------------------   F I N  G R A D O   I I		------------------------------






// -------------------------------	 G R A D O   I I I		------------------------------
// Metodo que se encarga de evaluar la expresion ingresada por el usuario
Nodo* Lista::getExpresionGradoIIIPost(char expresion[])
{

	Nodo* auxNodo;
	Nodo* expresionPostFija;
	char valorDato = ' ';
	int i, longitudExpresion;
	// Creamos y definimos el nuevo nodo auxiliar
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	// Creamos y definimos el nuevo nodo de expresion postFija
	expresionPostFija = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL;
	expresionPostFija = NULL;

	longitudExpresion = strlen(expresion);
	// Recorremos en un ciclo for el tamaño de la expresion para 
	// evaluar los valores que esta contiene

	//std::cout << "\n-----RECORRE FOR CICLO------\n\n";
	for (i = 0; i < longitudExpresion; i++) {

		//std::cout <<" [ "<<expresion[i]<<" ]";
		// Verificamos el caracter en la epxresion segun el codigo de la tabla ASCII

		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if ((expresion[i] >= 48 && expresion[i] <= 57))
		{
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
		}
		else {
			// Verificamos que el elemento de la expresion sea un operador
			if (verificaElementoOperador(expresion[i])) {
				// Verificamos que la lista auxiliar este vacia
				if (auxNodo == NULL) {
					std::cout << " ? " << expresion[i];
					auxNodo = push(expresion[i], auxNodo);
				}
				// Falso si el nodo auxiliar contiene un elemento
				else {
					// Se recorre el nodo auxiliar para verificar que los elementos sean menores
					// en prioridad
					Nodo* auxliarRecorre = NULL;
					auxliarRecorre = auxNodo;
					while (auxliarRecorre->sig != NULL) {
						std::cout << " > " << auxliarRecorre->simbolo;
						auxliarRecorre = auxliarRecorre->sig;
					}
					// Se le pasa el valor que se evaluando al nodo auxliar
					auxliarRecorre = push(expresion[i], auxNodo);
					auxNodo = auxliarRecorre;
				}
			}
		}

	}

	Nodo* auxOperadores = NULL;
	// Verificamos que no haya quedado un valor en nodo auxiliar y de ser asi 
	// es sacado del nodo axuliar y agregado a la expresion postfija
	while (auxNodo != NULL) {
		auxNodo = pop(&valorDato, auxNodo);
		auxOperadores = push(valorDato, auxOperadores);
	}

	// Todos los datos de la pila de operadores los saca e invierte el orden
	while (auxOperadores != NULL) {
		auxOperadores = pop(&valorDato, auxOperadores);
		expresionPostFija = insertarNodoFinalLista(valorDato, expresionPostFija);
	}

	return expresionPostFija;
}


// Metodo que recorre y evalua la expresion de grado III
float Lista::getResultadoExpresionGradoIIIPost(char expresion[]) {
	Nodo* auxNodo, * expresionPostFija;
	NodoFloat *resultadoPila;
	char valorDato = ' ';
	int i = 0, longitudExpresion = 0;
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = NULL, expresionPostFija = NULL, resultadoPila=NULL;
	longitudExpresion = strlen(expresion);
	float resultado = 0.0, valorSacado=0.0;
	char exp1[50] = " ", exp2[50] = " ", operando = ' ';
	bool ex1 = false, ex2 = false;
	int cont1= 0, cont2=0;
	bool negativa; negativa = false;

	// Mediante un ciclo for se recorre todos los valores contenidos en la expresion
	for (i = 0; i < longitudExpresion; i++) {
		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
		if ((expresion[i] >= 48 && expresion[i] <= 57)) {
			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);

			
			if (!ex1) { 
				exp1[cont1] = expresion[i]; 
				cont1++; 
			}
			else if (!ex2) {
				exp2[cont2] = expresion[i]; 
				cont2++; 
			}
		}

		// Falso si no es un numero entonces es un operador
		else {
			if ((expresion[i]=='(')) {
				auxNodo = push(expresion[i], auxNodo);
			}
			else {
				// Verifica que el caracter de la expresion[i] sea un operador (+,*,-,/)
				if (verificaElementoOperador(expresion[i])) {
					if (auxNodo == NULL) {
						if (expresion[i]=='-') negativa = true;
						
						auxNodo = push(expresion[i], auxNodo);
						exp1[cont1] = expresion[i]; cont1++;
					}

					else {

						//std::cout << "\n---------------- "<<cont1<<"\n";
						auxNodo = push(expresion[i], auxNodo);
						if (cont1 >= 1 && !ex1) {
							//std::cout << "##\n";
							operando = expresion[i];
							ex1 = true;
						}
						else if (ex1) {
							exp2[cont2] = expresion[i]; cont2++;
						}
					}

				}
			}

		}

		// Cuando encuentra un parentesis de cerrar saca los elementos realiza su operacion
		/// y los vuelve a guardar en la pila
		if (expresion[i] == ')') {
			std::cout << "\n DATO 1 ::: " << atoi(exp1) << " <>  DATO 2  ::: " << atoi(exp2)<<" <> "<<operando;

			resultado = operacion(atoi(exp1), atoi(exp2), operando);
			resultadoPila=pushFloat(resultado, resultadoPila);
			ex1 = false, ex2 = false;
			cont1 = 0, cont2 = 0;
			std::cout << "\n############################################\n";
			std::cout << resultado;
		}

	}
	resultado = 0;
	while (resultadoPila!=NULL)
	{
		resultadoPila = popFloat(&valorSacado, resultadoPila);
		resultado += valorSacado;
	}

	return resultado;
}




// ------------------------------   F I N  G R A D O   I I I		------------------------------





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
	return 0;
}


float Lista::recorreExpresionPost(Nodo* expresionPost) {
	Nodo* auxNodo = NULL;
	char expresion[50]=" ";
	int i = 0;
	auxNodo = (Nodo*)malloc(sizeof(Nodo));
	auxNodo = expresionPost;

	//cout << "\n-------------------------------------------------\n";
	while (auxNodo!= NULL) {
		//cout<<" "<<auxNodo->simbolo;
		expresion[i]=auxNodo->simbolo;
		auxNodo = auxNodo->sig;
		i++;
	}
	return evaluaExpresionPostFija(expresion);
}


// Metodo que retorna un nodo evaluando una expresion pasada
float Lista::evaluaExpresionPostFija(char expresion[])
{
	NodoFloat* pila = NULL;
	int tamExpresion=0, i=0;
	char valorAux=' ';
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
	elevado = false;
	parentesis = false;
	contMult = 0;
	contResta = 0;
	contSuma = 0;
	contDivision = 0;
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
		printf("\nPila es vacia!\n");
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
	default:
		return 0;
		break;

	}
}














//~~~~~~~~~~~~~~~~~~~~~~~~		C O P I A   D E   S E G U R I D A D		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//// Metodo que se encarga de evaluar la expresion ingresada por el usuario
//Nodo* Lista::evaluaExpresionIngresada(char expresion[])
//{
//
//	std::cout << "\nEXPRESION	%%%%%%%%%%%%%%%%%%%%%%%	" << expresion << "\n";
//	Nodo* auxNodo;
//	Nodo* expresionPostFija;
//	char valorDato = ' ';
//	int i, longitudExpresion;
//	// Creamos y definimos el nuevo nodo auxiliar
//	auxNodo = (Nodo*)malloc(sizeof(Nodo));
//	// Creamos y definimos el nuevo nodo de expresion postFija
//	expresionPostFija = (Nodo*)malloc(sizeof(Nodo));
//	auxNodo = NULL;
//	expresionPostFija = NULL;
//
//	longitudExpresion = strlen(expresion);
//	// Recorremos en un ciclo for el tamaño de la expresion para 
//	// evaluar los valores que esta contiene
//
//	//std::cout << "\n-----RECORRE FOR CICLO------\n\n";
//	for (i = 0; i < longitudExpresion; i++) {
//
//		//std::cout <<" [ "<<expresion[i]<<" ]";
//		// Verificamos el caracter en la epxresion segun el codigo de la tabla ASCII
//
//		// Si valor en la tabla es del 48 al 57 - Es un numero del 0 al 9
//		if ((expresion[i] >= 48 && expresion[i] <= 57))
//		{
//			expresionPostFija = insertarNodoFinalLista(expresion[i], expresionPostFija);
//		}
//		else {
//			//cout << " ELSE NO OPERADOR\n";
//			if ((expresion[i] == '(')) {
//				//cout << " ========= " << expresion[i]<<"\n";
//				auxNodo = push(expresion[i], auxNodo);
//			}
//			// Falso si no es un operando o un parentesis de apertura
//			else {
//
//				// Verificamos que el elemento de la expresion sea un operador
//				if (verificaElementoOperador(expresion[i])) {
//					// Verificamos que la lista auxiliar este vacia
//					if (auxNodo == NULL)
//						auxNodo = push(expresion[i], auxNodo);
//					// Falso si el nodo auxiliar contiene un elemento
//					else {
//						// Se recorre el nodo auxiliar para verificar que los elementos sean menores
//						// en prioridad
//						while (auxNodo != NULL) {
//
//							//cout<<"\n@- "<<auxNodo->simbolo<<" VALUE: "<<obtenerPrioridadElementos(auxNodo->simbolo)<<"\n";
//							// Veirficamos que la prioridad de elementos guardados en el nodo auxiliar
//							// sea mayor que la expresion del dato evaluado
//							if ((obtenerPrioridadElementos(auxNodo->simbolo) >=
//								obtenerPrioridadElementos(expresion[i]))) {
//								// Si es asi entonces se saca le valor que este en el tope
//								// del nodo auxiliar y lo insertamos en la expresion post fija
//								auxNodo = pop(&valorDato, auxNodo);
//								expresionPostFija = insertarNodoFinalLista(valorDato, expresionPostFija);
//
//							}
//							// Falso sale del ciclo
//							else break;
//						}
//						// Se le pasa el valor que se evaluando al nodo auxliar
//						auxNodo = push(expresion[i], auxNodo);
//					}
//				}
//			}
//		}
//
//		// Verificamos que si caracter a evaluar es un parentesis de cerrar expresion
//		// entonces debemos verificar acomodar y sacar todos los elementos del nodo auxliar
//		// y agregarlos a la lista del nodo de la expresion post fija
//		if (expresion[i] == ')') {
//			// Se recorre y se retira los operadores de  nodo auxliar minetras esta sean
//			// difentes al parentesis de apertura o esta no sea vacia - nula
//			while ((auxNodo != NULL) && (auxNodo->simbolo != '(') && (auxNodo->sig != NULL)) {
//				// se retira el valor del nodo auxiliar 
//				auxNodo = pop(&valorDato, auxNodo);
//				// Se agrega el valor y se inserta al final del la expresion postfija
//				expresionPostFija = insertarNodoFinalLista(valorDato, expresionPostFija);
//			}
//			// Sacamos el caracter de parentesis de apertura
//
//			auxNodo = pop(&valorDato, auxNodo);
//		}
//	}
//
//
//	// Verificamos que no haya quedado un valor en nodo auxiliar y de ser asi 
//	// es sacado del nodo axuliar y agregado a la expresion postfija
//	while (auxNodo != NULL) {
//		auxNodo = pop(&valorDato, auxNodo);
//		expresionPostFija = insertarNodoFinalLista(valorDato, expresionPostFija);
//	}
//
//	return expresionPostFija;
//}














