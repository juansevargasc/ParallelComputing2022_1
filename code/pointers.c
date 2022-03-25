#include <stdio.h>
#include <stdlib.h>

int sumar(int *ap)
{
    int c;
    c = *ap + 1;
    return c;
}

int main()
{

    int *ap; // * significa reservar una variable para guardar una dirección en memoria. No es la reserva de memoria.
    ap = malloc(100 * sizeof(int)); // alocar la memoria.

    if (ap == NULL) // Manejo de error
    { //en caso de error ap regresa null
        perror("error maloc: ");
        exit(-1); //saca el programa de ejecución
    }
    
    int x = 5;
    //sumar(&x); // &: deberìa usar &, dado que x es una variable, pero sumar me pide un apuntador x*, entonces & me da el apuntador a memoria, &x

    //sumar(ap);

    for(int i = 0; i < 100; i++)
    {
        // ap[i] = i; //Forma tradicional
        *(ap + i) = sumar(&x) + i; //Con apuntadores
    }

    for (int i = 0; i < 100; i++)
    {
        //printf("%i, ", ap[i]); 
        printf("%i, ", *(ap + i) ); //*(ap + i) = i + 3; -> ap (es una dirección) sumo i (un entero) entonces avanza 4 bytes. Para eso se hace int* ap, para aclarar
    }
    
    free(ap);
    return 0;
}