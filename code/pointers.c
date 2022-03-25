#include <stdio.h>
#include <stdlib.h>

int sumar(int *ap){
    int c;
    c = *ap + 1;
    return c;
}

int main(){
    int *ap;
    ap = malloc(100*sizeof(int));
    int x = 5;
    sumar(&x); //dirección de una VARIABLE, no de un apuntador

    sumar(ap);

    if (ap==NULL){ //en caso de error ap regresa null
        perror("error maloc: ");
        exit(-1); //saca el programa de ejecución
    }

    for(int i=0; i< 100; i++){
        // ap[i] = i; //Forma tradicional
        *(ap+i) = i; //Con apuntadores
    }

    return 0;
}