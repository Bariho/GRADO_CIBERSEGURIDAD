#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void menu_principal();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();

void ejercicio1() {

    char cadena[51];
    int longitud, contador_palabras = 0, contador_numero = 0;

    getchar(); 

    printf("Introduce una frase: ");
    fgets(cadena, sizeof(cadena), stdin);
    printf("Test");
    
    cadena[strcspn(cadena, "\n")] = '\0';
    longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++) {
        if (isdigit(cadena[i])) { // isdigit verifica si es un numero o no.
            contador_numero = 1;
        }
        if (cadena[i] == ' ' || cadena[i + 1] == '\0') {
            contador_palabras++;
        }
    }

    printf("La frase tiene %d caracteres, %d palabras y %s caracteres numericos.\n",longitud, contador_palabras, contador_numero ? "contiene" : "no contiene");

}

void ejercicio2() {

    int num1, num2, suma = 0;
    printf("Introduce el primer numero entero: ");
    scanf("%d", &num1);
    printf("Introduce el segundo numero entero: ");
    scanf("%d", &num2);

    printf("Los cuadrados perfectos comprendidos entre %d y %d son: ", num1, num2);

    
    int inicio = (int)ceil(sqrt(num1)); // Redondea la raíz hacia arriba
    int fin = (int)floor(sqrt(num2)); // Redondea la raíz hacia abajo

    for (int i = inicio; i <= fin; i++) {
        int cuadrado = i * i;

        if (cuadrado > 1) {
            printf("%d ", cuadrado);
            suma += cuadrado;
        }
    }

    printf("\nLa suma de los cuadrados perfectos comprendido entre %d y %d es: %d\n", num1, num2, suma);

}

void ejercicio3(){

    int numero;

    printf("Introduce un numero: ");
    scanf("%d", &numero);

    int division = numero / 2;
    int resto = numero % 2;

    if (resto != 1){
        printf("El numero es divisible entre dos con cociente: %d", division);
    }
    else{
        printf("\nEl numero no es divisible entre dos con resto: %d", resto);
    }

}


void ejercicio4() {
    char palabra[50], palabra_invertida[50];

    printf("Introduce una palabra: ");
    scanf("%s", palabra);

    // Copiar la palabra original en otra variable
    strcpy(palabra_invertida, palabra);

    // Invertir la palabra
    strrev(palabra_invertida);

    // Comparar la palabra original con la invertida
    if (strcmp(palabra, palabra_invertida) == 0) {
        printf("La palabra '%s' es un palindromo.\n", palabra);
    } else {
        printf("La palabra '%s' no es un palindromo.\n", palabra);
    }
}


void menu_principal(){

    int select;
        printf("Laboratorio 1 - Grado de Ciberseguridad 2024 | Alejandro Rodriguez Moreno.\n");
        printf("\n(1) Ejercicio 1. \n(2) Ejercicio 2. \n(3) Ejercicio 3. \n(4) Ejercicio 4. \n(5) Salir. \n");
        printf("Seleccione un ejercicio: ");
        scanf("%i",&select);

        switch(select){
	    	case 1: ejercicio1();break;	
	    	case 2: ejercicio2();break;
	    	case 3: ejercicio3();break;
	    	case 4: ejercicio4();break;	
	    	default: printf("La opcion elegida es INCORRECTA.\n\n");
	    }
}

int main(){

    menu_principal();
    return 0;

}
